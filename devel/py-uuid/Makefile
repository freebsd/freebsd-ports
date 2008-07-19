# New ports collection makefile for:	py-uuid
# Date created:				6 July 2008
# Whom:					Junji NAKANISHI <jun-g@daemonfreaks.com>
#
# $FreeBSD$

PORTNAME=	uuid
PORTVERSION=	1.30
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jun-g@daemonfreaks.com
COMMENT=	UUID object and generation functions for Python

USE_PYTHON=	2.4
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

#.if ${PYTHON_REL} >= 250
#IGNORE=		uuid ships with Python 2.5.x
#.endif

.include <bsd.port.post.mk>
