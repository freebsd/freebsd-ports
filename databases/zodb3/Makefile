# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	zodb
PORTVERSION=	3.10.5
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	CHEESESHOP
PKGNAMESUFFIX=	-py${PYTHON_SUFFIX}
DISTNAME=	ZODB3-${PORTVERSION}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Z - Object Database for python

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zconfig>=0:devel/py-zconfig@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zdaemon>=0:sysutils/py-zdaemon@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}transaction>=1.1.0:devel/py-transaction@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zclockfile>=1.0.0:devel/py-zclockfile@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.event>=1.0.0:devel/py-zope.event@${FLAVOR}

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
