# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	transaction
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Transaction management for Python

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=3.5.2:${PORTSDIR}/devel/py-zope.interface
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USE_ZIP=	yes

.include <bsd.port.mk>
