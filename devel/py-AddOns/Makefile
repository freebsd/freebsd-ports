# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	AddOns
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://www.turbogears.org/2.0/downloads/2.0.1/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Dynamically extend other objects with AddOns

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}DecoratorTools>=1.7:${PORTSDIR}/devel/py-decoratortools
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
