# New ports collection makefile for:	vor
# Date created:				07 Sep 2005
# Whom:					Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	vor
PORTVERSION=	0.3
CATEGORIES=	games
MASTER_SITES=	http://qualdan.com/vor/

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Dodge the rocks until you die

BUILD_DEPENDS=	${LOCALBASE}/include/argp.h:${PORTSDIR}/devel/argp-standalone

USE_SDL=	mixer image sdl
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
.for file in main.c shape.h sound.h
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|' ${WRKSRC}/${file}
.endfor
.for file in shape.h score.c score.h debug.c
	@${REINPLACE_CMD} -e 's|<stdint.h>|<inttypes.h>|' ${WRKSRC}/${file}
.endfor
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|^\(my_objects.*\)$$|\1 ${LOCALBASE}/lib/libargp.a|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/share/vor|${PREFIX}/share/vor|g' ${WRKSRC}/config.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vor ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${MKDIR} ${DATADIR}/banners
	${MKDIR} ${DATADIR}/fonts
	${MKDIR} ${DATADIR}/icons
	${MKDIR} ${DATADIR}/indicators
	${MKDIR} ${DATADIR}/music
	${MKDIR} ${DATADIR}/sounds
	${MKDIR} ${DATADIR}/sprites
	${INSTALL_DATA} ${WRKSRC}/data/banners/* ${DATADIR}/banners/
	${INSTALL_DATA} ${WRKSRC}/data/fonts/* ${DATADIR}/fonts/
	${INSTALL_DATA} ${WRKSRC}/data/icons/* ${DATADIR}/icons/
	${INSTALL_DATA} ${WRKSRC}/data/indicators/* ${DATADIR}/indicators/
	${INSTALL_DATA} ${WRKSRC}/data/music/* ${DATADIR}/music/
	${INSTALL_DATA} ${WRKSRC}/data/sounds/* ${DATADIR}/sounds/
	${INSTALL_DATA} ${WRKSRC}/data/sprites/* ${DATADIR}/sprites/

.include <bsd.port.mk>
