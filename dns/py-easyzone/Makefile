# New ports collection makefile for:	py-easyzone
# Date created:				10 February 2012
# Whom:					Attila Nagy <bra@fsn.hu>
#
# $FreeBSD$
#

PORTNAME=	easyzone
PORTVERSION=	1.2.2
CATEGORIES=	dns python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bra@fsn.hu
COMMENT=	DNS Zone abstraction module for Python

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dnspython>=1.9.4:${PORTSDIR}/dns/py-dnspython

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_NOEGGINFO=	yes
PYDISTUTILS_PKGNAME=	easyzone
PLIST_SUB+=	PORTVERSION=${PORTVERSION} \
		PYTHON_VER=${PYTHON_VER}

.include <bsd.port.mk>
