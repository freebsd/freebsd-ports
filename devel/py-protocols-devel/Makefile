# New ports collection makefile for:	py-protocols-devel
# Date created:		15 December 2006
# Whom:			Dryice Liu	<dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	PyProtocols
PORTVERSION=	1.0.a0.r2302
CATEGORIES=	devel python
MASTER_SITES=	http://files.turbogears.org/eggs/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-1.0a0dev-r2302

MAINTAINER=	wenheping@gmail.com
COMMENT=	Protocol Definition, Declaration, and Adaptation for Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}DecoratorTools>=1.7:${PORTSDIR}/devel/py-decoratortools

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes
PYDISTUTILS_PKGVERSION=	1.0a0dev-r2302

.include <bsd.port.mk>
