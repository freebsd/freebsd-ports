# New ports collection makefile for:	nkf
# Version required:	1.6
# Date created:		5 February 1995
# Whom:			asami
#
# $Id: Makefile,v 1.6 1995/04/20 18:05:40 asami Exp $
#

DISTNAME=	nkf-1.6
CATEGORIES+=	japanese
MASTER_SITES=	http://www.sfc.wide.ad.jp/~max/FreeBSD/ports/distfiles/

MAINTAINER=	asami@FreeBSD.ORG

pre-patch:
	@echo "===>  Installing custom Makefile for ${DISTNAME}"
	@(cp ${FILESDIR}/Makefile ${WRKSRC})

.include <bsd.port.mk>
