# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	pycha
PORTVERSION=	0.7.0
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for making charts with Python

LICENSE=	LGPL3

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONS_DEFINE=		CAIRO
OPTIONS_DEFAULT=	CAIRO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCAIRO}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/cairo:${PORTSDIR}/graphics/py-cairo
.endif

.include <bsd.port.mk>
