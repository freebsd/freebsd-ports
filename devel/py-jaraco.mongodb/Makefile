PORTNAME=	jaraco.mongodb
PORTVERSION=	12.4.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	jaraco_mongodb-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Routines and classes supporting MongoDB environments
WWW=		https://pypi.org/project/jaraco.mongodb/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61.2:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=3.4.1:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cachetools>=0:devel/py-cachetools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dnspython>=0,1:dns/py-dnspython@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.collections>=2:devel/py-jaraco.collections@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.context>=2:devel/py-jaraco.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.functools>=2:devel/py-jaraco.functools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.itertools>=2:devel/py-jaraco.itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.logging>=2:devel/py-jaraco.logging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.services>=2:devel/py-jaraco.services@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jaraco.ui>=2.4:devel/py-jaraco.ui@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}more-itertools>=0:devel/py-more-itertools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}portend>=0:net/py-portend@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymongo>=3.5:databases/py-pymongo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytimeparse>=0:devel/py-pytimeparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tempora>=0:devel/py-tempora@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31200
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}backports.tarfile>=0:devel/py-backports.tarfile@${PY_FLAVOR}
.endif

.include <bsd.port.post.mk>
