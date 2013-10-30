# Created by: Brian Buchanan <brian@CSUA.Berkeley.EDU>
# $FreeBSD$

PORTNAME=	flightgear-data
PORTVERSION=	2.12.0
CATEGORIES=	games
# see http://www.flightgear.org/templates.js
MASTER_SITES=	http://mirrors.ibiblio.org/pub/mirrors/flightgear/ftp/Shared/ \
		http://ftp.linux.kiev.ua/pub/mirrors/ftp.flightgear.org/flightgear/Shared/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Shared/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Shared/ \
		ftp://flightgear.wo0t.de/flightgear-ftp/ftp/Shared/
DISTNAME=	FlightGear-data-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	FlightGear scenery, textures, and aircraft models

LICENSE=	GPLv2

NO_BUILD=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/fgdata
DATADIR=	${PREFIX}/share/flightgear

PLIST=		${WRKDIR}/pkg-plist
PLIST_DIRS=	%%DATADIR%%

MANUAL_PACKAGE_BUILD=	very large distfile (>900 MB)

post-patch:
	@${RM} -f ${WRKSRC}/COPYING

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} * -type d -empty | ${SORT} \
		| ${SED} -e 's|^|@exec ${MKDIR} %D/share/flightgear/|' >> ${PLIST} && \
	${FIND} * -type f | ${SORT} \
		| ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
	${FIND} * -type d | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
