# New ports collection makefile for:	uudx
# Version required:	2.99
# Date created:		2 June 1996
# Whom:			ABURAYER Rewsirow <pcs51674@asciinet.or.jp>
#
#
#

DISTNAME=	uudx_299
PKGNAME=	uudx-2.99
CATEGORIES+=	archivers
MASTER_SITES=	ftp://ftp.ae.keio.ac.jp/pub/msdos/archivers/uu/

MAINTAINER=	pcs51674@asciinet.or.jp

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha

EXTRACT_CMD=	lha
EXTRACT_SUFX=	.lzh
EXTRACT_BEFORE_ARGS=	xw=${WRKDIR}
NO_WRKSUBDIR=	yes
PATCH_STRIP=	-p1

pre-patch:
	@echo "===>  Installing custom Makefile for ${DISTNAME}"
	@(cp ${FILESDIR}/Makefile ${WRKSRC})

.include <bsd.port.mk>
