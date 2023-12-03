PORTNAME=	python-libsbml
DISTVERSION=	5.20.1
CATEGORIES=	biology python
#MASTER_SITES=	PYPI # no tarballs on PYPI
MASTER_SITES=	https://github.com/sbmlteam/python-libsbml/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LibSBML Python API
WWW=		https://sbml.org/Main_Page

LICENSE=	LGPL21

BUILD_DEPENDS=	cmake:devel/cmake-core \
		swig:devel/swig

USES=		python
USE_PYTHON=	autoplist distutils # autoplist produces incomplete plist, missing files are in pkg-plist. Reported to the upstream author fbergman@caltech.edu on 2021-08-17

MAKE_ENV=	CMAKE_BUILD_PARALLEL_LEVEL=${MAKE_JOBS_NUMBER}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/libsbml/_libsbml*.so

.include <bsd.port.mk>
