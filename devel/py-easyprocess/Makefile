PORTNAME=	easyprocess
PORTVERSION=	0.2.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	EasyProcess-${PORTVERSION}

MAINTAINER=	daniel@blodan.se
COMMENT=	Easy to use python subprocess interface

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paver>0:devel/py-paver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cog>=2.3:devel/py-cog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}

NO_ARCH=	YES
USE_PYTHON=	autoplist distutils
USES=		python:3.6+

.include <bsd.port.mk>
