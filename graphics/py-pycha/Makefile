# Ports collection makefile for:	pycha
# Date created:			08 July, 2009
# Whom:				Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pycha
PORTVERSION=	0.5.0
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wenheping@gmail.com
COMMENT=	A library for making charts with Python

USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install

OPTIONS=	CAIRO   "Add support for py-cairo" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CAIRO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/cairo:${PORTSDIR}/graphics/py-cairo
.endif

.include <bsd.port.post.mk>
