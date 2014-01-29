# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	TurboKid
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Python template plugin that supports Kid templates

RUN_DEPENDS=	kid:${PORTSDIR}/devel/py-kid

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
