PORTNAME=	glfw
DISTVERSION=	3.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/glfw/glfw/releases/download/${DISTVERSION}/

MAINTAINER=	vvd@FreeBSD.org
COMMENT=	Portable framework for OpenGL development
WWW=		https://www.glfw.org/

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cmake:insource localbase:ldflags zip
USE_LDCONFIG=	yes

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	GLFW_BUILD_DOCS

CONFLICTS_INSTALL=	glfw2

PLIST_SUB=	MAJVER=${DISTVERSION:R} \
		VERSION=${DISTVERSION}
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES PREEDIT
OPTIONS_DEFAULT=	PREEDIT X11
OPTIONS_MULTI=		PLATFORM
OPTIONS_MULTI_PLATFORM=	WAYLAND X11
PLATFORM_DESC=		Window creation platform
PREEDIT_DESC=		Add patches for run Minecraft (https://github.com/glfw/glfw/pull/2130)

EXAMPLES_CMAKE_BOOL=	GLFW_BUILD_EXAMPLES GLFW_BUILD_TESTS

# Patches to support running applications such as Minecraft with games/lwjgl3
PREEDIT_PATCH_SITES=	https://github.com/glfw/glfw/commit/
PREEDIT_PATCHFILES=	bf945f1213728a98f7647380616f9cff9f6b3611.patch:-p1 \
			0d7379403edd2f3a3476ce76fba4ac8c6d8410b7.patch:-p1 \
			55cdeb59029d51be4b622d3b66a9735e4cf07a3b.patch:-p1 \
			5f2118a2fa052f4361c6129378d5e8d0c923b118.patch:-p1 \
			4da43dd83e1d16055107f91d9c34df3b114ab6f4.patch:-p1 \
			11fd72171161e77f8c85a4ce51370ae8b813532d.patch:-p1 \
			d8d0e52de8fb7c4f9879c2ff3599e0ba13ce8bc6.patch:-p1 \
			d793a873a0fa740fa832917f99de35d5e09e7987.patch:-p1 \
			d1f1b2a88de2a6d1701558c732164f5e070030a5.patch:-p1 \
			cef608cf56c2fb88ff3eded4240f7a609610abad.patch:-p1 \
			a66cc4d8805fc2857edf75812ba702e39e2873d7.patch:-p1 \
			c4ba4cd58ea4e3eb6686a34596998de65330f71c.patch:-p1 \
			0729aacc8cc6ff888f593108fdf70ce3fc2800b2.patch:-p1 \
			6be88608b1ddbc42d5c59448dc15852f9de7ec26.patch:-p1

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

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES} && ${PORT_OPTIONS:MPREEDIT}
LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig
TESTS_FILES=	input_text
.endif

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
		iconify inputlag joysticks monitors msaa reopen \
		tearing threads timeout title triangle-vulkan window \
		${TESTS_FILES} \
		${STAGEDIR}${EXAMPLESDIR}/tests

.include <bsd.port.mk>
