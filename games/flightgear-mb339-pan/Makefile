# New ports collection makefile for:	flightgear-mb339-pan
# Date created:				11 Dec 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flightgear-mb339-pan
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://hcilab.uniud.it/pan/downloads/
DISTNAME=	mb339pan

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	A simulation of the MB-339 PAN aerobatic jet

RUN_DEPENDS=	${LOCALBASE}/share/FlightGear/version:${PORTSDIR}/games/flightgear-data

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
RESTRICTED=	Redistribution prohibited
PLIST=		${WRKDIR}/.pkg-plist

post-patch:
	@${MV} ${WRKSRC}/${DISTNAME}/engines ${WRKDIR}/${DISTNAME}/Engines

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} * -type d -empty | ${SORT} \
		| ${SED} -e 's|^|@exec ${MKDIR} share/FlightGear/Aircraft/|' >> ${PLIST} && \
	${FIND} * -type f | ${SORT} \
		| ${SED} -e 's|^|share/FlightGear/Aircraft/|' >> ${PLIST} && \
	${FIND} * -type d | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm share/FlightGear/Aircraft/|' >> ${PLIST}

do-install:
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} \* ${PREFIX}/share/FlightGear/Aircraft/)

.include <bsd.port.mk>
