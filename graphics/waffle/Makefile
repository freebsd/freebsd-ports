# Created by: Jean-Sébastien Pédron <dumbbell@FreeBSD.org>
# $FreeBSD$

PORTNAME=	waffle
PORTVERSION=	1.5.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.waffle-gl.org/files/release/waffle-${PORTVERSION}/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Library that allows to defer selection of an OpenGL API until runtime

LICENSE=	BSD2CLAUSE

USES=		cmake:outsource ninja pkgconfig tar:xz
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/waffle1

OPTIONS_DEFINE=	DOCS

USE_XORG=	x11 xcb
USE_GL=		gl egl
CFLAGS+=	-I${LOCALBASE}/include
LIBS+=	-L${LOCALBASE}/lib

#CMAKE_ARGS+=	-Dwaffle_has_glx=ON \
#		-Dwaffle_has_x11_egl=ON

# todo needs libudev
#		-Dwaffle_has_gbm=ON

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
post-install:
	${RM} -rf ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
