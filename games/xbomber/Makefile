# New ports collection makefile for:   xbomber
# Version required:    0.8
# Date created:        28 June 1998
# Whom:                marcus
#
# $Id$
#

DISTNAME=       xbomber.0.8
PKGNAME=	xbomber-0.8
CATEGORIES=     games
MASTER_SITES=   ftp://ftp.sonic.net/pub/users/nbs/unix/x/xbomber/

MAINTAINER=     jclarke@cisco.com

WRKSRC=         ${WRKDIR}/xbomber
MAKEFILE=	makefile

post-install:
	${MKDIR} ${PREFIX}/bin; \
	${ECHO} "#!/bin/sh" > ${PREFIX}/bin/xbomber; \
	${ECHO} "cd ${PREFIX}/lib/xbomber" >> ${PREFIX}/bin/xbomber; \
	${CAT} ${SCRIPTDIR}/xbomber.sh >> ${PREFIX}/bin/xbomber; \
	chmod 0755 ${PREFIX}/bin/xbomber

.include <bsd.port.mk>
