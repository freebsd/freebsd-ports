# New ports collection makefile for:	luna
# Version required:	1.9
# Date created:		03 July 1996
# Whom:			ABURAYER Rewsirow <pcs51674@asciinet.or.jp>
#
# $Id: Makefile,v 1.1.1.1 1996/10/24 08:53:50 asami Exp $
#

DISTNAME=	luna19
PKGNAME=	luna-1.9
CATEGORIES=	astro games
MASTER_SITES=	ftp://ftp.nc.nihon-u.ac.jp/pub/MSDOS/games/

MAINTAINER=	pcs51674@asciinet.or.jp

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha

EXTRACT_CMD=	lha
EXTRACT_SUFX=	.lzh
EXTRACT_BEFORE_ARGS=	xfw=${WRKDIR}
PATCH_STRIP=	-p1

post-extract:
	@echo "===>  Removing object files for ${DISTNAME}"
	@(cd ${WRKDIR}/luna19/iprintf; rm -fr *.o)

.include <bsd.port.mk>
