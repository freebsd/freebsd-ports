# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	TurboJson
PORTVERSION=	1.1.4
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	11

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python template plugin for TurboGears that supports json

DEPRECATED=	Development of this branch ceased
EXPIRATION_DATE=	2017-03-03

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}RuleDispatch>=0.5.a0.r2306:devel/py-ruledispatch \
		${PYTHON_PKGNAMEPREFIX}simplejson>=1.9.1:devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}DecoratorTools>=1.7:devel/py-decoratortools

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
