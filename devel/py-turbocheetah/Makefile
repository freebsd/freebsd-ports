# New ports collection makefile for:	py-turbocheetah
# Date created:		2006-12-01
# Whom:			Nicola Vitale <nivit@email.it>
#
# $FreeBSD$
#

PORTNAME=	TurboCheetah
PORTVERSION=	1.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://files.turbogears.org/eggs/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	TurboGears plugin to support use of Cheetah templates

RUN_DEPENDS=	cheetah:${PORTSDIR}/devel/py-cheetah

USE_PYTHON=		2.4+
USE_PYDISTUTILS=	easy_install

.include <bsd.port.mk>
