PORTNAME=	check-manifest
PORTVERSION=	0.51
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	check_manifest-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool to check the completeness of MANIFEST.in for Python packages
WWW=		https://github.com/mgedmin/check-manifest

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>=0.1:devel/py-build@${PY_FLAVOR} \
		${PY_TOMLI}
TEST_DEPENDS=	git-tiny>=0:devel/git@tiny \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

.include <bsd.port.mk>
