# Created by: Amar Takhar <verm@drunkmonk.net>
# $FreeBSD$

PORTNAME=	kobodeluxe
PORTVERSION=	0.5.1
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://olofson.net/kobodl/download/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	KoboDeluxe-${DISTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	An SDL port of the scrolling game XKobo

USE_BZIP2=	yes
USE_SDL=	image sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sharedstatedir=${SCOREDIR} --enable-oss

MAN6=		kobodl.6

SCOREDIR=	/var/games/${PORTNAME}
PLIST_SUB=	SCOREDIR="${SCOREDIR}"

DATADIR=	${PREFIX}/share/kobo-deluxe

DESKTOP_ENTRIES="Kobo Deluxe" \
		"An SDL port of the scrolling game XKobo" \
		"${DATADIR}/" \
		"kobodeluxe" \
		"Game;ArcadeGame;" \
		false

OPTIONS_DEFINE=	OPENGL
OPTIONS_DEFAULT=OPENGL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENGL}
USE_GL=		yes
CONFIGURE_ARGS+=	--enable-opengl
.else
CONFIGURE_ARGS+=	--disable-opengl
.endif

post-extract:
	@cd ${WRKSRC} && ${TAR} -xzf icons.tar.gz

post-patch:
	@${REINPLACE_CMD} -e 's|$$(datadir)/games/kobo-deluxe|${DATADIR}|; \
		s|$$(prefix)/games/kobo-deluxe/scores|${SCOREDIR}|; \
		s|-lSDL$$||; s|SDL/SDL|SDL|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|$$(datadir)/games/kobo-deluxe|${DATADIR}|' \
		${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e 's|pipe2|kobopipe2|g' ${WRKSRC}/enemies.h \
		${WRKSRC}/enemy.cpp

post-install:
	${CHGRP} games ${PREFIX}/bin/kobodl
	${CHMOD} g+s ${PREFIX}/bin/kobodl
	${INSTALL} -d -o root -g games -m 775 ${SCOREDIR}
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/Ubuntu/kobodeluxe.desktop \
		${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/icons/Ubuntu/kobo-icon.xpm \
		${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
