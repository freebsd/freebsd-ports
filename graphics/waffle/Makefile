# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTNAME=	waffle
PORTVERSION=	1.5.2
PORTREVISION=	9
CATEGORIES=	graphics
MASTER_SITES=	http://www.waffle-gl.org/files/release/waffle-${PORTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Library that allows to defer selection of an OpenGL API until runtime

LICENSE=	BSD2CLAUSE

USES=		cmake compiler:c11 gl localbase pathfix pkgconfig tar:xz xorg
USE_GL=		egl gl
USE_LDCONFIG=	yes
USE_XORG=	x11 xcb

DOCSDIR=	${PREFIX}/share/doc/waffle1

CMAKE_ARGS+=	-Dwaffle_has_glx=ON \
		-Dwaffle_has_x11_egl=ON
#CMAKE_ARGS+=	-Dwaffle_has_gbm=ON # FIXME: Required udev

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS WAYLAND
OPTIONS_DEFAULT=WAYLAND

WAYLAND_LIB_DEPENDS=	libwayland-egl.so:graphics/wayland
WAYLAND_CMAKE_BOOL=	waffle_has_wayland

.include <bsd.port.mk>
