# New ports collection makefile for:	py-boto
# Date created:			Aug 26, 2007
# Whom:				Peter Schuller <peter.schuller@infidyne.com>
#
# $FreeBSD$
#

PORTNAME=	boto
PORTVERSION=	1.9b
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	peter.schuller@infidyne.com
COMMENT=	Python interface to Amazon Web Services

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

CONFLICTS=	py2[0-9]-boto-devel-[0-9]*

.include <bsd.port.mk>
