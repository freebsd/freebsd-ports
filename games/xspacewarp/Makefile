# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	xspacewarp
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time Trek - like game for X Window System

USES=		imake:noman xorg
USE_XORG=	x11 xaw xext xmu xt xpm sm ice

PLIST_FILES=	bin/xspacewarp \
		lib/X11/app-defaults/XSpacewarp

post-extract:
	@${LN} -sf XSpacewarp.app_def ${WRKSRC}/XSpacewarp.ad

post-patch:
	@${FIND} ${WRKSRC} -name "*.cc" -or -name "*.hh" | ${XARGS} \
		${REINPLACE_CMD} -e \
		's|<iostream.h>|<iostream>| ; \
		 s| cerr| std::cerr| ; \
		 s| cout| std::cout| ; \
		 s| endl| std::endl|'

.include <bsd.port.mk>
