# $FreeBSD$

PORTNAME=	egl-wayland
DISTVERSION=	1.1.5
CATEGORIES=	graphics

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	EGLStream-based Wayland external platform

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	eglexternalplatform>=1.1:graphics/eglexternalplatform
LIB_DEPENDS=	libwayland-server.so:graphics/wayland

USES=		gl meson pkgconfig
USE_GITHUB=	yes
USE_GL=		egl
USE_LDCONFIG=	yes
GH_ACCOUNT=	NVIDIA

post-patch:
	@${REINPLACE_CMD} -e "/install/s/datadir')/prefix'), 'libdata'/" \
		${WRKSRC}/meson.build

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/egl/egl_external_platform.d
	${INSTALL_DATA} ${FILESDIR}/10_nvidia_wayland.json \
		${STAGEDIR}${PREFIX}/share/egl/egl_external_platform.d

.include <bsd.port.mk>
