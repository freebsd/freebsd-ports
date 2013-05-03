# Created by: Wen Heping <wenheping@wenheping.com>
# $FreeBSD$

PORTNAME=	svglib
PORTVERSION=	0.6.3
PORTREVISION=	1
CATEGORIES=	converters python
MASTER_SITES=	CHEESESHOP \
		http://www.dinu-gherman.net/tmp/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	An Library For Reading And Converting SVG

BROKEN=		Does not fetch

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}reportlab2>0:${PORTSDIR}/print/py-reportlab2

LICENSE=	LGPL3

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
