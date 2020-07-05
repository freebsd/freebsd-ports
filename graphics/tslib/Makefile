# $FreeBSD$

PORTNAME=	tslib
DISTVERSION=	1.22
CATEGORIES=	graphics

MAINTAINER=	adridg@FreeBSD.org
COMMENT=	Touchscreen access library

LICENSE=	LGPL21

USES=	cmake

USE_GITHUB=	yes
GH_ACCOUNT=	libts

# - Waveshare requires Linux internals
CMAKE_OFF=	enable-waveshare

.include <bsd.port.mk>
