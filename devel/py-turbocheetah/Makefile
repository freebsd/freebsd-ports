# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	TurboCheetah
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://files.turbogears.org/eggs/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	TurboGears plugin to support use of Cheetah templates

RUN_DEPENDS=	cheetah:devel/py-cheetah

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		leaves files behind on deinstall
.endif

.include <bsd.port.post.mk>
