# Created by: Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
# $FreeBSD$

PORTNAME=	zodb
PORTVERSION=	3.10.5
CATEGORIES=	databases
MASTER_SITES=	CHEESESHOP
PKGNAMESUFFIX=	-py${PYTHON_SUFFIX}
DISTNAME=	ZODB3-${PORTVERSION}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Z - Object Database for python

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zconfig>=0:${PORTSDIR}/devel/py-zconfig \
		${PYTHON_PKGNAMEPREFIX}zdaemon>=0:${PORTSDIR}/sysutils/py-zdaemon \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}transaction>=1.1.0:${PORTSDIR}/devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}zclockfile>=1.0.0:${PORTSDIR}/devel/py-zclockfile \
		${PYTHON_PKGNAMEPREFIX}zope.event>=1.0.0:${PORTSDIR}/devel/py-zope.event

USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes
PYDISTUTILS_PKGNAME=	ZODB3

NO_STAGE=	yes

.include <bsd.port.mk>
