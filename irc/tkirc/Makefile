# New ports collection makefile for:    tkirc
# Date created:         Jan 15 1998
# Whom:                 brianfeldman@hotmail.com
#
# $FreeBSD$
#

PORTNAME=	tkirc
PORTVERSION=	2.43
CATEGORIES=	irc tk83
MASTER_SITES=	ftp://ftp.netsplit.de/pub/tcltk/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	green@FreeBSD.org
COMMENT=	A GUI for the ircII Internet Relay Chat client

RUN_DEPENDS=	irc:${PORTSDIR}/irc/ircII \
		wish8.3:${PORTSDIR}/x11-toolkits/tk83

WRKSRC=		${WRKDIR}/tkirc2
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkirc2 ${PREFIX}/bin
	${LN} -f ${PREFIX}/bin/tkirc2 ${PREFIX}/bin/tkirc
	${MKDIR} ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tkirc
	${MKDIR} ${PREFIX}/share/doc/tkirc/examples
	${TAR} cf - -C ${WRKSRC} .tkirc2 | \
	    ${TAR} xf - -C ${PREFIX}/share/doc/tkirc/examples

.include <bsd.port.mk>
