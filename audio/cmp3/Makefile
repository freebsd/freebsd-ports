# New ports collection makefile for:   cmp3
# Version required:    2.0pre3
# Date created:        10 April 1999
# Whom:                Chris Piazza <cpiazza@home.net>
#
# $Id: Makefile,v 1.1.1.1 1999/04/13 23:26:27 mharo Exp $
#

DISTNAME=	cmp3-2.0pre3
PKGNAME=	cmp3-2.0p3
CATEGORIES=	audio
MASTER_SITES=	http://nkk104.rh.psu.edu/cmp3/

MAINTAINER=	cpiazza@home.net

RUN_DEPENDS= 	mpg123:${PORTSDIR}/audio/mpg123

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/cmp3
PKGMESSAGE=	${WRKSRC}/MESSAGE
.if defined(NOPORTDOCS)
PLIST=		${PKGDIR}/PLIST.nodocs
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cmp3 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rnmp3 ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/cmp3
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cmp3
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${SED} 's,PREFIX,${PREFIX},' ${PKGDIR}/MESSAGE > ${WRKSRC}/MESSAGE
	@${CAT} ${WRKSRC}/MESSAGE
.endif

.include <bsd.port.mk>
