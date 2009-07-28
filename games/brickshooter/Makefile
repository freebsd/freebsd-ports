# New ports collection makefile for:	brickshooter
# Date created:		09 May 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	brickshooter
PORTVERSION=	0.04
CATEGORIES=	games
MASTER_SITES=	http://bilious.homelinux.org/~paxed/brickshooter/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Push blocks on to the playing field, match block colors to remove them

USE_SDL=	sdl mixer image

PORTDOCS=	*

post-patch:
.for dir in gfx levels snd
	@${REINPLACE_CMD} -e 's|${dir}/|${DATADIR}/&|g' ${WRKSRC}/${PORTNAME}.c
.endfor

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c \
		`${SDL_CONFIG} --libs --cflags` -lSDL_image -lSDL_mixer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.for dir in gfx levels snd
	${MKDIR} ${DATADIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/* ${DATADIR}/${dir}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
