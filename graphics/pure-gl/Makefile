# New ports collection makefile for:	pure-gtk
# Date created:		2011-03-18
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-gl
PORTVERSION=	0.8
CATEGORIES=	graphics
MASTER_SITES=	http://pure-lang.googlecode.com/files/

MAINTAINER=	lichray@gmail.com
COMMENT=	Pure language interface to OpenGL

LIB_DEPENDS+=	pure.7:${PORTSDIR}/lang/pure
RUN_DEPENDS+=	${LOCALBASE}/lib/pure/ffi.pure:${PORTSDIR}/devel/pure-ffi

LICENSE_FILE=	${WRKSRC}/COPYING

USE_GMAKE=	yes
USE_GL=	glut

MAKE_ARGS+=	prefix=${PREFIX} CPPFLAGS+=-I${LOCALBASE}/include LDFLAGS+=-L${LOCALBASE}/lib \
		CFLAGS="${CFLAGS}" LinkGL="-lglut -lGLU -lGL"

PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
