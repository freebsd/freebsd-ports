PORTNAME=	imlib2-jxl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1
PORTREVISION=	3
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	JPEG XL loader for imlib2
WWW=		https://github.com/alistair7/imlib2-jxl

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE-BSD-ab

LIB_DEPENDS=	libImlib2.so:graphics/imlib2 \
		libjxl.so:graphics/libjxl

USES=		gmake pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	alistair7
MAKE_ENV=	RELEASE_CFLAGS="${CFLAGS}"
ALL_TARGET=	# empty
PLIST_FILES=	lib/imlib2/loaders/jxl.so

OPTIONS_DEFINE=	LCMS2
OPTIONS_DEFAULT=LCMS2

LCMS2_LIB_DEPENDS=	liblcms2.so:graphics/lcms2

post-patch-LCMS2-off:
	@${REINPLACE_CMD} -e '/-DIMLIB2JXL_USE_LCMS/d' \
		-e 's/`pkg-config[^`]*lcms[^`]*`//' \
		${WRKSRC}/Makefile

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.so:H}
	${INSTALL_LIB} ${WRKSRC}/${PLIST_FILES:M*.so:T} \
		${STAGEDIR}${PREFIX}/${PLIST_FILES:M*.so:H}

.include <bsd.port.mk>
