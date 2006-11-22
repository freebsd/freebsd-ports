# New ports collection makefile for:	IrcII Client
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	ircii
PORTVERSION=	20060725
CATEGORIES=	irc ipv6
MASTER_SITES=	ftp://ftp.warped.com/pub/ircII/ \
		ftp://ftp.irc.org/irc/clients/unix/ircII/

MAINTAINER=	sylvioc@gmail.com
COMMENT=	The 'Internet Relay Chat' and 'Internet Citizens Band' Client

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	IRCLIB=${PREFIX}/share/irc

USE_BZIP2=	yes

MAN1=		irc.1 ircII.1 ircbug.1

PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" && ${OSVERSION} >= 700000
BROKEN=	Doesn't build
.endif

.include <bsd.port.post.mk>
