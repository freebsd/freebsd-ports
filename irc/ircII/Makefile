# New ports collection makefile for:	IrcII Client
# Version required:	2.8.2
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.7 1995/05/06 00:32:12 torstenb Exp $
#

DISTNAME=	ircii-2.8.2
CATEGORIES+=	net
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/clients/
DISTFILES=	ircii-2.8.2.tar.gz ircii-2.8help.tar.gz

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	cp -R ${WRKDIR}/help ${PREFIX}/lib/irc/
	install -c ${WRKDIR}/${DISTNAME}/doc/ircII.1 ${PREFIX}/man/man1/irc.1
	gzip -9nf ${PREFIX}/man/man1/irc.1

.include <bsd.port.mk>
