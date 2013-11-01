# $FreeBSD$

PORTNAME=	libslang2
PORTVERSION=	2.2.4
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v${PORTVERSION:R}/ \
		ftp://ftp.fu-berlin.de/pub/unix/misc/slang/v${PORTVERSION:R}/ \
		ftp://ftp.ntua.gr/pub/lang/slang/slang/v${PORTVERSION:R}/
DISTNAME=	slang-${PORTVERSION}

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Routines for rapid alpha-numeric terminal applications development

LICENSE=	GPLv2

CONFLICTS=	libslang-1.*.j[0-9]

USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
PLIST_SUB+=	SHLIB_VERSION=${PORTVERSION}

CONFIGURE_ARGS+=--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

ALL_TARGET=	all static
INSTALL_TARGET=	install install-static

DOCSDIR=	${PREFIX}/share/doc/slang
DATADIR=	${PREFIX}/share/slsh

OPTIONS_DEFINE=	PCRE PNG ICONV ONIG DOCS
OPTIONS_DEFAULT=PCRE PNG ICONV DOCS
OPTIONS_SUB=	yes

ONIG_DESC=	Oniguruma support

PORTDOCS=	*

PCRE_CONFIGURE_WITH=	pcre
PCRE_LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre
PNG_CONFIGURE_WITH=	png
PNG_LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png
ICONV_CONFIGURE_WITH=	iconv
ICONV_USES=		iconv
ONIG_CONFIGURE_WITH=	onig
ONI_LIB_DEPENDS=	libonig.so:${PORTSDIR}/devel/oniguruma4

post-patch:
	@${REINPLACE_CMD} -E 's,doc/slsh,doc/slang/v\@slang_major_version\@,' \
		${WRKSRC}/slsh/Makefile.in
	@${REINPLACE_CMD} -e 's, install[_-]docs,,g; /MKINSDIR.*DEST_SLSH_DOC_DIR/d' \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/slsh/Makefile.in

.include <bsd.port.mk>
