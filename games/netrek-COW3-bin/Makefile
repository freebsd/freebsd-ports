# New ports collection makefile for:    netrek
# Version required:     COW 3.00pl0
# Date created:         15 Mar 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	COW.3.00pl0.FreeBSD
PKGNAME=	netrek-COW-3.00p0
CATEGORIES=	games
MASTER_SITES=	ftp://bigbang.astro.indiana.edu/pub/netrek/COW/COW-bin/
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
