# New ports collection makefile for:    tkirc
# Date created:         Jan 15 1998
# Whom:                 brianfeldman@hotmail.com
#
# $FreeBSD$
#

PORTNAME=	tkirc
PORTVERSION=	1.202
CATEGORIES=	irc tk82
MASTER_SITES=	ftp://ftp.informatik.uni-oldenburg.de/pub/tkirc/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	green@FreeBSD.org

RUN_DEPENDS=	irc:${PORTSDIR}/irc/ircII \
		wish8.2:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/tkirc
NO_BUILD=	yes

post-patch:
	perl -pi.orig -e 's/wish/wish8.2/' ${WRKSRC}/tkirc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkirc	  ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/tkircrc-example ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/README	  ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/CHANGES	  ${PREFIX}/share/doc/tkirc
	${INSTALL_DATA} ${WRKSRC}/COPYING	  ${PREFIX}/share/doc/tkirc

.include <bsd.port.mk>
