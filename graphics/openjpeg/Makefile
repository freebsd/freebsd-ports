# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	openjpeg
PORTVERSION=	2.1.2
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open-source JPEG 2000 codec

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake>=3:devel/cmake
LIB_DEPENDS=	liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USE_LDCONFIG=	yes
USES=		cmake cpe pkgconfig

PLIST_SUB=	VER=${PORTVERSION:R}

GH_ACCOUNT=	uclouvain
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${OPENJPEG_INSTALL_LIB_DIR}/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
