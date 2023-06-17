PORTNAME=	time-machine
DISTVERSION=	2.10.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/1}-${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Travel through time in your Python tests
WWW=		https://github.com/adamchainz/time-machine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.40.0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=2.8.2:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.5:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist pep517

post-install:
		${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/_time_machine${PYTHON_EXT_SUFFIX}.so

.include <bsd.port.mk>
