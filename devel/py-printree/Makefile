PORTNAME=	printree
DISTVERSION=	0.2.1
CATEGORIES=	devel science
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pretty print python objects in a tree format
WWW=		https://github.com/chrizzFTD/printree

LICENSE=	MIT

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

NO_ARCH=	yes

# tests as of 0.2.1: 7 passed, 1 warning in 3.30s

.include <bsd.port.mk>
