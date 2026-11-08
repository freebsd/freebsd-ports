PORTNAME=	glfw
DISTVERSION=	3.5.1
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

PLIST_SUB=	MAJVER=${DISTVERSION:R:R} \
		VERSION=${DISTVERSION:R}
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES PREEDIT
OPTIONS_DEFAULT=	PREEDIT WAYLAND X11
OPTIONS_MULTI=		PLATFORM
OPTIONS_MULTI_PLATFORM=	WAYLAND X11
PLATFORM_DESC=		Window creation platform
PREEDIT_DESC=		Add patches for run Minecraft (https://github.com/glfw/glfw/pull/2130)

EXAMPLES_CMAKE_BOOL=	GLFW_BUILD_EXAMPLES GLFW_BUILD_TESTS

# Patches to support running applications such as Minecraft with games/lwjgl3
PREEDIT_PATCH_SITES=	https://github.com/glfw/glfw/commit/
PREEDIT_PATCHFILES=	a8e21e28da2c336052f4c99e82c621d985c35d02.patch:-p1 \
			1f532f8f3fb5c2c86304ac4b63528ad79bb9e3f4.patch:-p1 \
			542bee1306cc7662df2a964862a77d0a7ca90eb5.patch:-p1 \
			5e8231a4bffd24c3f9da87292bef24d70c3b4d00.patch:-p1 \
			b6deacdc67016750692e28318d9863df3c742566.patch:-p1 \
			065cb103b4966cdc8b20fd1106859df942c57498.patch:-p1 \
			ff5010b755e7aabfdf9484b52c1be62aa328ebb5.patch:-p1 \
			9e6045b1fa63a605b7413b31d4f345730d545f35.patch:-p1 \
			f1070efb181e788187f3c8a5652c029f1ae86d8e.patch:-p1 \
			38943c2156d8dce810ca19f8c97be51e60295559.patch:-p1 \
			c2bccfda0a24f040b7120eec64197895d196b12f.patch:-p1 \
			f42598e2a126c51c245905a971fabda33103985b.patch:-p1 \
			ad485c296e38e0f5cdb4f0b05123669fc42c76ff.patch:-p1 \
			a3e006b4535b1059abeab34c7be22a17f0389355.patch:-p1 \
			c923d1be92aa50b9480a9651ba06ea4d4f2f8556.patch:-p1 \
			e9aa24f1d494f95426fa217b853c0b96b2c013f1.patch:-p1 \
			5863b8f546796da4c4f27dd9c7c7e2d06c0633f4.patch:-p1 \
			b30a503e4efbd5e37fcfbb8ca578f473dafbc631.patch:-p1 \
			934a37bf1f9b68f39573bbf5160eef73c7af442a.patch:-p1 \
			1e8c9544591b684e60c4d4d8f7963124b7d637c4.patch:-p1 \
			a1ca6f0bc098d1b5123eb3b0055757b49c261723.patch:-p1 \
			744c3de3658a9929bcb5378d3f373a37f046fb11.patch:-p1 \
			9af719e6073a317f2dfa17f6cf0c373619b1ec8c.patch:-p1

WAYLAND_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
			libxkbcommon>0:x11/libxkbcommon \
			wayland-protocols>=0:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim
WAYLAND_RUN_DEPENDS=	libxkbcommon>0:x11/libxkbcommon
WAYLAND_USES=		kde pkgconfig
WAYLAND_USE=		KDE=ecm:build
WAYLAND_CMAKE_BOOL=	GLFW_BUILD_WAYLAND

X11_BUILD_DEPENDS=	libxkbcommon>0:x11/libxkbcommon
X11_USES=		xorg
X11_USE=		XORG=x11,xcursor,xext,xi,xinerama,xrandr,xxf86vm
X11_CMAKE_BOOL=		GLFW_BUILD_X11

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
