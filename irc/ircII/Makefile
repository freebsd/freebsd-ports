# New ports collection makefile for:	IrcII Client
# Version required:	2.9
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.11 1996/06/17 22:24:20 torstenb Exp $
#

DISTNAME=	ircii-2.9-roof
PKGNAME=	ircii-2.9
CATEGORIES+=	net
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/clients/

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	yes

CONFIGURE_ARGS= --with-default-server="irc.FreeBSD.ORG"

WRKSRC=		${WRKDIR}/${PKGNAME}

.if !defined(NOMANCOMPRESS)
post-install:
	gzip -9nf ${PREFIX}/man/man1/ircII.1 ${PREFIX}/man/man1/ircbug.1
.endif

.include <bsd.port.mk>
