# New ports collection makefile for:    roxirc
# Date created:         Mar 15 1999
# Whom:                 rox@fearme.com
#
# $FreeBSD$
#

PORTNAME=	roxirc
PORTVERSION=	1.5
CATEGORIES=	irc tk82
MASTER_SITES=	http://roxirc.lighter.net/download/

MAINTAINER=	rox@fearme.com

RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/roxirc	  ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/roxirc
	${INSTALL_DATA} ${WRKSRC}/config ${PREFIX}/share/doc/roxirc/config-example
	${INSTALL_DATA} ${WRKSRC}/menus ${PREFIX}/share/doc/roxirc/menus-example
	${INSTALL_DATA} ${WRKSRC}/prefs ${PREFIX}/share/doc/roxirc/prefs-initial
	${INSTALL_DATA} ${WRKSRC}/help ${PREFIX}/share/doc/roxirc/help

post-patch:
	@${PERL} -pi -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/roxirc
	@${PERL} -pi -e 's,wish8.0,wish8.2,g' ${WRKSRC}/roxirc

.include <bsd.port.mk>
