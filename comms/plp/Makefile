# New ports collection makefile for:	Psion Link Protocol
# Version required:			1.8
# Date created:				Tue Nov 30 15:43:27 EST 1999
# Whom:					Maurice Castro <maurice@serc.rmit.edu.au>
#
# $FreeBSD$
#

DISTNAME=	plp_1_8
PKGNAME=	plp-1.8
CATEGORIES=	comms
MASTER_SITES=	http://www.proudman51.freeserve.co.uk/psion/ \
		http://people.FreeBSD.org/~kris/distfiles/

MAINTAINER=	maurice@serc.rmit.edu.au

USE_GMAKE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ncp ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/rfsv ${PREFIX}/bin

.include <bsd.port.mk>
