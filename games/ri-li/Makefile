# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	Ri-li
PORTVERSION=	2.0.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}%20Linux_Unix/${PORTNAME}%20V${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Drive a toy wood train in many levels - snake-like arcade game

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake
USE_SDL=	sdl mixer

CPPFLAGS+=	`${SDL_CONFIG} --cflags` -I${LOCALBASE}/include

PLIST_FILES=	bin/Ri_li
PORTDATA=	*

DESKTOP_ENTRIES="Ri-li" \
		"Drive a toy wood train in many levels - snake-like arcade game" \
		"${DATADIR}/Ri-li-icon-48x48.png" \
		"Ri_li" \
		"Game;ArcadeGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e 's|-lSDL |`${SDL_CONFIG} --libs`|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's| gentoo||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/strcpy.*DefPath/ s|.*|strcpy(DefPath,"${DATADIR}/");|' ${WRKSRC}/src/main.cc
	@${REINPLACE_CMD} -e '/include/ s|iostream.h|iostream|' ${WRKSRC}/src/*.cc
	@${REINPLACE_CMD} -e 's|cerr|std::&|g; s|endl|std::&|g' ${WRKSRC}/src/*.cc

.include <bsd.port.mk>
