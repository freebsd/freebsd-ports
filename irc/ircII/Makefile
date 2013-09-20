# Created by: torstenb
# $FreeBSD$

PORTNAME=	ircii
PORTVERSION=	20111115
CATEGORIES=	irc ipv6
MASTER_SITES=	http://ircii.warped.com/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	The 'Internet Relay Chat' and 'Internet Citizens Band' Client

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	IRCLIB=${PREFIX}/share/irc

USE_BZIP2=	yes

MAN1=		irc.1 ircII.1 ircbug.1

PLIST_SUB=	VERSION="${PORTVERSION}"

NO_STAGE=	yes
.include <bsd.port.mk>
