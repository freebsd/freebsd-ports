# New ports collection makefile for:	uudx
# Version required:	2.99
# Date created:		2 June 1996
# Whom:			ABURAYER Rewsirow <pcs51674@asciinet.or.jp>
#
# $Id: Makefile,v 1.4 1997/04/26 23:55:24 asami Exp $
#

DISTNAME=	uudx_299
PKGNAME=	uudx-2.99
CATEGORIES=	converters
MASTER_SITES=	ftp://ftp.ae.keio.ac.jp/pub/msdos/archivers/uu/
EXTRACT_SUFX=	.lzh

MAINTAINER=	rewsirow@ff.iij4u.or.jp

BUILD_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		nkf:${PORTSDIR}/japanese/nkf

EXTRACT_CMD=	lha
EXTRACT_BEFORE_ARGS=	xw=${WRKDIR}
NO_WRKSUBDIR=	yes
MANLANG=	ja_JP.EUC
MAN1=		uudx.1

pre-patch:
	@echo "===>  Installing custom Makefile for ${DISTNAME}"
	@(${CP} ${FILESDIR}/Makefile ${WRKSRC})

.include <bsd.port.mk>
