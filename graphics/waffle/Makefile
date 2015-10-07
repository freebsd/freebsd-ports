# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTNAME=	waffle
PORTVERSION=	1.5.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.waffle-gl.org/files/release/waffle-${PORTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Library that allows to defer selection of an OpenGL API until runtime

LICENSE=	BSD2CLAUSE

USES=		cmake:outsource compiler:c11 ninja pkgconfig tar:xz
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/waffle1

OPTIONS_DEFINE=	DOCS

USE_XORG=	x11 xcb
USE_GL=		gl egl
CFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

CMAKE_ARGS+=	-Dwaffle_has_glx=ON
#CMAKE_ARGS+=	-Dwaffle_has_x11_egl=ON
#CMAKE_ARGS+=	-Dwaffle_has_gbm=ON # FIXME: Required udev

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

post-install-DOCS-off:
	${RM} -rf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
