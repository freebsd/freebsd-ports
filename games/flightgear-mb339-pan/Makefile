# New ports collection makefile for:	flightgear-mb339-pan
# Date created:				11 Dec 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flightgear-mb339-pan
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://hcilab.uniud.it/pan/downloads/
DISTNAME=	MB339-PAN

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simulation of the MB-339 PAN aerobatic jet

RUN_DEPENDS=	${LOCALBASE}/share/FlightGear/version:${PORTSDIR}/games/fgfs-base

BROKEN=		Size mismatch

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
RESTRICTED=	Redistribution prohibited
PLIST=		${WRKDIR}/.plist

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} * -type f | ${SORT} \
		| ${SED} -e 's|^|share/FlightGear/Aircraft/|' >> ${PLIST} && \
	${FIND} -d * -type d \
		| ${SED} -e 's|^|@dirrm share/FlightGear/Aircraft/|' >> ${PLIST}

do-install:
	cd ${WRKSRC} && \
	${FIND} * -type d -exec \
		${MKDIR} "${PREFIX}/share/FlightGear/Aircraft/{}" \; && \
	${FIND} * -type f -exec \
		${INSTALL_DATA} "{}" "${PREFIX}/share/FlightGear/Aircraft/{}" \;

.include <bsd.port.mk>
