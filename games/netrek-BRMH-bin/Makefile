# New ports collection makefile for:    netrek
# Date created:         15 Mar 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	netrek-BRMH
PORTVERSION=	2.2.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.solace.mh.se/pub/netrek/clients/bsd/
DISTNAME=	BRMH-2.2p2.freebsd.bin
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 16-player network space battle/conquest game with a Star Trek theme

USE_X_PREFIX=		YES
NO_BUILD=		YES
NO_WRKSUBDIR=		YES
PLIST_FILES=	bin/netrek

do-extract:
	${MKDIR} ${WRKDIR}
	${GUNZIP_CMD} < ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKDIR}/netrek

do-install:
	${INSTALL} -c -o root -g wheel -m 555 ${WRKDIR}/netrek ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
