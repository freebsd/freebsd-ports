# New ports collection makefile for:	nkf
# Version required:	1.6
# Date created:		5 February 1995
# Whom:			asami
#
# $FreeBSD$
#

DISTNAME=	nkf-1.62
PKGNAME=	ja-nkf-1.62
CATEGORIES=	japanese
MASTER_SITES=	http://www.sfc.wide.ad.jp/~max/FreeBSD/ports/distfiles/

MAINTAINER=	max@FreeBSD.org

MAN1=		nkf.1

post-extract:
	@${ECHO} "===>  Installing custom Makefile for ${DISTNAME}"
	@(${CP} ${FILESDIR}/Makefile ${WRKSRC})

.include <bsd.port.mk>
