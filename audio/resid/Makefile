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
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Cycle-based SID emulator engine

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--enable-shared

.include <bsd.port.mk>
