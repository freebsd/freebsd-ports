# Created by: philip@FreeBSD.org
# $FreeBSD$

PORTNAME=	threema-msgapi
PORTVERSION=	2.1.8
DISTVERSIONPREFIX=	v
CATEGORIES=	devel python
PKGNAMEPREFIX=  ${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Threema Gateway Message SDK for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		python:3.2+
USE_PYTHON=	distutils autoplist
USE_GITHUB=	yes
GH_ACCOUNT=	lgrahl
GH_PROJECT=	threema-msgapi-sdk-python

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}click>0:devel/py3-click \
		${PYTHON_PKGNAMEPREFIX}pylru-cache>0:devel/py3-pylru-cache \
		${PYTHON_PKGNAMEPREFIX}libnacl>0:security/py3-libnacl \
		${PYTHON_PKGNAMEPREFIX}aiohttp>0:www/py-aiohttp

.include <bsd.port.mk>
