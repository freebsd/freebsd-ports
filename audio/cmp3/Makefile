# New ports collection makefile for:   cmp3
# Version required:    2.0pre3
# Date created:        10 April 1999
# Whom:                Chris Piazza <cpiazza@home.net>
#
# $Id$
#

DISTNAME=	cmp3-2.0pre3
PKGNAME=	cmp3-2.0p3
CATEGORIES=	audio
MASTER_SITES=	http://nkk104.rh.psu.edu/cmp3/

MAINTAINER=	cpiazza@home.net

RUN_DEPENDS= 	mpg123:${PORTSDIR}/audio/mpg123

USE_GMAKE=	yes

WRKSRC=	${WRKDIR}/cmp3

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmp3 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rnmp3 ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cmp3
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cmp3
.endif

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
