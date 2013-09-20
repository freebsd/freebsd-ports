# Created by: Donald Burr <dburr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	netrek-BRMH
PORTVERSION=	2.2.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://ftp.netrek.org/pub/netrek/mirrors/ftp.csua.berkeley.edu.old/netrek/ \

DISTNAME=	BRMH-2.2p2.freebsd.bin
EXTRACT_SUFX=	.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A 16-player network space battle/conquest game with a Star Trek theme

NO_BUILD=		YES
NO_WRKSUBDIR=		YES
PLIST_FILES=	bin/netrek

NO_STAGE=	yes
do-extract:
	${MKDIR} ${WRKDIR}
	${GUNZIP_CMD} < ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} > ${WRKDIR}/netrek

do-install:
	${INSTALL} -c -o root -g wheel -m 555 ${WRKDIR}/netrek ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
