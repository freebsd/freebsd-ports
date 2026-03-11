PORTNAME=	egl-wayland2
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Dma-buf-based Wayland external platform library
WWW=		https://github.com/NVIDIA/egl-wayland2

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/libdrm/drm_fourcc.h:graphics/libdrm \
		eglexternalplatform>=1.2:graphics/eglexternalplatform \
		wayland-protocols>=1.8:graphics/wayland-protocols
LIB_DEPENDS=	libdrm.so:graphics/libdrm \
		libwayland-server.so:graphics/wayland

USES=		gl meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	NVIDIA
USE_GL=		egl gbm
USE_LDCONFIG=	yes

PLIST_SUB=	DISTVERSION=${DISTVERSION}

post-patch:
	@${REINPLACE_CMD} -e "/install/s/datadir')/prefix'), 'libdata'/" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
