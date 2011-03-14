# New ports collection makefile for:	ja-mutt
# Date created:		4 Sep 2000
# Whom:			IWASHITA Yoji <shuna@pop16.odn.ne.jp>
#
# $FreeBSD$
#
# WITH_MUTT_CYRUS_SASL2:	if defined, 'Cyrus sasl' support.
#

PORTNAME=	mutt
PORTVERSION=	${VERSION}.j${JP_VERSION}
PORTREVISION=	1
CATEGORIES=	japanese mail
MASTER_SITES=	ftp://ftp.mutt.org/mutt/devel/:body \
		ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/devel/:body \
		ftp://ftp.demon.co.uk/pub/mirrors/mutt/devel/:body \
		ftp://ftp.parodius.com/pub/mutt/devel/:body \
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

LIB_DEPENDS=	slang.2:${PORTSDIR}/japanese/libslang
RUN_DEPENDS=	urlview:${PORTSDIR}/textproc/urlview \
		${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

CONFLICTS=	mutt-[0-9]* ja-mutt-1.[0-4]*

VERSION=	1.5.21
JP_VERSION=	1
MANUALVERSION=	1.4
MANJADATE=	20050813

FETCH_BEFORE_ARGS=	-A	# ha4.seikyou.ne.jp is running broken httpd

NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_AUTOTOOLS=	automake autoconf
USE_OPENSSL=	yes
WRKSRC=		${WRKDIR}/mutt-${VERSION}
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CC="${CC} -D_DONT_USE_CTYPE_INLINE_ ${DB_CFLAGS} -I${LOCALBASE}/include -I${LOCALBASE}/include/slang" \
		LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-slang --enable-locales-fix \
		--with-libiconv-prefix=${LOCALBASE} \
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

OPTIONS=	MUTT_CYRUS_SASL2		"Enable SASL2 authentication"	off \
		MUTT_IMAP_HEADER_CACHE		"Enable imap header cache"	off \
		MUTT_IDN			"Enable idn support"		off \
		MUTT_MAILDIR_HEADER_CACHE	"Enable maildir header cache"	off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.endif
.if defined(WITH_MUTT_CYRUS_SASL2)
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
.endif
.if defined(WITH_MUTT_MAILDIR_HEADER_CACHE)
WITH_MUTT_IMAP_HEADER_CACHE=	yes
.endif
.if defined(WITH_MUTT_IMAP_HEADER_CACHE)
USE_BDB=	42+
.endif
.if exists(${LOCALBASE}/lib/libidn.so) && !defined(WITHOUT_MUTT_IDN)
WITH_MUTT_IDN=	yes
.endif
.if defined(WITH_MUTT_IDN)
LIB_DEPENDS+=	idn:${PORTSDIR}/dns/libidn
.endif

.if defined(WITH_MUTT_CYRUS_SASL2)
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
.endif
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif
.if defined(WITH_MUTT_IDN)
CONFIGURE_ARGS+=	--with-idn
.else
CONFIGURE_ARGS+=	--without-idn
.endif
.if defined(WITH_MUTT_IMAP_HEADER_CACHE)
CONFIGURE_ARGS+=	--enable-hcache --without-gdbm --with-bdb
.else
CONFIGURE_ARGS+=	--disable-hcache
.endif
.if defined(WITH_MUTT_MAILDIR_HEADER_CACHE)
CONFIGURE_ARGS+=	--without-qdbm
.endif

NOMANCOMPRESS=	yes
MAN1=		flea.1 mutt.1 muttbug.1 mutt_dotlock.1 smime_keys.1
MAN5=		muttrc.5 mbox.5 mmdf.5

pre-configure:
.if defined(NOPORTDOCS)
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-nodoc-contrib
.endif
	(cd ${WRKSRC}; ${ACLOCAL} -I m4; ${AUTOHEADER})

post-configure:
	@${REINPLACE_CMD} -E "\
		s|^(s%\@ACLOCAL\@%).+(%g)|\1${ACLOCAL}\2|; \
		s|^(s%\@AUTOCONF\@%).+(%g)|\1${AUTOCONF}\2|; \
		s|^(s%\@AUTOMAKE\@%).+(%g)|\1${AUTOMAKE}\2|; \
		s|^(s%\@AUTOHEADER\@%).+(%g)|\1${AUTOHEADER}\2|" \
		${BUILD_WRKSRC}/config.status

.if !defined(NOPORTDOCS)
post-install:
	${INSTALL_DATA} ${_DISTDIR}/INSTALL.JA-PATCH.ja ${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/README.JA-PATCH.ja ${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/manual-ja-patch.ja.txt ${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/usage-japanese.ja.txt ${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/INSTALL.JA-PATCH.ja.html ${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/README.JA-PATCH.ja.html ${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/manual-ja-patch.ja.html ${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/usage-japanese.ja.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.tex ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.sgml ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual.ja.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual.ja.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual.ja.sgml ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
