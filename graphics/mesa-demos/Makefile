PORTNAME=	mesa-demos
PORTVERSION=	9.0.0
CATEGORIES=	graphics
MASTER_SITES=	https://mesa.freedesktop.org/archive/demos/ \
		ftp://ftp.freedesktop.org/pub/mesa/demos/ #${PORTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	OpenGL demos distributed with Mesa
WWW=		https://www.mesa3d.org/

LICENSE=	MIT

CONFLICTS_INSTALL=	glx-utils

BUILD_DEPENDS=	glslangValidator:graphics/glslang \
		vulkan-headers>0:graphics/vulkan-headers

LIB_DEPENDS=	libvulkan.so:graphics/vulkan-loader \
		libxkbcommon.so:x11/libxkbcommon

USES=		gl localbase meson pkgconfig tar:xz xorg
USE_GL=		egl gl glesv2 glu glut
USE_XORG=	xcb xorgproto x11 xdamage xext xfixes xi xxf86vm

MESON_ARGS+=	-Dwith-glut=${LOCALBASE} \
		-Dgles1=disabled \
		-Dlibdrm=disabled \
		-Dosmesa=disabled \
		-Dwayland=disabled \
		-Dwith-system-data-files=true

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-stage:
	# bitmap program conflicts with x11/bitmap
	${MV} ${STAGEDIR}/${PREFIX}/bin/bitmap ${STAGEDIR}/${PREFIX}/bin/bitmap_demo

.include <bsd.port.mk>
