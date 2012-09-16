# New ports collection makefile for:	py-carbon
# Date created:		2011-05-01
# Whom:			Evan Sarmiento <bsdports@wayfair.com>
#
# $FreeBSD$
#

PORTNAME=	carbon
PORTVERSION=	0.9.10
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://launchpad.net/graphite/0.9/${PORTVERSION}/+download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bsdports@wayfair.com
COMMENT=	Backend storage application for graphite

LICENSE=	AL2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}txamqp>=0.3:${PORTSDIR}/net/py-txamqp \
		${PYTHON_PKGNAMEPREFIX}whisper>=0.9.10:${PORTSDIR}/databases/py-whisper \
		${PYTHON_PKGNAMEPREFIX}twisted>=11.0.0:${PORTSDIR}/devel/py-twisted

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes
FETCH_ARGS=	-pRr
USE_RC_SUBR=	carbon

.include <bsd.port.mk>
