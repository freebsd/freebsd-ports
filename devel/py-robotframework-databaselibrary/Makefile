PORTNAME=	robotframework-databaselibrary
PORTVERSION=	2.1.4
CATEGORIES=	devel www python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	robotframework_databaselibrary-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database Library for Robot Framework
WWW=		https://marketsquare.github.io/Robotframework-Database-Library/ \
		https://github.com/MarketSquare/Robotframework-Database-Library

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}robotframework>=5.0.1:devel/py-robotframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}robotframework-assertion-engine>=0:devel/py-robotframework-assertion-engine@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=61.0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}robotframework>=5.0.1:devel/py-robotframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}robotframework-assertion-engine>=0:devel/py-robotframework-assertion-engine@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
