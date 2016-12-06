# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glewpy
PORTVERSION=	0.7.4
PORTREVISION=	4
CATEGORIES=	graphics python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

PATCH_SITES=	http://mirror.amdmi3.ru/distfiles/${DIST_SUBDIR}/ \
		LOCAL/amdmi3
PATCHFILES=	glewpy-${PORTVERSION}-generatedsources.diff.bz2

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Advanced OpenGL extensions to Python

BUILD_DEPENDS=	pyrex>=0.9.6.2:devel/pyrex

USES=		python
USE_GL=		glew
USE_PYTHON=	distutils

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/glew/glew.so
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/glew/gl/*.so

.include <bsd.port.mk>
