# New ports collection makefile for:	flightgear
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=	fgfs-base
PORTVERSION=	1.0.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Shared/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Shared/

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	FlightGear scenery, textures and aircraft models

NO_BUILD=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/data
DATADIR=	${PREFIX}/share/FlightGear

PLIST=		${WRKDIR}/pkg-plist
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${RM} -f ${WRKSRC}/COPYING ${WRKSRC}/Aircraft/A-10/COPYING ${WRKSRC}/Aircraft/787/COPYING

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} * -type d -empty | ${SORT} \
		| ${SED} -e 's|^|@exec ${MKDIR} %%DATADIR%%/|' >> ${PLIST} && \
	${FIND} * -type f | ${SORT} \
		| ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
	${FIND} * -type d | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${DATADIR})

.include <bsd.port.mk>
