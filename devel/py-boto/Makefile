# New ports collection makefile for:	py-boto
# Date created:			Aug 26, 2007
# Whom:				Peter Schuller <peter.schuller@infidyne.com>
#
# $FreeBSD$
#

PORTNAME=	boto
PORTVERSION=	2.3.0
CATEGORIES=	devel python
MASTER_SITES=	GOOGLE_CODE \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	peter.schuller@infidyne.com
COMMENT=	Python interface to Amazon Web Services

LICENSE=	MIT

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install

CONFLICTS=	p5-Net-Amazon-Route53-[0-9]* py2[0-9]-boto-devel-[0-9]*

.include <bsd.port.mk>
