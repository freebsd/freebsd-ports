# $FreeBSD$

PORTNAME=	kayako
PORTVERSION=	1.1.5
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python API Wrapper for Kayako

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
