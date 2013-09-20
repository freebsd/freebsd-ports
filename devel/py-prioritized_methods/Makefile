# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	prioritized_methods
PORTVERSION=	0.2.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	An extension to PEAK-Rules to prioritize methods

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PEAK-Rules>=0.5:${PORTSDIR}/devel/py-PEAK-Rules
RUN_DEPENDS:=	${BUILD_DEPENDS}

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
