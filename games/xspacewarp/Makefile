# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xspacewarp
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time Trek - like game for X Window System

USES=		imake
USE_XORG=	x11 xaw xext xmu xt xpm sm ice
NO_INSTALL_MANPAGES=	yes

PLIST_FILES=	bin/xspacewarp \
		lib/X11/app-defaults/XSpacewarp

post-extract:
	@${CP} ${WRKSRC}/XSpacewarp.app_def ${WRKSRC}/XSpacewarp.ad

.include <bsd.port.mk>
