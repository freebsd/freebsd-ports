# New ports collection makefile for:	games/anagramarama
# Date created:			10 Aug 2005
# Whom:				Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	anagramarama
PORTVERSION=	0.2
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.omega.clara.net/anagramarama/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anagramarama - a word game for Linux, Windows and BeOS

USE_GMAKE=	yes
USE_SDL=	mixer sdl
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	OPTIMIZED_CFLAGS "Enable compilation optimizations" on

MAKEFILE=	makefile

.include <bsd.port.pre.mk>

post-patch:
# Fix Makefile.
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}| ; \
		s|\(-Wall\)|${CFLAGS} \1|' \
		${WRKSRC}/${MAKEFILE}

# Fix SDL include statement and path to ${DATADIR}.
	@${REINPLACE_CMD} -e 's|\(#include.*\)SDL/\(SDL.*\)|\1\2| ; \
		s|\(audio/\)|${DATADIR}/\1| ; \
		s|\(images/\)|${DATADIR}/\1| ; \
		s|\(wordlist.txt\)|${DATADIR}/\1|' \
		${WRKSRC}/src/*.c ${WRKSRC}/src/*.h

# Enable/disable optimized CFLAGS.
.if defined(WITHOUT_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|$$(OPT)||' ${WRKSRC}/${MAKEFILE}
.endif

do-install:
# Program.
	${INSTALL_PROGRAM} ${WRKSRC}/ag ${PREFIX}/bin

# Data.
	${MKDIR} ${DATADIR}

# Data: audio.
	${MKDIR} ${DATADIR}/audio
.for f in badword.wav clearword.wav click-answer.wav click-shuffle.wav \
	clock-tick.wav duplicate.wav found.wav foundbig.wav shuffle.wav
	${INSTALL_DATA} ${WRKSRC}/audio/${f} ${DATADIR}/audio
	${MKDIR} ${DATADIR}/images
.endfor

# Data: images.
.for f in background.bmp letterBank.bmp numberBank.bmp smallLetterBank.bmp
	${INSTALL_DATA} ${WRKSRC}/images/${f} ${DATADIR}/images
.endfor

# Data: wordlist.txt.
	${INSTALL_DATA} ${WRKSRC}/wordlist.txt ${DATADIR}

.include <bsd.port.post.mk>
