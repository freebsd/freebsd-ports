# New ports collection makefile for:	defendguin
# Date created:				8 February 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	defendguin
PORTVERSION=	0.0.12
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.billsgames.com/unix/x/defendguin/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another shoot-the-Bill game

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_SDL=	mixer sdl

PLIST_FILES=	bin/defendguin

MAN6=		defendguin.6

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -DDATA_PREFIX=\"${DATADIR}/\" \
		`${SDL_CONFIG} --cflags` defendguin.c -o defendguin \
		`${SDL_CONFIG} --libs` -lSDL_mixer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/defendguin ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/defendguin.6 ${MAN6PREFIX}/man/man6
	@${MKDIR} ${DATADIR}
	${TAR} -C ${WRKSRC}/../data -cf - . | \
		${TAR} -C ${DATADIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}

post-install:
	@${FIND} ${DATADIR} ! -type d | ${SED} \
		-e "s,${PREFIX}/,," >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | ${SED} \
		-e "s,${PREFIX}/,@dirrm ," >> ${TMPPLIST}

.include <bsd.port.mk>
