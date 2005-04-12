# New ports collection makefile for:	editss
# Date created:		14 November 2001
# Whom:			Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	editss
PORTVERSION=	2.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.xpilot.org/pub/contrib/

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	An editor for XPilot shipshapes

USE_IMAKE=	yes
ALL_TARGET=	editss
MAN6=		editss.6
NO_INSTALL_MANPAGES=	yes
XFREE86_HTML_MAN=	no
MAN_COMPRESSED=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/editss ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/editss
	${INSTALL_DATA} ${WRKSRC}/editssrc ${PREFIX}/share/editss
	${INSTALL_MAN} ${WRKSRC}/editss.6 ${MANPREFIX}/man/man6

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
