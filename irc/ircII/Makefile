# New ports collection makefile for:	IrcII Client
# Version required:	4.4S
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

DISTNAME=	ircii-4.4S
CATEGORIES=	irc ipv6
MASTER_SITES=	ftp://ircftp.au.eterna.com.au/pub/ircII/

MAINTAINER=	torstenb@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	IRCLIB=${PREFIX}/share/irc

USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/${PKGNAME}
MAN1=		ircII.1 ircbug.1

.include <bsd.port.mk>
