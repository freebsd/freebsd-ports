# Created by: Zhihao Yuan <lichray@gmail.com>
# $FreeBSD$

PORTNAME=	pure-gl
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure language interface to OpenGL

RUN_DEPENDS+=	${LOCALBASE}/lib/pure/ffi.pure:${PORTSDIR}/devel/pure-ffi

USE_PURE=	yes
USE_GL=	glut

MAKE_ARGS+=	LinkGL="-lglut -lGLU -lGL"

.include "${.CURDIR}/../../lang/pure/bsd.pure.mk"
.include <bsd.port.mk>
