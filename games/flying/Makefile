PORTNAME=	flying
PORTVERSION=	6.20
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/arcade

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pool/snooker/billiards/carrom/etc game

USES=		compiler imake tar:tgz xorg
USE_XORG=	x11
PLIST_FILES=	bin/flying share/man/man1/flying.1.gz

# build ignores CXXFLAGS, imake gets in the way of fixing it
CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_clang=	-Wno-c++11-narrowing

.include <bsd.port.mk>
