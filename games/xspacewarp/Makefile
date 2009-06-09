# New ports collection makefile for:	xspacewarp
# Date created:				16 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xspacewarp
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time Trek - like game for X Window System

USE_IMAKE=	yes
USE_XORG=	x11 xaw xext xmu xt xpm sm ice
NO_INSTALL_MANPAGES=	yes

post-extract:
	@${CP} ${WRKSRC}/XSpacewarp.app_def ${WRKSRC}/XSpacewarp.ad

.include <bsd.port.mk>
