PORTNAME=	xshogi
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	GNU/gnushogi

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese chess-like game for X Window System

RUN_DEPENDS=	gnushogi:games/gnushogi

USES=		xorg
USE_XORG=	xt xaw x11
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CPPFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	README.xboard BUGS
PLIST_FILES=	bin/xshogi share/man/man6/xshogi.6.gz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
