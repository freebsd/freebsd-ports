# New ports collection makefile for:	biniax2
# Date created:		16 Apr 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	biniax2
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	http://mordred.dir.bg/biniax/ \
		http://www.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-fullsrc

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Original logic game with arcade and tactics modes

USE_SDL=	sdl mixer image

WRKSRC=		${WRKDIR}

post-patch:
	@${RM} -f ${WRKSRC}/data/Thumbs.db
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|g' \
		${WRKSRC}/desktop/gfx.c ${WRKSRC}/desktop/snd.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} biniax.c hof.c desktop/cfg.c \
		desktop/gfx.c desktop/snd.c desktop/inp.c desktop/sys.c \
		-I. -Idesktop `${SDL_CONFIG} --cflags --libs` \
		-lSDL_image -lSDL_mixer -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${DATADIR}

.include <bsd.port.mk>
