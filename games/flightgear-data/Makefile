# New ports collection makefile for:	flightgear
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=	FlightGear-data
PORTVERSION=	2.0.0
CATEGORIES=	games
# see http://www.flightgear.org/templates.js
MASTER_SITES=	ftp://ftp.de.flightgear.org/pub/fgfs/Shared/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Shared/ \
		ftp://ftp.linux.kiev.ua/pub/mirrors/ftp.flightgear.org/flightgear/Shared/ \
		http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Shared/ \
		http://ftp3.linux.kiev.ua/pub/fgfs/Shared/ \
		ftp://ftp.ibiblio.org/pub/mirrors/flightgear/ftp/Shared/ \
		ftp://ftp.flightgear.org/pub/fgfs/Shared/ \
		ftp://ftp.is.co.za/pub/games/flightgear/ftp/Shared/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	FlightGear scenery, textures and aircraft models

NO_BUILD=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/data
DATADIR=	${PREFIX}/share/FlightGear

PLIST=		${WRKDIR}/pkg-plist
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${RM} -f ${WRKSRC}/COPYING

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} * -type d -empty | ${SORT} \
		| ${SED} -e 's|^|@exec ${MKDIR} %D/share/FlightGear/|' >> ${PLIST} && \
	${FIND} * -type f | ${SORT} \
		| ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
	${FIND} * -type d | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${DATADIR})

.include <bsd.port.mk>
