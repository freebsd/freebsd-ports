# Created by: Igor Pokrovsky <ip@doom.homeunix.org>
# $FreeBSD$

PORTNAME=	apoolGL
PORTVERSION=	0.99.22
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.planetjahn.de/files/
DISTNAME=	${PORTNAME}-099-pre22

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another billiards simulator

LICENSE=	GPLv2+

USE_SDL=	sdl
USE_GL=		gl

OPTIONS_DEFINE=	DOCS

PORTDOCS=	ApoolGL.txt CHANGELOG OpenGL-Features

post-patch:
	@${REINPLACE_CMD} -e "s|`${PRINTF} '\r'`$$||" ${WRKSRC}/ApoolGL.txt
	@${REINPLACE_CMD} -e 's|SDL/||' ${WRKSRC}/*.c

do-build:
	${CC} ${CFLAGS} -DDATADIR="\"${DATADIR}\"" \
		`${SDL_CONFIG} --cflags --libs` \
		-I${LOCALBASE}/include -L${LOCALBASE}/lib -lGL -lGLU -lm \
		-o ${WRKSRC}/apool ${WRKSRC}/*.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apool ${STAGEDIR}${PREFIX}/bin
.for i in hi lo med
	@${MKDIR} ${STAGEDIR}${DATADIR}/textures-${i}
	${INSTALL_DATA} ${WRKSRC}/textures-${i}/*.bmp ${STAGEDIR}${DATADIR}/textures-${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/*.dat ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
