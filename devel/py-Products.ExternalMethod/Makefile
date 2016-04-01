# $FreeBSD$

PORTNAME=	Products.ExternalMethod
PORTVERSION=	2.13.1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Support for external Python methods within a Zope 2 environment

LICENSE=	ZPL21
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>=0:security/py-AccessControl \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:devel/py-ExtensionClass \
		${PYTHON_PKGNAMEPREFIX}Persistence>=0:devel/py-Persistence \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3

NO_ARCH=	yes
USES=		python zip
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
