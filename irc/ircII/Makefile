# New ports collection makefile for:	IrcII Client
# Version required:	2.6
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.2 1995/02/11 15:22:02 torstenb Exp $
#

DISTNAME=	ircii-2.8
DISTFILES=	ircii-2.8.tar.gz ircii-2.8help.tar.gz
GNU_CONFIGURE=	YES
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/clients/
CATEGORIES+=	networking

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib/irc/script
	@mkdir -p ${PREFIX}/lib/irc/translation
	@cp -R ${WRKDIR}/help ${PREFIX}/lib/irc/

.include <bsd.port.mk>
