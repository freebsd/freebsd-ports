# New ports collection makefile for:    tkirc
# Version required:     1.151
# Date created:         Jan 15 1998
# Whom:                 brianfeldman@hotmail.com
#
# $Id: Makefile,v 1.4 1998/03/07 15:38:45 hoek Exp $
#

DISTNAME=	tkirc1.202
PKGNAME=	tkirc-1.202
CATEGORIES=	net tk80
MASTER_SITES=	ftp://ftp.informatik.uni-oldenburg.de/pub/tkirc/

MAINTAINER=	brianfeldman@hotmail.com

RUN_DEPENDS=	irc:${PORTSDIR}/net/ircII \
		wish8.0:${PORTSDIR}/x11/tk80

WRKSRC=		${WRKDIR}/tkirc
NO_BUILD=	yes

post-patch:
	perl -pi.orig -e 's/wish/wish8.0/' ${WRKSRC}/tkirc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkirc	  ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/tkircrc-example ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/README	  ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/CHANGES	  ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/COPYING	  ${PREFIX}/share/doc/tkirc

.include <bsd.port.mk>
