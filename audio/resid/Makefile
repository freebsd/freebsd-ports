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
MASTER_SITES=	http://critical.ch/distfiles/ \
		http://energy.critical.ch/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Cycle-based SID emulator engine

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--enable-shared

.include <bsd.port.mk>
