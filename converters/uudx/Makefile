# New ports collection makefile for:	uudx
# Version required:	2.99
# Date created:		2 June 1996
# Whom:			ABURAYER Rewsirow <pcs51674@asciinet.or.jp>
#
# $Id: Makefile,v 1.7 1998/04/05 04:46:02 max Exp $
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
EXTRACT_BEFORE_ARGS=	xqw=${WRKDIR}
EXTRACT_AFTER_ARGS=	# empty
NO_WRKSUBDIR=	yes
MANLANG=	ja
MAN1=		uudx.1

pre-patch:
	@${ECHO_MSG} "===>  Installing custom Makefile for ${DISTNAME}"
	@(${CP} ${FILESDIR}/Makefile ${WRKSRC})

.include <bsd.port.mk>
