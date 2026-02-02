PORTNAME=	spin
DISTVERSION=	0.17
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Scientific Python INcantations (spin)
WWW=		https://pypi.python.org/pypi/spin

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_TOMLI} \
		${PYTHON_PKGNAMEPREFIX}click>=8,<8.4:devel/py-click@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}importlib-metadata>=7:devel/py-importlib-metadata@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
