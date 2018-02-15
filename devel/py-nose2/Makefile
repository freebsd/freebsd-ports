# $FreeBSD$

PORTNAME=	nose2
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	daniel@blodan.se
COMMENT=	Next generations of nicer testing for Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}coverage>=4.4.1:devel/py-coverage@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.7:devel/py-six@${FLAVOR}

py27_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=2.0.0:devel/py-mock@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils

.include <bsd.port.mk>
