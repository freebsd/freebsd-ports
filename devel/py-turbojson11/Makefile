# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	TurboJson
PORTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	11

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python template plugin for TurboGears that supports json

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}RuleDispatch>=0.5.a0.r2306:${PORTSDIR}/devel/py-ruledispatch \
		${PYTHON_PKGNAMEPREFIX}simplejson>=1.9.1:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}DecoratorTools>=1.7:${PORTSDIR}/devel/py-decoratortools

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
