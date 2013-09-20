# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	AddOns
PORTVERSION=	0.7
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://www.turbogears.org/2.0/downloads/2.0.1/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Dynamically extend other objects with AddOns

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}DecoratorTools>=1.7:${PORTSDIR}/devel/py-decoratortools
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
