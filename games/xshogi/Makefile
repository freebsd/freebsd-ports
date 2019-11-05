# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	xshogi
PORTVERSION=	1.4.2
CATEGORIES=	games
MASTER_SITES=	GNU/gnushogi

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese chess-like game for X Window System

RUN_DEPENDS=	gnushogi:games/gnushogi

USES=		xorg
USE_XORG=	xt xaw x11
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include

PORTDOCS=	README.xboard BUGS
PLIST_FILES=	bin/xshogi man/man6/xshogi.6.gz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
