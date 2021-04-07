PORTNAME=	pengupop
PORTVERSION=	2.2.6
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.junoplay.com/files/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Online multiplayer clone of Bust a Move

GNU_CONFIGURE=	yes
USES=		gmake sdl
USE_SDL=	sdl
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

PLIST_FILES=	bin/pengupop

.include <bsd.port.mk>
