# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTNAME=	waffle
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.waffle-gl.org/files/release/waffle-${PORTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Library that allows to defer selection of an OpenGL API until runtime

LICENSE=	BSD2CLAUSE

USES=		cmake:outsource compiler:c11 localbase ninja pathfix pkgconfig tar:xz
USE_GL=		egl gl
USE_LDCONFIG=	yes
USE_XORG=	x11 xcb

DOCSDIR=	${PREFIX}/share/doc/waffle1

CMAKE_ARGS+=	-Dwaffle_has_glx=ON \
		-Dwaffle_has_x11_egl=ON
#CMAKE_ARGS+=	-Dwaffle_has_gbm=ON # FIXME: Required udev

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
