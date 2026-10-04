PORTNAME=	UZDoom
DISTVERSION=	5.0.3
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Feature centric source port for Doom-engine games
WWW=		https://github.com/UZDoom/UZDoom

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		armv6 armv7 i386 powerpc powerpcspe
NOT_FOR_ARCHS_REASON=	upstream only supports 64-bit platforms

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libopenal.so:audio/openal-soft \
		libvpx.so:multimedia/libvpx

USES=		cmake desktop-file-utils gnome localbase pkgconfig python:build \
		sdl shared-mime-info
USE_GITHUB=	yes
USE_GNOME=	glib20
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

.include <bsd.port.options.mk>

# clang 19 PCH: std::__va_list mismatches __builtin_va_list on aarch64
.if ${ARCH} == aarch64
CMAKE_OFF+=	USE_PCH
.endif

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/include ${STAGEDIR}${PREFIX}/lib

post-install-DOCS-off:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
