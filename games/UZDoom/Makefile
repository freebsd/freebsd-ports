PORTNAME=	UZDoom
DISTVERSION=	5.0.3
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Feature centric source port for Doom-engine games
WWW=		https://github.com/UZDoom/UZDoom

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libopenal.so:audio/openal-soft \
		libvpx.so:multimedia/libvpx

USES=		cmake desktop-file-utils localbase pkgconfig python:build \
		sdl shared-mime-info
USE_GITHUB=	yes
USE_SDL=	sdl2

DATADIR=	${PREFIX}/share/games/uzdoom
DOCSDIR=	${PREFIX}/share/doc/uzdoom

CMAKE_OFF=	BUILD_SHARED_LIBS DYN_OPENAL SEND_ANON_STATS
CXXFLAGS+=	-DSHARE_DIR=\\\"${PREFIX}/share\\\"

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		WSI
OPTIONS_SINGLE_WSI=	WAYLAND X11
OPTIONS_DEFAULT=	WAYLAND
WSI_DESC=		Vulkan window system integration

WAYLAND_CMAKE_BOOL=	VULKAN_USE_WAYLAND
X11_CMAKE_BOOL=		VULKAN_USE_XLIB
X11_USES=		xorg
X11_USE=		XORG=x11

.include "${.CURDIR}/../doom-data/Makefile.include"

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/include ${STAGEDIR}${PREFIX}/lib

post-install-DOCS-off:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
