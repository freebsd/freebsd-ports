PORTNAME=	pip-tools
PORTVERSION=	7.5.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pip_tools-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Keep your pinned dependencies fresh
WWW=		https://github.com/jazzband/pip-tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=7:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}build>=1.0.0:devel/py-build@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}click>=8:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=22.2:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyproject-hooks>=0:devel/py-pyproject-hooks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
