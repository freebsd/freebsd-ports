# New ports collection makefile for:	IrcII Client
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	ircii
PORTVERSION=	20011210
CATEGORIES=	irc ipv6
MASTER_SITES=	ftp://ftp.warped.com/pub/ircII/ \
		ftp://ircftp.au.eterna.com.au/pub/ircII/ \
		ftp://ftp.plig.net/pub/ircII/

MAINTAINER=	anders@hack.org

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	IRCLIB=${PREFIX}/share/irc

USE_BZIP2=	yes

MAN1=		ircII.1 ircbug.1

PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.mk>
