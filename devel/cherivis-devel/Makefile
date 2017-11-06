# $FreeBSD$

PORTNAME=	cherivis-devel
PORTVERSION=	0.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel gnustep

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Visualisation tool for CHERI / BERI streamtraces

LICENSE=	MIT

BROKEN_aarch64=		does not compile: error: unexpected token in argument list

USES=		gnustep
USE_GITHUB=	yes
GH_ACCOUNT=	CTSRD-CHERI
GH_PROJECT=	CheriVis

LIB_DEPENDS+=	libcheritrace.so:devel/cheritrace-devel

USE_GNUSTEP=		back build
USE_LDCONFIG=	${GNUSTEP_SYSTEM_LIBRARIES}

.include <bsd.port.mk>
