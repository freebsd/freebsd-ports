# New ports collection makefile for:	nkf
# Version required:	1.6
# Date created:		5 February 1995
# Whom:			asami
#
# $Id: Makefile,v 1.11 1996/09/28 16:19:47 max Exp $
#

DISTNAME=	nkf-1.62
PKGNAME=	jp-nkf-1.62
CATEGORIES=	japanese
MASTER_SITES=	http://www.sfc.wide.ad.jp/~max/FreeBSD/ports/distfiles/

MAINTAINER=	max@FreeBSD.ORG

post-extract:
	@echo "===>  Installing custom Makefile for ${DISTNAME}"
	@(cp ${FILESDIR}/Makefile ${WRKSRC})

.include <bsd.port.mk>
