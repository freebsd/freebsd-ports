# Created by: Evan Sarmiento <bsdports@wayfair.com>
# $FreeBSD$

PORTNAME=	carbon
PORTVERSION=	0.9.12
PORTREVISION=	2
CATEGORIES=	databases python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Backend storage application for graphite

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}txamqp>=0.3:${PORTSDIR}/net/py-txamqp \
		${PYTHON_PKGNAMEPREFIX}whisper>=0.9.10:${PORTSDIR}/databases/py-whisper \
		${PYTHON_PKGNAMEPREFIX}django18>=1.4:${PORTSDIR}/www/py-django18

USE_PYTHON=	distutils
USES=		python:2 twisted:run
USE_RC_SUBR=	carbon
USE_GITHUB=	yes
GH_ACCOUNT=	graphite-project

.include <bsd.port.mk>
