# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	simpleviewer
PORTVERSION=	2.92
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	https://bitbucket.org/andreyu/simple-viewer-gl/get/
DISTNAME=	v${PORTVERSION}	# version tag, thus no embedded ${PORTNAME}
DIST_SUBDIR=	${PORTNAME}	# and hence the need for ${DIST_SUBDIR}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and simple OpenGL image viewer with transparency support

LICENSE=	GPLv2

LIB_DEPENDS=	libIlmImf.so:graphics/openexr \
		libImlib2.so:graphics/imlib2 \
		libexif.so:graphics/libexif \
		libfreetype.so:print/freetype2 \
		libgif.so:graphics/giflib \
		libglfw.so:graphics/glfw \
		liblcms2.so:graphics/lcms2 \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff \
		libwebp.so:graphics/webp

USES=		cmake:insource compiler:c++11-lang gl jpeg pkgconfig tar:bzip2 \
		xorg
USE_GL=		glu
USE_XORG=	ice sm x11 xcursor xext xinerama xrandr xxf86vm

WRKSRC=		${WRKDIR}/andreyu-simple-viewer-gl-b3bd8710e176

PLIST_FILES=	bin/sviewgl
PORTEXAMPLES=	config.example
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sviewgl ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config.example ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
