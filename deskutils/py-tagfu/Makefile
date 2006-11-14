# New ports collection makefile for:	py-tagfu
# Date created:				14 Nov 2006
# Whom:					Alexander Botero-Lowry <alexbl@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	tagfu
PORTVERSION=	0.1
CATEGORIES=	deskutils devel python
MASTER_SITES=	http://www.geekfire.com/~alex/tagfu/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	Python module for tagging urls with tags or metadata

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/pysqlite2/__init__.py:${PORTSDIR}/databases/py-pysqlite22

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
