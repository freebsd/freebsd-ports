# Created by: Attila Nagy <bra@fsn.hu>
# $FreeBSD$

PORTNAME=	easyzone
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bra@fsn.hu
COMMENT=	DNS Zone abstraction module for Python

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=1.9.4:${PORTSDIR}/dns/py-dnspython
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
