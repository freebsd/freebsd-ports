# New ports collection makefile for:	IrcII Client
# Version required:	2.9
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.10 1996/04/01 07:11:29 asami Exp $
#

DISTNAME=	ircii-2.9-base
PKGNAME=	ircii-2.9
CATEGORIES+=	net
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/clients/

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PKGNAME}

.if !defined(NOMANCOMPRESS)
post-install:
	gzip -9nf ${PREFIX}/man/man1/ircII.1 ${PREFIX}/man/man1/ircbug.1
.endif

.include <bsd.port.mk>
