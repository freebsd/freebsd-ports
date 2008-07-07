# New ports collection makefile for:	py-turbojson
# Date created:		2006-12-02
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	TurboJson
PORTVERSION=	1.1.3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python template plugin for TurboGears that supports json

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}RuleDispatch>=0.5.a0.r2306:${PORTSDIR}/devel/py-ruledispatch \
		${PYTHON_PKGNAMEPREFIX}simplejson>=1.9.1:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}sqlobject>=0.10.0_1:${PORTSDIR}/databases/py-sqlobject

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
