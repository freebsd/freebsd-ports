# New ports collection makefile for:	IrcII Client
# Version required:	2.8
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.3 1995/04/01 12:48:07 jkh Exp $
#

DISTNAME=	ircii-2.8
CATEGORIES+=	networking
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/clients/
DISTFILES=	ircii-2.8.tar.gz ircii-2.8help.tar.gz

GNU_CONFIGURE=	yes

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib/irc/script
	@mkdir -p ${PREFIX}/lib/irc/translation
	@cp -R ${WRKDIR}/help ${PREFIX}/lib/irc/

.include <bsd.port.mk>
