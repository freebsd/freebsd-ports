# Created by: jamie
# $FreeBSD$

PORTNAME=	hex-a-hop
PORTVERSION=	1.1.0
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME:S/-//g}/${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Puzzle game based on hexagonal tiles

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		iconv localbase sdl
USE_SDL=	sdl
USE_CXXSTD=	c++98
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	PANGO SOUND NLS DEBUG
OPTIONS_DEFAULT=	SOUND

DEBUG_CONFIGURE_ENABLE=	debug

NLS_USES=		gettext
NLS_CONFIGURE_ENV=	ac_cv_header_libintl_h=yes
NLS_CONFIGURE_ENV_OFF=	ac_cv_header_libintl_h=no
NLS_LDFLAGS=		-lintl

PANGO_DESC=	Use SDL_Pango instead of SDL_ttf
PANGO_USE=	SDL=pango
PANGO_USE_OFF=	SDL=ttf
PANGO_CONFIGURE_ON=	--disable-sdlttf

SOUND_DESC=	Sound support
SOUND_USE=	SDL=mixer
SOUND_CONFIGURE_ENABLE=	sound

DESKTOP_ENTRIES="Hex-a-Hop" "${COMMENT}" \
		"${DATADIR}/icon.bmp" \
		"hex-a-hop" "LogicGame;Game;" false

post-patch:
	@${REINPLACE_CMD} -E '/CFLAGS|CXXFLAGS/s/-g//' ${WRKSRC}/configure

.include <bsd.port.mk>
