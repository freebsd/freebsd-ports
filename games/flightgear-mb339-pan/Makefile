# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>

PORTNAME=	flightgear-mb339-pan
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://hcilab.uniud.it/pan/downloads/
DISTNAME=	mb339pan_${PORTVERSION}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Simulation of the MB-339 PAN aerobatic jet

# Converted from RESTRICTED
LICENSE=	mb339
LICENSE_NAME=	mb339
LICENSE_TEXT=	Redistribution prohibited
LICENSE_PERMS=	auto-accept

RUN_DEPENDS=	${LOCALBASE}/share/flightgear/version:games/flightgear-data

NO_BUILD=	yes
USES=		zip
WRKSRC=	${WRKDIR}/${PORTNAME}
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
DATADIR=	${PREFIX}/share/flightgear/Aircraft

PLIST=		${WRKDIR}/pkg-plist
PLIST_DIRS=	%%DATADIR%%

pre-extract:
	@${MKDIR} ${WRKSRC}

pre-install:
	@${RM} ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} * -type d -empty | ${SORT} \
		| ${SED} -e 's|^|@exec ${MKDIR} %D/share/flightgear/Aircraft/|' >> ${PLIST} && \
	${FIND} * -type f | ${SORT} \
		| ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
	${FIND} * -type d -empty | ${SORT} -r \
		| ${SED} -e 's|^|@dir %%DATADIR%%/|' >> ${PLIST}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
