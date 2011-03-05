# New ports collection makefile for:	py-distribute
# Date created:		2010-05-06
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	distribute
PORTVERSION=	0.6.14
#PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A Python packages installer, and Setuptools replacement

CONFLICTS=	py[2-3][0-9]-setuptools-[0-9]*

PLIST_SUB=	PYVER=${PYTHON_VER} VERSION=${PORTVERSION} SETUPTOOLS_VER=0.6c11

PYDISTUTILS_NOEGGINFO=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.mk>
