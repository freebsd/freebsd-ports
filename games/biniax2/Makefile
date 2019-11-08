# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	biniax2
PORTVERSION=	1.30
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://mordred.dir.bg/biniax/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-fullsrc

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Original logic game with arcade and tactics modes

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_SDL=	sdl mixer image
USES=		dos2unix sdl
DOS2UNIX_FILES=	biniax.c
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

post-patch:
	@${RM} ${WRKSRC}/data/Thumbs.db
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/|g' \
		${WRKSRC}/desktop/gfx.c ${WRKSRC}/desktop/snd.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} biniax.c hof.c desktop/cfg.c \
		desktop/gfx.c desktop/snd.c desktop/inp.c desktop/sys.c \
		-I. -Idesktop `${SDL_CONFIG} --cflags --libs` \
		-lSDL_image -lSDL_mixer -o ${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
