PORTNAME=	glfw
DISTVERSION=	3.4
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/glfw/glfw/releases/download/${DISTVERSION}/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Portable framework for OpenGL development
WWW=		https://www.glfw.org/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake:insource localbase zip
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	GLFW_BUILD_DOCS

CONFLICTS_INSTALL=	glfw2

PLIST_SUB=	MAJVER=${DISTVERSION:R} \
		VERSION=${DISTVERSION}
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	X11
OPTIONS_MULTI=		PLATFORM
OPTIONS_MULTI_PLATFORM=	WAYLAND X11
PLATFORM_DESC=		Window creation platform

EXAMPLES_CMAKE_BOOL=	GLFW_BUILD_EXAMPLES GLFW_BUILD_TESTS

WAYLAND_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
			libxkbcommon>0:x11/libxkbcommon \
			wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim
WAYLAND_USES=		kde:5 pkgconfig
WAYLAND_USE=		KDE=ecm
WAYLAND_CMAKE_BOOL=	GLFW_BUILD_WAYLAND

X11_USES=	xorg
X11_USE=	XORG=x11,xcursor,xi,xinerama,xrandr,xxf86vm
X11_CMAKE_BOOL=	GLFW_BUILD_X11

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/docs/html/search
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/html/search/* \
		${STAGEDIR}${DOCSDIR}/docs/html/search
	cd ${WRKSRC}/docs/html && ${INSTALL_DATA} *.html *.png *.css *.js \
		 ${STAGEDIR}${DOCSDIR}/docs/html

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/tests
	cd ${WRKSRC}/examples && ${INSTALL_PROGRAM} \
		boing gears heightmap offscreen particles sharing splitview \
		triangle-opengl triangle-opengles wave windows \
		${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/tests && ${INSTALL_PROGRAM} \
		allocator clipboard cursor empty events gamma glfwinfo icon \
		iconify inputlag joysticks monitors msaa reopen tearing threads \
		timeout title triangle-vulkan window \
		${STAGEDIR}${EXAMPLESDIR}/tests

.include <bsd.port.mk>
