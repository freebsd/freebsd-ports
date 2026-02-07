PORTNAME=	easyprocess
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	EasyProcess-${PORTVERSION}

MAINTAINER=	daniel@blodan.se
COMMENT=	Easy to use python subprocess interface
WWW=		https://github.com/ponty/EasyProcess

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}paver>0:devel/py-paver@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cogapp>=2.3:devel/py-cogapp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR}

NO_ARCH=	YES
USE_PYTHON=	autoplist distutils
USES=		python

.include <bsd.port.mk>
