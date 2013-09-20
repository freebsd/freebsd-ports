# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flightgear-mb339-pan
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://hcilab.uniud.it/pan/downloads/
DISTNAME=	mb339pan_${PORTVERSION}

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A simulation of the MB-339 PAN aerobatic jet

RUN_DEPENDS=	${LOCALBASE}/share/flightgear/version:${PORTSDIR}/games/flightgear-data

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
RESTRICTED=	Redistribution prohibited
PLIST=		${WRKDIR}/.pkg-plist

NO_STAGE=	yes
pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} * -type d -empty | ${SORT} \
		| ${SED} -e 's|^|@exec ${MKDIR} share/flightgear/Aircraft/|' >> ${PLIST} && \
	${FIND} * -type f | ${SORT} \
		| ${SED} -e 's|^|share/flightgear/Aircraft/|' >> ${PLIST} && \
	${FIND} * -type d | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm share/flightgear/Aircraft/|' >> ${PLIST}

do-install:
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${PREFIX}/share/flightgear/Aircraft/)

.include <bsd.port.mk>
