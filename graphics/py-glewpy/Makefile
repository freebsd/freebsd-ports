# New ports collection makefile for:	py-glewpy
# Date created:		2006-09-26
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glewpy
PORTVERSION=	0.7.4
CATEGORIES=	graphics python
MASTER_SITES=	SF
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Advanced OpenGL extensions to Python

BUILD_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex
LIB_DEPENDS=	GLEW.1:${PORTSDIR}/graphics/glew

USE_PYTHON=	2.4+
USE_PYDISTUTILS=yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.mk>
