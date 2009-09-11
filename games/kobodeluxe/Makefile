# New ports collection makefile for:	kobodeluxe
# Date created:		12 June 2002
# Whom:			Amar Takhar <verm@drunkmonk.net>
#
# $FreeBSD$
#

PORTNAME=	kobodeluxe
PORTVERSION=	0.5.1
PORTREVISION=	2
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
MAKE_JOBS_SAFE=	yes

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

OPTIONS=	OPENGL "OpenGL rendering layer" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_OPENGL)
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

post-install:
	${CHGRP} games ${PREFIX}/bin/kobodl
	${CHMOD} g+s ${PREFIX}/bin/kobodl
	${INSTALL} -d -o root -g games -m 775 ${SCOREDIR}
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/icons/Ubuntu/kobodeluxe.desktop \
		${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/icons/Ubuntu/kobo-icon.xpm \
		${PREFIX}/share/pixmaps/

.include <bsd.port.post.mk>
