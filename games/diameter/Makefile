# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	diameter
PORTVERSION=	0.4.0.3
PORTREVISION=	13
CATEGORIES=	games
MASTER_SITES=	SF/game${PORTNAME}/game${PORTNAME}/${PORTNAME}-0.4.0

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arcade-style game with elements of economy and adventure

BROKEN_armv6=		fails to compile: res/3dsloader.cpp:77:15: comparison between pointer and integer ('char *' and 'int')
BROKEN_armv7=		fails to compile: res/3dsloader.cpp:77:15: comparison between pointer and integer ('char *' and 'int')

LIB_DEPENDS=	libpng.so:graphics/png \
		libguichan.so:devel/guichan

USES=		compiler:c++11-lang dos2unix gl gmake pkgconfig python:2.7 sdl \
		tar:bzip2 
DOS2UNIX_FILES=	src/res/3dsloader.cpp
GNU_CONFIGURE=	yes
USE_GL=		gl glu
USE_SDL=	sdl mixer image

WRKSRC=		${WRKDIR}/gamediameter

CPPFLAGS+=	`${SDL_CONFIG} --cflags` -I${LOCALBASE}/include
LDFLAGS+=	`${SDL_CONFIG} --libs` -L${LOCALBASE}/lib

CXXFLAGS+=	-Wno-static-float-init

DATADIR=	${PREFIX}/share/gamediameter

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|; /^CFLAGS=.*march/ d' \
		${WRKSRC}/configure

.include <bsd.port.mk>
