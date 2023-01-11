PORTNAME=	python-libsbml
DISTVERSION=	5.19.0
CATEGORIES=	biology python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LibSBML Python API
WWW=		https://sbml.org/Main_Page

LICENSE=	LGPL21

BUILD_DEPENDS=	cmake:devel/cmake-core \
		swig:devel/swig

USES=		python:3.6-3.9
USE_PYTHON=	autoplist distutils # autoplist produces incomplete plist, missing files are in pkg-plist. Reported to the upstream author fbergman@caltech.edu on 2021-08-17

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/libsbml/_libsbml*.so

.include <bsd.port.mk>
