# New ports collection makefile for:	ezbounce
# Version required: 	0.85.2
# Date created:	 	19 February 1999
# Whom:			Chris Piazza <cpiazza@FreeBSD.org>
#
# $Id: Makefile,v 1.3 1999/05/25 10:08:17 mharo Exp $
#

DISTNAME=	ezbounce-0.85.2
CATEGORIES=	net
MASTER_SITES=  	http://druglord.freelsd.org/ezbounce/ \
		http://irc.themes.org/downloads/misc/

MAINTAINER=	cpiazza@FreeBSD.org

GNU_CONFIGURE= 	yes

do-install:
	@ ${ECHO} ------------------------------------------------------------------
	@ ${ECHO} You will need to read http://druglord.freelsd.org/ezbounce/README
	@ ${ECHO} and http://druglord.freelsd.org/ezbounce/mdidentd.README
	@ ${ECHO} to set up this program.
	@ ${ECHO} Also, edit ${PREFIX}/etc/ezbounce.conf to your liking.
	@ ${ECHO} ------------------------------------------------------------------
	${INSTALL_PROGRAM} -C ${WRKSRC}/ezbounce ${PREFIX}/sbin
	${INSTALL_PROGRAM} -C ${WRKSRC}/mdidentd/mdidentd ${PREFIX}/sbin
	@ ${SED} -e s:/path/to:${PREFIX}/sbin: ${WRKSRC}/sample.conf > \
		${WRKSRC}/sample.conf.new
	if [ ! -f ${PREFIX}/etc/ezbounce.conf ]; then \
			${INSTALL_SCRIPT} -C ${WRKSRC}/sample.conf.new \
			${PREFIX}/etc/ezbounce.conf; \
		fi
	${INSTALL_SCRIPT} -C ${WRKSRC}/sample.conf.new \
		${PREFIX}/etc/ezbounce.conf.default

.include <bsd.port.mk>
