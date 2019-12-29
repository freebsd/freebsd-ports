# $FreeBSD$

PORTNAME=	magnum-extras
DISTVERSIONPREFIX=	v
DISTVERSION=	2019.10
PORTREVISION=	0
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extras for the Magnum C++11/C++14 graphics engine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libassimp.so:multimedia/assimp \
		libCorradeUtility.so:devel/corrade \
		libfaad.so:audio/faad \
		libfreetype.so:print/freetype2 \
		libIL.so:graphics/devil \
		libMagnum.so:graphics/magnum \
		libpng.so:graphics/png

USES=		cmake compiler:c++14-lang desktop-file-utils gl sdl xorg
USE_GITHUB=	yes
GH_ACCOUNT=	mosra
GH_TUPLE=	mosra:toolchains:fc22ff5:t/toolchains
USE_GL=		egl glesv2
USE_SDL=	sdl2
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DLIB_SUFFIX:STRING=""

CMAKE_ON=	WITH_PLAYER WITH_UI WITH_UI_GALLERY

.include <bsd.port.mk>
