# ex:ts=8
# Ports collection makefile for:	py-simpleparse
# Date created:			Jan 6, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	simpleparse
PORTVERSION=	2.1.0.a1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/2.1.0a1
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	SimpleParse-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python EBNF parser generator for use with mx.TextTools

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/TextTools/TextTools.py:${PORTSDIR}/lang/py-mx-base

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	SimpleParse
PYDISTUTILS_PKGVERSION=	2.1.0a1

.include <bsd.port.mk>
