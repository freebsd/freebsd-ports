# New ports collection makefile for:	IrcII Client
# Version required:	2.8.2
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.5 1995/04/16 23:54:44 torstenb Exp $
#

DISTNAME=	ircii-2.8.2
CATEGORIES+=	networking
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/clients/
DISTFILES=	ircii-2.8.2.tar.gz ircii-2.8help.tar.gz

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	yes

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib/irc/script
	@mkdir -p ${PREFIX}/lib/irc/translation
	@cp -R ${WRKDIR}/help ${PREFIX}/lib/irc/

.include <bsd.port.mk>
