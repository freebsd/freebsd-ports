# New ports collection makefile for:	IrcII Client
# Version required:	2.8.16beta
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.8 1995/11/27 04:05:08 asami Exp $
#

DISTNAME=	ircii-2.8.16beta
CATEGORIES+=	net
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/clients/

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	gzip -9nf ${PREFIX}/man/man1/ircII.1 ${PREFIX}/man/man1/ircbug.1

.include <bsd.port.mk>
