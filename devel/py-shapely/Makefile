PORTNAME=	Shapely
PORTVERSION=	1.8.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Python Package for Manipulation 2D Geospatial Geometry
WWW=		https://pypi.org/project/Shapely/

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libgeos_c.so:graphics/geos

USES=		python:3.7+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${SETENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
