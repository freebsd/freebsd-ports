# New ports collection makefile for:    netrek
# Version required:     BRMH 2.2p2
# Date created:         15 Mar 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	BRMH-2.2p2.freebsd.bin
PKGNAME=	netrek-BRMH-2.2p2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.solace.mh.se/pub/netrek/clients/bsd/
EXTRACT_SUFX=	.gz

MAINTAINER=	dburr@FreeBSD.org

USE_X_PREFIX=		YES
NO_BUILD=		YES
NO_WRKSUBDIR=		YES

do-extract:
	${MKDIR} ${WRKDIR}
	${GUNZIP_CMD} < ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKDIR}/netrek

do-install:
	${INSTALL} -c -o root -g wheel -m 555 ${WRKDIR}/netrek ${PREFIX}/bin
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
