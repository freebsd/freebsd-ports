# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	openjpeg
PORTVERSION=	2.1.0
CATEGORIES=	graphics
MASTER_SITES=	SF/openjpeg.mirror/${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open-source JPEG 2000 codec

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	liblcms2.so:${PORTSDIR}/graphics/lcms2 \
		libpng15.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff

USE_LDCONFIG=	yes
USES=		cmake cpe pkgconfig

PLIST_SUB=	VER=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e 's|$${OPENJPEG_INSTALL_LIB_DIR}/pkgconfig|libdata/pkgconfig|' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
