# New ports collection makefile for:	Irc Server
# Version required:	2.8.21
# Date created:		23 August 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.10 1996/06/14 08:52:47 asami Exp $
#

DISTNAME=	irc2.8.21
PKGNAME=	irc-2.8.21
CATEGORIES=	net
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/servers/

MAINTAINER=	torstenb@FreeBSD.ORG

# the NOTE command is disabled by default
# ENABLE_NOTE=yes

# Restrictive copyright in irc2.8.21/ircd/res.c
RESTRICTED=	"No redistribution allowed."
MAN8=		ircd.8

pre-install:
	mkdir -p ${PREFIX}/lib/ircd

.include <bsd.port.mk>
