# New ports collection makefile for:	ja-mutt
# Date created:		4 Sep 2000
# Whom:			IWASHITA Yoji <shuna@pop16.odn.ne.jp>
#
# $FreeBSD$
#
# WITH_MUTT_CYRUS_SASL:	if defined, 'Cyrus sasl' support.
#

PORTNAME=	mutt-devel
PORTVERSION=	${VERSION}.j${JP_VERSION}
PORTREVISION=	10
CATEGORIES=	japanese mail
MASTER_SITES=	http://www.emaillab.org/mutt/${VERSION}/ \
		http://www.emaillab.org/mutt/1.5/doc/:ja_doc \
		http://133.16.174.22/mutt/ \
		http://mutt-j.sourceforge.jp/ \
		ftp://ftp.mutt.org/mutt/devel/
PKGNAMEPREFIX=	ja-
DISTNAME=	mutt-${VERSION}
DISTFILES=	${EXTRACT_ONLY} \
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
PATCHFILES=	patch-${VERSION}.mutt-j.ja.${JP_VERSION}.gz:ja_patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	st@be.to
COMMENT=	Text-based mail client (Japanised development version)

LIB_DEPENDS=	slang.2:${PORTSDIR}/japanese/libslang
RUN_DEPENDS=	urlview:${PORTSDIR}/textproc/urlview \
		${LOCALBASE}/etc/mime.types:${PORTSDIR}/misc/mime-support

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.endif
.if defined(WITH_MUTT_CYRUS_SASL)
LIB_DEPENDS+=	sasl2.2:${PORTSDIR}/security/cyrus-sasl2
.endif
.if defined(WITH_MUTT_IDN)
LIB_DEPENDS+=	idn.16:${PORTSDIR}/dns/libidn
.endif

.if defined(WITH_MUTT_HEADER_CACHE)
LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm
CONFIGURE_ARGS+=	--enable-hcache
.endif

CONFLICTS=	mutt-* ja-mutt-1.[024]*

VERSION=	1.5.14
JP_VERSION=	1
MANUALVERSION=	1.4
MANJADATE=	20050813

FETCH_BEFORE_ARGS=	-A	# ha4.seikyou.ne.jp is running broken httpd

NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_AUTOTOOLS=	automake:19 autoconf:262
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
		--sysconfdir=${PREFIX}/etc --mandir=${PREFIX}/man \
		--with-docdir=${DOCSDIR} \
		--enable-pop --enable-imap \
		--enable-default-japanese
.if defined(MUTT_CONFIGURE_ARGS)
CONFIGURE_ARGS+=	${MUTT_CONFIGURE_ARGS}
.endif
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif
.if defined(WITH_MUTT_CYRUS_SASL)
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
.endif
.if defined(WITH_MUTT_HEADER_CACHE)
CONFIGURE_ARGS+=	--enable-hcache
.endif
.if defined(WITH_MUTT_IDN)
CONFIGURE_ARGS+=	--with-idn=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-idn
.endif

NOMANCOMPRESS=	yes
MAN1=		flea.1 mutt.1 muttbug.1 mutt_dotlock.1
MAN5=		muttrc.5 mbox.5 mmdf.5

pre-configure:
.if defined(NOPORTDOCS)
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extrapatch-nodoc-aa
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extrapatch-nodoc-ab
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

.include <bsd.port.mk>
