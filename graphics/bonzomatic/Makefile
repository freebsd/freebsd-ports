PORTNAME=	bonzomatic
DISTVERSION=	2021-03-07
PORTREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Live shader coding tool and Shader Showdown workhorse

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfontconfig.so:x11-fonts/fontconfig \
		libglfw.so:graphics/glfw
BUILD_DEPENDS=	${LOCALBASE}/include/stb/stb_image.h:devel/stb

USES=		cmake compiler:c++11-lang gl localbase:ldflags pkgconfig xorg
USE_GL=		gl glu glew
USE_XORG=	x11 xext xrandr xinerama xcursor xi
CMAKE_ON=	BONZOMATIC_USE_SYSTEM_GLFW \
		BONZOMATIC_USE_SYSTEM_GLEW \
		BONZOMATIC_USE_SYSTEM_STB
USE_GITHUB=	yes
GH_ACCOUNT=	Gargaj
GH_PROJECT=	Bonzomatic

.include <bsd.port.mk>
