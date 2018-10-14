# $FreeBSD$

PORTNAME=	nose2
PORTVERSION=	0.8.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	daniel@blodan.se
COMMENT=	Next generations of nicer testing for Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=4.4.1:devel/py-coverage@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.7:devel/py-six@${PY_FLAVOR}

py27_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${PY_FLAVOR}

USES=		python

NO_ARCH=	yes
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
