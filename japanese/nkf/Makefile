# New ports collection makefile for:	nkf
# Version required:	1.6
# Date created:		5 February 1995
# Whom:			asami
#
# $Id: Makefile,v 1.9 1996/09/17 15:07:40 max Exp $
#

DISTNAME=	nkf-1.6
PKGNAME=	jp-nkf-1.6
CATEGORIES+=	japanese
MASTER_SITES=	http://www.sfc.wide.ad.jp/~max/FreeBSD/ports/distfiles/

MAINTAINER=	max@FreeBSD.ORG

pre-patch:
	@echo "===>  Installing custom Makefile for ${DISTNAME}"
	@(cp ${FILESDIR}/Makefile ${WRKSRC})

.include <bsd.port.mk>
