PORTNAME=	egl-x11
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.4
CATEGORIES=	graphics

MAINTAINER=	x11@FreeBSD.org
COMMENT=	EGL X11/XCB platform library for NVIDIA driver
WWW=		https://github.com/NVIDIA/egl-x11

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	eglexternalplatform>=1.2:graphics/eglexternalplatform \
		${LOCALBASE}/include/libdrm/drm_fourcc.h:graphics/libdrm

USES=		gl meson pkgconfig xorg
USE_GITHUB=	yes
USE_GL=		egl gbm
USE_XORG=	x11 xcb
USE_LDCONFIG=	yes
GH_ACCOUNT=	NVIDIA

PLIST_SUB+=	SHLIB_VERSION=${DISTVERSION}

.include <bsd.port.mk>
