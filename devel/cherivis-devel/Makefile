# $FreeBSD$

PORTNAME=	cherivis-devel
PORTVERSION=	0.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel gnustep

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Visualisation tool for CHERI / BERI streamtraces

LICENSE=	MIT

BROKEN_FreeBSD_9=	does not build on FreeBSD 9.x

USES=		gnustep
USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-CHERI
GH_PROJECT=	CheriVis

LIB_DEPENDS+=	libcheritrace.so:devel/cheritrace-devel

USE_GNUSTEP=		back build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

.include <bsd.port.mk>
