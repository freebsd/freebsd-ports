# New ports collection makefile for:   cmp3
# Version required:    2.0pre3
# Date created:        10 April 1999
# Whom:                Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	cmp3-2.0pre3
PKGNAME=	cmp3-2.0p3
CATEGORIES=	audio
MASTER_SITES=	http://www.personal.psu.edu/users/n/k/nkk104/cmp3/

MAINTAINER=	cpiazza@FreeBSD.org

RUN_DEPENDS= 	mpg123:${PORTSDIR}/audio/mpg123

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/cmp3
PKGMESSAGE=	${WRKSRC}/MESSAGE

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
