PORTNAME=	pygmsh
DISTVERSION=	7.1.17
PORTREVISION=	2
CATEGORIES=	cad python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python frontend for Gmsh (on top of Gmsh's own binding)
WWW=		https://github.com/meshpro/pygmsh

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

PY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gmsh>0:cad/py-gmsh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}meshio>=4.3.2:science/py-meshio@${PY_FLAVOR} \
		${PYNUMPY}
BUILD_DEPENDS=	${PY_DEPENDS}
RUN_DEPENDS=	${PY_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist pytest # 1 error and many warnings in tests, see https://github.com/meshpro/pygmsh/issues/564

NO_ARCH=	yes

pre-configure:
	@( \
		${ECHO} "from setuptools import setup" && \
		${ECHO} "setup()" \
	) > ${WRKSRC}/setup.py

.include <bsd.port.mk>
