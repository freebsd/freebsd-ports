# New ports collection makefile for:	py-mahotas
# Date created:		2010-12-14
# Whom:			Pedro Garcia Freitas <sawp@sawp.com.br>
#
# $FreeBSD$
#

PORTNAME=	mahotas
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sawp@sawp.com.br
COMMENT=	An Efficient Image Processing Library for Python

BUILD_DEPENDS+=	${PYNUMPY}

USE_GCC=	4.5+
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes

.include <bsd.port.mk>
