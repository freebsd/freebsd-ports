PORTNAME=	toolz
DISTVERSION=	1.2.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Functional standard library for Python
WWW=		https://github.com/pytoolz/toolz

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-git-versioning>=2.0:devel/py-setuptools-git-versioning@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

# tests as of 1.2.0: 192 passed, 1 skipped in 0.14s

.include <bsd.port.mk>
