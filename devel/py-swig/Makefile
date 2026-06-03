PORTNAME=	swig
DISTVERSION=	4.4.1
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	python

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python wrapper for the SWIG code generation tool
WWW=		https://swig.org/ \
		https://github.com/nightlark/swig-pypi

LICENSE=	APACHE20

RUN_DEPENDS=	swig:devel/swig

USES=		python
USE_PYTHON=	pep517 autoplist

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

NO_ARCH=	yes

.include <bsd.port.mk>
