# ex:ts=8
# Ports collection makefile for:	visionegg
# Date created:			Jan 9, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	visionegg
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Visual stimulus creation and control

BUILD_DEPENDS=	\
	${PYNUMERIC} \
	${PYTHON_SITELIBDIR}/PIL/Image.py:${PORTSDIR}/graphics/py-imaging \
	${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl \
	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game
RUN_DEPENDS=	\
	${PYNUMERIC} \
	${PYTHON_SITELIBDIR}/PIL/Image.py:${PORTSDIR}/graphics/py-imaging \
	${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl \
	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

USE_MESA=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_BUILDARGS=	-L${X11BASE}/lib
CFLAGS+=	-I${X11BASE}/include

do-build:
	@(cd ${BUILD_WRKSRC}; \
	  ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} build_py ; \
	  ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} build_ext ${PYDISTUTILS_BUILDARGS})

.include <bsd.port.mk>
