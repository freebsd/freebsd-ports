# New ports collection makefile for:    roxirc
# Version required:     1.2
# Date created:         Mar 15 1999
# Whom:                 rox@fearme.com
#
# $Id$
#

DISTNAME=	roxirc-1.2
CATEGORIES=	net tk80
MASTER_SITES=	http://w3.lighter.net/roxirc/download/

MAINTAINER=	rox@fearme.com

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

WRKSRC=		${WRKDIR}/roxirc-1.2
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/roxirc	  ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/roxirc
	${INSTALL_DATA} ${WRKSRC}/config ${PREFIX}/share/doc/roxirc/config-example
	${INSTALL_DATA} ${WRKSRC}/menus ${PREFIX}/share/doc/roxirc/menus-example
	${INSTALL_DATA} ${WRKSRC}/prefs ${PREFIX}/share/doc/roxirc/prefs-intial

post-patch:
	/usr/bin/perl -pi -e 's,/usr/local,${PREFIX},g' ${WRKSRC}/roxirc

.include <bsd.port.mk>
