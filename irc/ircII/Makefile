# New ports collection makefile for:	IrcII Client
# Version required:	2.9
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $Id: Makefile,v 1.12 1996/10/28 07:32:37 dima Exp $
#

DISTNAME=	ircii-2.9-roof
PKGNAME=	ircii-2.9
CATEGORIES=	net
MASTER_SITES=	ftp://cs-ftp.bu.edu/irc/clients/

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	yes

CONFIGURE_ARGS= --with-default-server="irc.FreeBSD.ORG"

WRKSRC=		${WRKDIR}/${PKGNAME}
MAN1=		ircII.1 ircbug.1

.include <bsd.port.mk>
