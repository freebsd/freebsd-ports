# Created by: nwhitehorn
# $FreeBSD$

PORTNAME=	astropy
DISTVERSION=	4.0.1
PORTEPOCH=	2
CATEGORIES=	astro
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nwhitehorn@FreeBSD.org
COMMENT=	Community-developed python astronomy tools

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.rst

BUILD_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}astropy-helpers>=0:astro/py-astropy-helpers@${PY_FLAVOR}
RUN_DEPENDS=	${PYNUMPY}

USES=		compiler:c11 python:3.5+
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
