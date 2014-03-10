# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	annelid
PORTVERSION=	1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.garthgillespie.com/annelid/
DISTFILES=	${PORTNAME}-src${EXTRACT_SUFX} \
		${PORTNAME}-media${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remake of the ubiquitous "Snake" and "Worm" games

RESTRICTED=	No redistribution allowed

USES=	gmake zip
USE_SDL=	sdl
USE_GL=		gl
NO_WRKSUBDIR=	yes

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

SUB_FILES=	${PORTNAME}-sh

DATAFILES=	annelid.dat apple.tga apple.wav backd.tga backn.tga font.dat \
		font.tga front.tga grow.wav head.tga powerup.tga readme.txt \
		score.wav segment.tga shrink.wav slow.wav speed.wav title.tga \
		vortex.wav

.include <bsd.port.options.mk>

post-patch:
# Fix Makefile.
	@${REINPLACE_CMD} -e 's|%%CFLAGS%%|${CFLAGS}| ; \
		s|%%LOCALBASE%%|${LOCALBASE}| ; \
		s|sdl-config|${SDL_CONFIG}|' \
		${WRKSRC}/${MAKEFILE}

# Fix SDL include statement.
	@${REINPLACE_CMD} -e 's|\(#include.*\)SDL/\(SDL.*\)|\1\2|' \
		${WRKSRC}/*.cpp ${WRKSRC}/*.h

# Enable/disable compilation optimizations.
.if empty(PORT_OPTIONS:MOPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|$$(OPT)||' ${WRKSRC}/${MAKEFILE}
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/libexec
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in ${DATAFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor

.include <bsd.port.mk>
