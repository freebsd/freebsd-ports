# New ports collection makefile for:	xboing
# Version required:	2.4
# Date created:		31 January 1995
# Whom:			janek
#
# $Id: Makefile,v 1.11 1998/09/17 00:32:35 asami Exp $

DISTNAME=	xboing2.4
PKGNAME=	xboing-2.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=	janek@gaja.ipan.lublin.pl

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

.if ${MACHINE_ARCH} == "alpha"
PLIST=		${PKGDIR}/PLIST.alpha
.endif

USE_IMAKE=	yes
WRKSRC= ${WRKDIR}/xboing
MAN1=		xboing.1

.include <bsd.port.mk>
