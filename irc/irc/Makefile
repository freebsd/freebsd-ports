# New ports collection makefile for:	Irc Server
# Version required:	2.8.21
# Date created:		23 August 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.8 1995/06/27 00:12:28 torstenb Exp $
#

DISTNAME=	irc2.8.21
PKGNAME=	irc-2.8.21
CATEGORIES+=	net
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/servers/

MAINTAINER=	torstenb@FreeBSD.ORG

# the NOTE command is disabled by default
# ENABLE_NOTE=yes

# Restrictive copyright in irc2.8.21/ircd/res.c
NO_PACKAGE=	yes

pre-install:
	mkdir -p ${PREFIX}/lib/ircd

post-install:
	gzip -9nf ${PREFIX}/man/man8/ircd.8

.include <bsd.port.mk>
