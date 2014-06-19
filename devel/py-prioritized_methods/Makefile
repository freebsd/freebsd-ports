# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	prioritized_methods
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Extension to PEAK-Rules to prioritize methods

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PEAK-Rules>=0.5:${PORTSDIR}/devel/py-PEAK-Rules
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
