# New ports collection makefile for:	Irc Server
# Version required:	2.8.20
# Date created:		23 August 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.3 1995/02/11 01:44:28 torstenb Exp $
#

DISTNAME=	irc2.8.21
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/servers/
CATEGORIES+=	networking

pre-install:
	mkdir -p ${PREFIX}/bin
	mkdir -p ${PREFIX}/lib/ircd
	mkdir -p ${PREFIX}/man/man1
	mkdir -p ${PREFIX}/man/man8

.include <bsd.port.mk>
