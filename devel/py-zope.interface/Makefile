# New ports collection makefile for:	py-zopeInterface
# Date created:		13 April 2005
# Whom:	      		Neal Nelson <neal@nelson.name>
#
# $FreeBSD$
#

PORTNAME=	zopeInterface
PORTVERSION=	3.5.2
CATEGORIES=	devel zope python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	zope.interface-${PORTVERSION}

MAINTAINER=	neal@nelson.name
COMMENT=	Zope.interface package from Zope 3

FETCH_CMD=	fetch -RP

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes
PYDISTUTILS_PKGNAME=	zope.interface
PYEASYINSTALL_ARCHDEP=	yes

.include <bsd.port.mk>
