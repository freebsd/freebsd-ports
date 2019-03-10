# $FreeBSD$

PORTNAME=	launchpadlib
PORTVERSION=	1.10.6
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Python API for Launchpad

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.txt

RUN_DEPENDS=	\
	${PYTHON_PKGNAMEPREFIX}httplib2>=0:www/py-httplib2@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}keyring>=0:security/py-keyring@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}lazr.restfulclient>=0:devel/py-lazr.restfulclient@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}lazr.uri>=0:devel/py-lazr.uri@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}testresources>=0:devel/py-testresources@${PY_FLAVOR} \
	${PYTHON_PKGNAMEPREFIX}wadllib>=0:devel/py-wadllib@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
