# New ports collection makefile for:	pcemu(1)
# Date created:		7 March 1995
# Whom:			joerg
#
# $FreeBSD$
#

PORTNAME=	pcemu
PORTVERSION=	1.01b
PORTREVISION=	1
CATEGORIES=	emulators
#
# This could in theory become a chicken-and-egg problem.  Anyway,
# wcarchive is well connected, and the distfile hasn't been changed
# for years now.
MASTER_SITES+=	ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/
#
# interface business GmbH is not so well connected, but Joerg's got
# direct access there.
MASTER_SITES+=	ftp://ftp.interface-business.de/pub/outgoing/
#
# This is the original master site, but better use a well-connected server
MASTER_SITES+=	ftp://ftp.cs.bris.ac.uk/pub/users/hedley/
DISTNAME=	pcemu1.01alpha

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	An 8086 PC emulator, by David Hedley

BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_XLIB=	yes
MAKE_ENV=	FILESDIR=${FILESDIR}

.include <bsd.port.mk>
