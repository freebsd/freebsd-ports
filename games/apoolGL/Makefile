# New ports collection makefile for:	apoolGL
# Date created:				26 Aug 2005
# Whom:					Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	apoolGL
PORTVERSION=	0.99.22
CATEGORIES=	games
MASTER_SITES=	http://www.planetjahn.de/files/
DISTNAME=	${PORTNAME}-099-pre22

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Another billiard simulator

USE_X_PREFIX=	yes
USE_SDL=	sdl
USE_GL=		yes

PORTDOCS=	ApoolGL.txt CHANGELOG OpenGL-Features

post-patch:
	@${REINPLACE_CMD} -e "s|`${PRINTF} '\r'`$$||" ${WRKSRC}/ApoolGL.txt
	@${REINPLACE_CMD} -e 's|SDL/||' ${WRKSRC}/*.c

do-build:
	${CC} ${CFLAGS} -DDATADIR="\"${DATADIR}\"" \
		`${SDL_CONFIG} --cflags --libs` \
		-I${X11BASE}/include -L${X11BASE}/lib -lGL -lGLU \
		-o ${WRKSRC}/apool ${WRKSRC}/*.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/apool ${PREFIX}/bin
.for i in hi lo med
	${MKDIR} ${DATADIR}/textures-${i}
	${INSTALL_DATA} ${WRKSRC}/textures-${i}/*.bmp ${DATADIR}/textures-${i}
.endfor
	${INSTALL_DATA} ${WRKSRC}/*.dat ${DATADIR}

.ifndef (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
