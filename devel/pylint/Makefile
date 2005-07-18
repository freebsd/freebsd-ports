# New ports collection makefile for:	pylint
# Date created:		28 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	pylint
PORTVERSION=	0.7.0
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.logilab.org/pub/pylint/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Analyzes python source code looking for bugs and signs of poor quality

RUN_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/logilab/__init__.py:${PORTSDIR}/devel/py-logilab-common

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

.include <bsd.port.mk>
