# Created by: torstenb
# $FreeBSD$

PORTNAME=	ircii
PORTVERSION=	20111115
CATEGORIES=	irc ipv6
MASTER_SITES=	http://ircii.warped.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The 'Internet Relay Chat' and 'Internet Citizens Band' Client

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	IRCLIB=${PREFIX}/share/irc
USE_AUTOTOOLS=	autoconf213 autoheader213

USES=		tar:bzip2

PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.mk>
