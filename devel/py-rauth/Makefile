# New ports collection makefile for:	py-rauth
# Date created:				2012-06-17
# Whom:					koobs <koobs.freebsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	rauth
PORTVERSION=	0.4.14
CATEGORIES=	devel www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs.freebsd@gmail.com
COMMENT=	A Python library for OAuth 1.0/a, 2.0, and Ofly consumers

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0.12.0:${PORTSDIR}/www/py-requests

# Python3 ready
USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install

.include <bsd.port.mk>
