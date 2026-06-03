PORTNAME=	array-api-strict
DISTVERSION=	2.5
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI \
		https://github.com/data-apis/array-api-strict/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:tl:C/[-_.]+/_/g}-${DISTVERSION}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	Strict, minimal implementation of the Python array API
WWW=		https://data-apis.org/array-api-strict/ \
		https://github.com/data-apis/array-api-strict

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>8:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>0:math/py-numpy@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>0:devel/py-hypothesis@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517 pytest

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|setuptools >= 61.0,<=75|setuptools >= 61|' \
		${WRKSRC}/pyproject.toml

.include <bsd.port.mk>
