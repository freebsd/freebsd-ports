# New ports collection makefile for:	Irc Server
# Version required:	2.8.21
# Date created:		23 August 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.5 1995/04/15 05:41:35 asami Exp $
#

DISTNAME=	irc2.8.21
PKGNAME=	irc-2.8.21
CATEGORIES+=	networking
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/servers/

MAINTAINER=	torstenb@FreeBSD.ORG

pre-install:
	mkdir -p ${PREFIX}/lib/ircd

post-install:
	gzip -9nf ${PREFIX}/man/man8/ircd.8

.include <bsd.port.mk>
