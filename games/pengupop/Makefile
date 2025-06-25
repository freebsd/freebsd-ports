PORTNAME=	pengupop
PORTVERSION=	2.2.6
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.junoplay.com/files/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Online multiplayer clone of Bust a Move
WWW=		https://www.junoplay.com/pengupop

GNU_CONFIGURE=	yes
USES=		gmake sdl
USE_SDL=	sdl
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

PLIST_FILES=	bin/pengupop

.include <bsd.port.mk>
