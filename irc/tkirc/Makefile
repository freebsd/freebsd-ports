# New ports collection makefile for:    tkirc
# Version required:     1.151
# Date created:         Jan 15 1998
# Whom:                 brianfeldman@hotmail.com
#
# $Id: Makefile,v 1.2 1998/01/18 11:13:54 asami Exp $
#

DISTNAME=	tkirc-1.151
CATEGORIES=	net x11 tk80
MASTER_SITES=	ftp://ftp.informatik.uni-oldenburg.de/pub/tkirc/
DISTFILES=	tkirc1.151.tar.gz

MAINTAINER=	brianfeldman@hotmail.com

RUN_DEPENDS=	irc:${PORTSDIR}/net/ircII \
		wish8.0:${PORTSDIR}/x11/tk80

WRKSRC=		${WRKDIR}/tkirc
NO_BUILD=	yes
STRIP=

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tkirc	  ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/tkircrc-example ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/README	  ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/CHANGES	  ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/COPYING	  ${PREFIX}/share/doc/tkirc

.include <bsd.port.mk>
