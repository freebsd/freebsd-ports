PORTNAME=	pymongo
PORTVERSION=	4.18.2
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Python driver for MongoDB
WWW=		https://github.com/mongodb/mongo-python-driver

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hatch-requirements-txt>=0.4.1:devel/py-hatch-requirements-txt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=2.6.1:dns/py-dnspython@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	mongodb
USE_PYTHON=	autoplist concurrent pep517

CONFLICTS_INSTALL=	py[0-9][0-9]-pymongo28

post-install:
	        ${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/bson/_cbson${PYTHON_TAG}.so
	        ${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/pymongo/_cmessage${PYTHON_TAG}.so

.include <bsd.port.mk>
