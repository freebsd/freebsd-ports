# New ports collection makefile for:	zbase32
# Date created:		1st,Oct 2008
# Whom:			Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	zbase32
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	converters python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Base32 Encoder/Decoder

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools_darcs>=1.2.11:${PORTSDIR}/devel/py-setuptools_darcs
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
