# New ports collection makefile for:	flightgear-mb339-pan
# Date created:				11 Dec 2005
# Whom:					Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flightgear-mb339-pan
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	http://hcilab.uniud.it/pan/downloads/
DISTNAME=	MB339-PAN

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A simulation of the MB-339 PAN aerobatic jet

RUN_DEPENDS=	${X11BASE}/share/FlightGear/version:${PORTSDIR}/games/fgfs-base

PREFIX?=	${X11BASE}	# USE_X_PREFIX would pull in USE_XLIB
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
RESTRICTED=	"Redistribution prohibited"
PLIST=		${WRKDIR}/.plist

IGNORE=		is incompatible with the latest FlightGear release

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
