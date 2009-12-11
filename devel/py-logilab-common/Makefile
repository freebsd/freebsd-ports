# New ports collection makefile for:	py-logilab-common
# Date created:		28 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	logilab-common
PORTVERSION=	0.45.2
CATEGORIES=	devel python
MASTER_SITES=	LOGILAB/common
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Common low-level libraries shared among logilab projects

USE_PYTHON=	2.4+
USE_PYDISTUTILS=easy_install

post-extract:
	${TOUCH} ${WRKSRC}/test/__init__.py

.include <bsd.port.mk>
