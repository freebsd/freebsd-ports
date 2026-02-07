PORTNAME=	bitefusion
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://www.junoplay.com/files/ \
		https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Snake game with 8 levels
WWW=		https://www.junoplay.com/

GNU_CONFIGURE=	yes
USES=		gmake sdl
USE_SDL=	sdl
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

PLIST_FILES=	bin/bitefusion

DESKTOP_ENTRIES="Bitefusion" \
		"${COMMENT}" \
		"" \
		"${PORTNAME}" \
		"Game;ArcadeGame;" \
		""

post-patch:
	@${REINPLACE_CMD} -e 's|-linux-gnu|-portbld-${OPSYS:tl}|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
