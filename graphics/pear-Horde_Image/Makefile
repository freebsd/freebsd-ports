# $FreeBSD$

PORTNAME=	Horde_Image
PORTVERSION=	2.6.0
CATEGORIES=	graphics www pear
PKGNAMEPREFIX=	${PEAR_PKGNAMEPREFIX}

MAINTAINER=	horde@FreeBSD.org
COMMENT=	Horde Image API

USES=	horde
USE_HORDE_RUN=	Horde_Exception \
		Horde_Support \
		Horde_Translation \
		Horde_Util

OPTIONS_DEFINE=	GD
GD_DESC=	Depend on PHP gd extension

GD_USES=	php
GD_USE=		PHP=gd

.include <bsd.port.mk>
