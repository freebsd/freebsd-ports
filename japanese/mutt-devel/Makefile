# Created by: IWASHITA Yoji <shuna@pop16.odn.ne.jp>
# $FreeBSD$

# WITH_MUTT_CYRUS_SASL2:	if defined, 'Cyrus sasl' support.
#

PORTNAME=	mutt
PORTVERSION=	${VERSION}.j${JP_VERSION}
PORTREVISION=	8
CATEGORIES=	japanese mail
MASTER_SITES=	ftp://ftp.mutt.org/mutt/devel/:body \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/devel/:body \
		ftp://ftp.demon.co.uk/pub/mirrors/mutt/devel/:body \
		http://www.emaillab.org/mutt/${MANUALVERSION}/:ja_man1 \
		http://mutt-j.sourceforge.jp/:ja_man2 \
		http://www.emaillab.org/mutt/1.5/doc/:ja_doc
PKGNAMESUFFIX=	-devel
DISTNAME=	mutt-${VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:body \
		manual_ja-${MANUALVERSION}i-1${EXTRACT_SUFX}:ja_man1 \
		manual.ja-${MANJADATE}${EXTRACT_SUFX}:ja_man2 \
		README.JA-PATCH.ja.html:ja_doc \
		README.JA-PATCH.ja:ja_doc \
		INSTALL.JA-PATCH.ja.html:ja_doc \
		INSTALL.JA-PATCH.ja:ja_doc \
		manual-ja-patch.ja.html:ja_doc \
		manual-ja-patch.ja.txt:ja_doc \
		usage-japanese.ja.html:ja_doc \
		usage-japanese.ja.txt:ja_doc
DIST_SUBDIR=	mutt
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		manual_ja-${MANUALVERSION}i-1${EXTRACT_SUFX} \
		manual.ja-${MANJADATE}${EXTRACT_SUFX}

PATCH_SITES=	http://www.emaillab.org/mutt/${VERSION}/:ja_patch
PATCHFILES=	patch-${VERSION}.tt.wcwidth.${JP_VERSION}.gz:ja_patch \
		patch-${VERSION}.tt.create_rfc2047_params.${JP_VERSION}.gz:ja_patch \
		patch-${VERSION}.tt+yy.delete_prefix.${JP_VERSION}.gz:ja_patch \
		patch-${VERSION}.tt.sanitize_ja_char.${JP_VERSION}.gz:ja_patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	st@be.to
COMMENT=	Text-based mail client (Japanised development version)

LICENSE=	GPLv2

RUN_DEPENDS=	urlview:textproc/urlview \
		${LOCALBASE}/etc/mime.types:misc/mime-support

BROKEN_aarch64=		fails to compile: conflicting types for __wcwidth
BROKEN_armv6=		fails to compile: conflicting types for __wcwidth
BROKEN_armv7=		fails to compile: conflicting types for __wcwidth

CONFLICTS=	ja-mutt-[0-9]* mutt-[0-9]* mutt-devel-[0-9]* mutt-devel-lite-[0-9]* mutt-lite-[0-9]* zh-mutt-devel-[0-9]*

VERSION=	1.5.21
JP_VERSION=	1
MANUALVERSION=	1.4
MANJADATE=	20050813

FETCH_BEFORE_ARGS=	-A	# ha4.seikyou.ne.jp is running broken httpd

USES=		gmake iconv ncurses shebangfix autoreconf fakeroot ssl
SHEBANG_FILES=	smime_keys.pl contrib/smime_keys_test.pl
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/mutt-${VERSION}
LDFLAGS+=	-L${LOCALBASE}/lib -ltinfow
CONFIGURE_ENV=	CC="${CC} -D_DONT_USE_CTYPE_INLINE_ -D_XLOCALE_CTYPE_H ${DB_CFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/ncurses"
CONFIGURE_ARGS=	--with-ncurses --enable-locales-fix \
		${ICONV_CONFIGURE_ARG} \
		--without-wc-funcs \
		--enable-flock --disable-fcntl \
		--with-ssl \
		--sysconfdir=${PREFIX}/etc \
		--with-docdir=${DOCSDIR} \
		--enable-pop --enable-imap \
		--enable-smtp
.if defined(MUTT_CONFIGURE_ARGS)
CONFIGURE_ARGS+=	${MUTT_CONFIGURE_ARGS}
.endif

OPTIONS_DEFINE=	CYRUS_SASL2 IMAP_HEADER_CACHE IDN MAILDIR_HEADER_CACHE NLS DOCS
CYRUS_SASL2_DESC=	SASL2 authentication
IMAP_HEADER_CACHE_DESC=	imap header cache
MAILDIR_HEADER_CACHE_DESC=	maildir header cache

DOCS_EXTRA_PATCHES_OFF=	${PATCHDIR}/extra-patch-nodoc-contrib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
.endif
.if ${PORT_OPTIONS:MCYRUS_SASL2}
LIB_DEPENDS+=	libsasl2.so:security/cyrus-sasl2
.endif
.if ${PORT_OPTIONS:MMAILDIR_HEADER_CACHE}
PORT_OPTIONS+=	MAILDIR_HEADER_CACHE
.endif
.if ${PORT_OPTIONS:MIMAP_HEADER_CACHE}
USES+=		bdb
CONFIGURE_SED=	-e 's/BDB_VERSIONS="/&${BDB_LIB_NAME} db${BDB_VER} /'
.endif
.if ${PORT_OPTIONS:MIDN}
LIB_DEPENDS+=	libidn.so:dns/libidn
.endif

.if ${PORT_OPTIONS:MCYRUS_SASL2}
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
.endif
.if ! ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif
.if ${PORT_OPTIONS:MIDN}
CONFIGURE_ARGS+=	--with-idn
.else
CONFIGURE_ARGS+=	--without-idn
.endif
.if ${PORT_OPTIONS:MIMAP_HEADER_CACHE}
CONFIGURE_ARGS+=	--enable-hcache --without-gdbm --with-bdb
.else
CONFIGURE_ARGS+=	--disable-hcache
.endif
.if ${PORT_OPTIONS:MMAILDIR_HEADER_CACHE}
CONFIGURE_ARGS+=	--without-qdbm
.endif

post-patch:
.if defined(CONFIGURE_SED)
	@${REINPLACE_CMD} -E ${CONFIGURE_SED} \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}.ac
.endif

post-configure:
	@${REINPLACE_CMD} -E "\
		s|^(s%\@ACLOCAL\@%).+(%g)|\1${ACLOCAL}\2|; \
		s|^(s%\@AUTOCONF\@%).+(%g)|\1${AUTOCONF}\2|; \
		s|^(s%\@AUTOMAKE\@%).+(%g)|\1${AUTOMAKE}\2|; \
		s|^(s%\@AUTOHEADER\@%).+(%g)|\1${AUTOHEADER}\2|" \
		${BUILD_WRKSRC}/config.status

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${INSTALL_DATA} ${_DISTDIR}/INSTALL.JA-PATCH.ja ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/README.JA-PATCH.ja ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/manual-ja-patch.ja.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/usage-japanese.ja.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/INSTALL.JA-PATCH.ja.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/README.JA-PATCH.ja.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/manual-ja-patch.ja.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/usage-japanese.ja.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.tex ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.sgml ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual.ja.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual.ja.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual.ja.sgml ${STAGEDIR}${DOCSDIR}
.endif
	# These are outside the path and do not belong there:
	${RM} ${STAGEDIR}${PREFIX}/etc/Muttrc ${STAGEDIR}${PREFIX}/etc/mime.types

.include <bsd.port.mk>
