# New ports collection makefile for:	pcemu(1)
# Version required:	1.01alpha
# Date created:		7 March 1995
# Whom:			joerg
#
# $FreeBSD$
#

DISTNAME=	pcemu1.01alpha
PKGNAME=	pcemu-1.01a
CATEGORIES=	emulators

# Warning notice:  by now, you'll have to live with those warnings:
#
#In file included from /usr/include/sys/types.h:48,
#                 from /usr/include/stdio.h:43,
#                 from main.c:22:
#/usr/include/machine/endian.h:50: warning: `LITTLE_ENDIAN' redefined
#*Initialization*:1: warning: this is the location of the previous definition

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

MAINTAINER=	joerg@FreeBSD.org

USE_XLIB=	yes
MAKE_ENV=	FILESDIR=${FILESDIR}

.include <bsd.port.mk>
