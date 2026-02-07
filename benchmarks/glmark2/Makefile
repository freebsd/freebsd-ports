PORTNAME=	glmark2
PORTVERSION=	2023.01
PORTREVISION=	2
CATEGORIES=	benchmarks

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Benchmark for OpenGL (ES) 2.0
WWW=		https://launchpad.net/glmark2

LICENSE=	GPLv3

LIB_DEPENDS=	libpng.so:graphics/png

USES=		compiler:c++14-lang jpeg meson pkgconfig
USE_GITHUB=	yes
CONFIGURE_ARGS=	-Dflavors=${PLATFORMS:ts,}

PORTDOCS=	NEWS

OPTIONS_DEFINE=	DOCS
OPTIONS_MULTI=	PLATFORM
OPTIONS_MULTI_PLATFORM=	DRM GBM WAYLAND X11
OPTIONS_DEFAULT=	DRM GBM WAYLAND X11
OPTIONS_SUB=	yes

PLATFORM_DESC=		Window systems

DRM_DESC=		KMS console support
DRM_LIB_DEPENDS=	libudev.so:devel/libudev-devd \
			libdrm.so:graphics/libdrm
DRM_USES=		gl
DRM_USE=		GL=gbm
DRM_VARS=		PLATFORMS+="drm-gl drm-glesv2"

GBM_DESC=		GBM offscreen rendering
GBM_USES=		gl
GBM_USE=		GL=gbm
GBM_VARS=		PLATFORMS+="gbm-gl gbm-glesv2"

WAYLAND_CATEGORIES=	wayland
WAYLAND_BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
			wayland-protocols>=1.12:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland
WAYLAND_VARS=		PLATFORMS+="wayland-gl wayland-glesv2"

X11_USES=		localbase xorg
X11_USE=		XORG=x11
X11_VARS=		PLATFORMS+="x11-gl x11-glesv2 x11-gl-egl"

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
