# New ports collection makefile for:	luna
# Version required:	1.9
# Date created:		03 July 1996
# Whom:			ABURAYER Rewsirow <rewsirow@ff.iij4u.or.jp>
#
# $Id: Makefile,v 1.2 1996/11/15 22:34:47 obrien Exp $
#

DISTNAME=	luna19
PKGNAME=	luna-1.9
CATEGORIES=	astro games
MASTER_SITES=	ftp://ftp.ae.keio.ac.jp/pub/msdos/utils/
EXTRACT_SUFX=	.lzh

MAINTAINER=	rewsirow@ff.iij4u.or.jp

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	xfw=${WRKDIR}
PATCH_STRIP=	-p1

post-extract:
	@echo "===>  Removing object files for ${DISTNAME}"
	@(cd ${WRKDIR}/luna19/iprintf; rm -fr *.o)

.include <bsd.port.mk>
