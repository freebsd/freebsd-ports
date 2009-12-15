# New ports collection makefile for:	libslang2
# Date created:		2005-05-16
# Whom:			Renato Botelho <freebsd@galle.com.br>
#
# $FreeBSD$
#

PORTNAME=	libslang2
PORTVERSION=	2.2.2
CATEGORIES=	devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v${PORTVERSION:R}/ \
		ftp://ftp.fu-berlin.de/pub/unix/misc/slang/v${PORTVERSION:R}/ \
		ftp://ftp.ntua.gr/pub/lang/slang/slang/v${PORTVERSION:R}/
DISTNAME=	slang-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Routines for rapid alpha-numeric terminal applications development

CONFLICTS=	libslang-1.*.j[0-9]

USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
PLIST_SUB+=	SHLIB_VERSION=${PORTVERSION}

CONFIGURE_ARGS+=--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

ALL_TARGET=	all static
INSTALL_TARGET=	install install-static

MAN1=		slsh.1
DOCSDIR=	${PREFIX}/share/doc/slang
DATADIR=	${PREFIX}/share/slsh

OPTIONS=	PCRE	"Include pcre support" on \
		PNG	"Include png support"  on \
		ICONV	"Include iconv support" on \
		ONIG	"Include Oniguruma support" off

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PCRE)
LIB_DEPENDS+=	pcre.0:${PORTSDIR}/devel/pcre
PLIST_SUB+=	PCRE=""
.else
CONFIGURE_ARGS+=	--without-pcre
PLIST_SUB+=	PCRE="@comment "
.endif

.if !defined(WITHOUT_PNG)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
PLIST_SUB+=	PNG=""
.else
CONFIGURE_ARGS+=	--without-png
PLIST_SUB+=	PNG="@comment "
.endif

.if !defined(WITHOUT_ICONV)
USE_ICONV=	yes
PLIST_SUB+=	ICONV=""
.else
CONFIGURE_ARGS+=	--without-iconv
PLIST_SUB+=	ICONV="@comment "
.endif

.if defined(WITH_ONIG)
LIB_DEPENDS+=	onig.1:${PORTSDIR}/devel/oniguruma4
PLIST_SUB+=	ONIG=""
.else
CONFIGURE_ARGS+=	--without-onig
PLIST_SUB+=	ONIG="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -E 's,doc/slsh,doc/slang/v\@slang_major_version\@,' \
		${WRKSRC}/slsh/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's, install[_-]docs,,g; /MKINSDIR.*DEST_SLSH_DOC_DIR/d' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/slsh/Makefile.in
.endif

.include <bsd.port.post.mk>
