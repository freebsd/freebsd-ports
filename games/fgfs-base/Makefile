# New ports collection makefile for:	flightgear
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=	fgfs-base
PORTVERSION=	0.9.9
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.flightgear.org/pub/fgfs/Shared/ \
		ftp://ftp.de.flightgear.org/pub/fgfs/Shared/

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	FlightGear scenery, textures and aircraft models

PREFIX?=	${X11BASE}	# USE_X_PREFIX would pull in USE_XLIB
NO_BUILD=	yes
USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/data
DATADIR=	${PREFIX}/share/FlightGear

PLIST=		${WRKDIR}/pkg-plist
PLIST_DIRS=	%%DATADIR%%

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && \
	${FIND} * -type f | ${SORT} \
		| ${SED} -e 's|^|%%DATADIR%%/|' >> ${PLIST} && \
	${FIND} * -type d | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm %%DATADIR%%/|' >> ${PLIST}

do-install:
	cd ${WRKSRC} && \
	${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

.include <bsd.port.mk>
