# New ports collection makefile for:	xboing
# Date created:		31 January 1995
# Whom:			janek
#
# $FreeBSD$

PORTNAME=	xboing
PORTVERSION=	2.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	janek@gaja.ipan.lublin.pl

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

.if ${MACHINE_ARCH} == "alpha"
PLIST=		${PKGDIR}/PLIST.alpha
.endif

USE_IMAKE=	yes
WRKSRC= ${WRKDIR}/xboing
MAN1=		xboing.1

.include <bsd.port.mk>
