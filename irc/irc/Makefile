# New ports collection makefile for:	Irc Server
# Version required:	2.8.21
# Date created:		23 August 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.4 1995/04/01 12:48:05 jkh Exp $
#

DISTNAME=	irc2.8.21
PKGNAME=	irc-2.8.21
CATEGORIES+=	networking
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/servers/

pre-install:
	mkdir -p ${PREFIX}/bin
	mkdir -p ${PREFIX}/lib/ircd
	mkdir -p ${PREFIX}/man/man1
	mkdir -p ${PREFIX}/man/man8

.include <bsd.port.mk>
