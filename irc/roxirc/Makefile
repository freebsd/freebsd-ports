# New ports collection makefile for:    roxirc
# Date created:         Mar 15 1999
# Whom:                 rox@fearme.com
#
# $FreeBSD$
#

PORTNAME=	roxirc
PORTVERSION=	1.72
CATEGORIES=	irc tk83
MASTER_SITES=	http://roxirc.lighter.net/download/

MAINTAINER=	rox@fearme.com
COMMENT=	A tcl/tk irc client

RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/roxirc	  ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/roxirc
	${INSTALL_DATA} ${WRKSRC}/config ${PREFIX}/share/doc/roxirc/config-example
	${INSTALL_DATA} ${WRKSRC}/menus ${PREFIX}/share/doc/roxirc/menus-example
	${INSTALL_DATA} ${WRKSRC}/bindings ${PREFIX}/share/doc/roxirc/bindings-example
	${INSTALL_DATA} ${WRKSRC}/prefs ${PREFIX}/share/doc/roxirc/prefs-initial
	${INSTALL_DATA} ${WRKSRC}/startup ${PREFIX}/share/doc/roxirc/startup-example
	${INSTALL_DATA} ${WRKSRC}/help ${PREFIX}/share/doc/roxirc/help

.include <bsd.port.mk>
