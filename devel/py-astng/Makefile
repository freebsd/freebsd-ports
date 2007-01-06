# New ports collection makefile for:	astng
# Date created:		27 Apr 2006
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	astng
PORTVERSION=	0.16.3
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.logilab.org/pub/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	logilab-${PORTNAME}-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Extension for Python compiler.ast module

RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/logilab/__init__.py:${PORTSDIR}/devel/py-logilab-common

USE_PYTHON=	2.3+
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
