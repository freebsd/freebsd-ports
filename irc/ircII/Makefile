# New ports collection makefile for:	IrcII Client
# Version required:	2.8.16beta
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.9 1996/03/31 20:25:33 torstenb Exp $
#

DISTNAME=	ircii-2.8.16beta
PKGNAME=	ircii-2.8.16b
CATEGORIES+=	net
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/clients/

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	yes

.if !defined(NOMANCOMPRESS)
post-install:
	gzip -9nf ${PREFIX}/man/man1/ircII.1 ${PREFIX}/man/man1/ircbug.1
.endif

.include <bsd.port.mk>
