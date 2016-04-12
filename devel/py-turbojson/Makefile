# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	TurboJson
PORTVERSION=	1.3.2
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://www.turbogears.org/2.1/downloads/2.1.4/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python template plugin for TurboGears that supports json

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=1.9.1:devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}PEAK-Rules>=0:devel/py-PEAK-Rules
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=1.9.1:devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}PEAK-Rules>=0:devel/py-PEAK-Rules

USES=		python:2
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
