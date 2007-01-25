# New ports collection makefile for:	hachoir-parser
# Date created:		25 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hachoir-parser
PORTVERSION=	0.8.1
CATEGORIES=	devel python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/h/${PORTNAME}/ CSME

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Parsers of most common file formats

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/hachoir_core/__init__.py:${PORTSDIR}/devel/hachoir-core

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
