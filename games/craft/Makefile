PORTNAME=	craft
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	fbsd
CATEGORIES=	games

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Simple Minecraft clone written in C using modern OpenGL
WWW=		https://www.michaelfogleman.com/craft/

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libglfw.so:graphics/glfw

USES=		cmake:insource compiler:c11 gl sqlite:3 xorg

USE_GITHUB=	yes
GH_ACCOUNT=	daniloegea
GH_PROJECT=	Craft

USE_XORG=	x11 xi xrandr xxf86vm
USE_GL=		gl glew glu

.include <bsd.port.mk>
