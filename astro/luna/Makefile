# New ports collection makefile for:	luna
# Version required:	1.9
# Date created:		03 July 1996
# Whom:			ABURAYER Rewsirow <rewsirow@ff.iij4u.or.jp>
#
# $Id: Makefile,v 1.4 1998/09/26 23:24:34 steve Exp $
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
EXTRACT_AFTER_ARGS=	# empty
PATCH_STRIP=	-p1

post-extract:
	@echo "===>  Removing object files for ${DISTNAME}"
	@(cd ${WRKDIR}/luna19/iprintf; ${RM} -fr *.o)

.include <bsd.port.mk>
