# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	brickshooter
PORTVERSION=	0.04
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://bilious.homelinux.org/~paxed/brickshooter/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Push blocks on to the playing field, match block colors to remove them

USES=		sdl
USE_SDL=	sdl mixer image

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
.for dir in gfx levels snd
	@${REINPLACE_CMD} -e 's|${dir}/|${DATADIR}/&|g' ${WRKSRC}/${PORTNAME}.c
.endfor

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} ${PORTNAME}.c \
		`${SDL_CONFIG} --libs --cflags` -lSDL_image -lSDL_mixer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC} && ${COPYTREE_SHARE} "gfx levels snd" ${STAGEDIR}${DATADIR}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
