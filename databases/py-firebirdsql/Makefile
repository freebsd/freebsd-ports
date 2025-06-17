PORTNAME=	firebirdsql
DISTVERSION=	1.3.5
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jjachuf@gmail.com
COMMENT=	Python DBAPI module for FirebirdSQL
WWW=		https://github.com/nakagami/pyfirebirdsql

LICENSE=	BSD2CLAUSE


BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist pep517

.include <bsd.port.mk>
