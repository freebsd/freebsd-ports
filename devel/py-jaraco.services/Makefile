PORTNAME=	jaraco.services
PORTVERSION=	4.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jaraco_services-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Service orchestration and pytest plugins
WWW=		https://github.com/jaraco/jaraco.services

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}jaraco.classes>=0:devel/py-jaraco.classes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}path>=0:devel/py-path@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portend>=0:net/py-portend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tempora>=0:devel/py-tempora@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
