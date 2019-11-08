# Created by: nwhitehorn
# $FreeBSD$

PORTNAME=	astropy
PORTVERSION=	1.1.2 # Do not update without testing ports depending on this one
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	astro
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nwhitehorn@FreeBSD.org
COMMENT=	Community-developed python astronomy tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/licenses/LICENSE.rst

BUILD_DEPENDS=	${PYNUMPY}
RUN_DEPENDS=	${PYNUMPY}

USES=		python:-3.6
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
