# New ports collection makefile for:	resid
# Date created:				6 October 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	resid
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	audio emulators
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Cycle-based SID emulator engine

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=		--enable-shared

.include <bsd.port.mk>
