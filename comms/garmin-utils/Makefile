# New ports collection makefile for:   garmin-utils
# Date created:        4 Oct 2003
# Whom:                Matthew Braithwaite <mab@red-bean.com>
#
# $FreeBSD$
#

PORTNAME=	garmin-utils
PORTVERSION=	2.2
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.snafu.org/pub/

MAINTAINER=	mab@red-bean.com
COMMENT=	Utilities for Garmin GPS receivers

MAN1=		gardump.1 garload.1
MANCOMPRESSED=	yes
MAKE_ARGS+=	MANDIR=${MANPREFIX}/man/man \
		GPS_SERIAL_PORT=/dev/cuaa0

PLIST_FILES=	bin/gardump bin/garload

.include <bsd.port.mk>
