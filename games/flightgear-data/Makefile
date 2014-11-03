# Created by: Brian Buchanan <brian@CSUA.Berkeley.EDU>
# $FreeBSD$

PORTNAME=	flightgear-data
PORTVERSION=	3.2.0
CATEGORIES=	games
# see http://www.flightgear.org/templates.js
MASTER_SITES=	http://mirrors.ibiblio.org/flightgear/ftp/Shared/ \
		http://ftp.linux.kiev.ua/pub/mirrors/ftp.flightgear.org/flightgear/Shared/ \
		ftp://ftp.kingmont.com/flightsims/flightgear/Shared/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Shared/ \
		ftp://flightgear.wo0t.de/flightgear-ftp/ftp/Shared/
DISTNAME=	FlightGear-data-${PORTVERSION}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	FlightGear scenery, textures, and aircraft models

LICENSE=	GPLv2

NO_BUILD=	yes
USES=		tar:bzip2
WRKSRC=		${WRKDIR}/fgdata
DATADIR=	${PREFIX}/share/flightgear

PLIST=		${WRKDIR}/pkg-plist
PLIST_DIRS=	%%DATADIR%%

MANUAL_PACKAGE_BUILD=	very large distfile (>1 GB)

post-patch:
	@${RM} -f ${WRKSRC}/COPYING

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} * -type d -empty | ${SORT} \
		| ${SED} -e 's|^|@exec ${MKDIR} %D/share/flightgear/|' >> ${PLIST} && \
	${FIND} * -type f | ${SORT} \
		| ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
	${FIND} * -type d -empty | ${SORT} -r \
		| ${SED} -e 's|^|@dir %%DATADIR%%/|' >> ${PLIST}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} '! -name .gitignore')

.include <bsd.port.mk>
