# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	zbase32
PORTVERSION=	1.1.5
PORTREVISION=	1
CATEGORIES=	converters python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Base32 Encoder/Decoder

DEPRECATED=	does not build with python3
EXPIRATION_DATE=2020-10-25

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_darcs>=1.2.11:devel/py-setuptools_darcs@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		python:2.7
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
