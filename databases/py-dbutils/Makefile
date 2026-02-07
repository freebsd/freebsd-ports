PORTNAME=	dbutils
PORTVERSION=	3.1.0
CATEGORIES=	databases python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	DBUtils-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Providing solid, persistent, and pooled connections to a database
WWW=		https://webwareforpython.github.io/DBUtils/ \
		https://github.com/WebwareForPython/DBUtils

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
