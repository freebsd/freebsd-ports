# New ports collection makefile for:	py-logilab-common
# Date created:		28 May 2004
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	logilab-common
PORTVERSION=	0.9.2
CATEGORIES=	devel python
MASTER_SITES=	ftp://ftp.logilab.fr/pub/common/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	common-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Common low-level libraries shared among logilab projects

USE_PYTHON=	2.1+
USE_PYDISTUTILS=yes

post-extract:
	${TOUCH} ${WRKSRC}/test/__init__.py

.include <bsd.port.mk>
