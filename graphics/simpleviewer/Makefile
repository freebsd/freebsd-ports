# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	simpleviewer
PORTVERSION=	2.88
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://bitbucket.org/andreyu/simple-viewer-gl/get/
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and simple OpenGL image viewer with transparency support

LICENSE=	GPLv2

LIB_DEPENDS=	libImlib2.so:graphics/imlib2 \
		libexif.so:graphics/libexif \
		libfreetype.so:print/freetype2 \
		libgif.so:graphics/giflib \
		libglfw.so:graphics/glfw \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp

USES=		cmake compiler:c++11-lang jpeg pkgconfig tar:bzip2
USE_GL=		glu
USE_XORG=	ice sm x11 xcursor xext xrandr xxf86vm

WRKSRC=		${WRKDIR}/andreyu-simple-viewer-gl-b9266979237d

PLIST_FILES=	bin/sviewgl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sviewgl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
