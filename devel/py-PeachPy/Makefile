# $FreeBSD$

PORTNAME=	PeachPy
DISTVERSION=	0.0.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Portable efficient assembly codegen in higher-level Python

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		python:2.7 zip # fails with python-3.6: https://bitbucket.org/MDukhan/peachpy/issues/5/fails-with-python-36
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
