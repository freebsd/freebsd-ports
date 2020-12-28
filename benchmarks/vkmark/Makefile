# $FreeBSD$

PORTNAME=	vkmark
DISTVERSION=	2017.08-21
DISTVERSIONSUFFIX=	-ge8c0720
CATEGORIES=	benchmarks

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Vulkan benchmark

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING-LGPL2.1

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers \
		glm>0:math/glm
LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader \
		libassimp.so:multimedia/assimp

USES=		compiler:c++14-lang localbase meson pkgconfig
USE_GITHUB=	yes

OPTIONS_DEFINE=	DRM WAYLAND X11
OPTIONS_DEFAULT=DRM WAYLAND X11
OPTIONS_EXCLUDE=DRM # not supported yet
OPTIONS_SUB=	yes

DRM_DESC=		KMS console support
DRM_LIB_DEPENDS=	libdrm.so:graphics/libdrm
DRM_USES=		gl
DRM_USE=		GL=gbm
DRM_MESON_TRUE=		kms

WAYLAND_BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
			wayland-protocols>=1.12:graphics/wayland-protocols
WAYLAND_LIB_DEPENDS=	libwayland-client.so:graphics/wayland
WAYLAND_MESON_TRUE=	wayland

X11_LIB_DEPENDS=	libxcb-icccm.so:x11/xcb-util-wm
X11_USES=		xorg
X11_USE=		XORG=xcb
X11_MESON_TRUE=		xcb

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
