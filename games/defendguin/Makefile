# New ports collection makefile for:	defendguin
# Date created:				8 February 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	defendguin
PORTVERSION=	0.0.12
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.tuxpaint.org/unix/x/defendguin/src/ \
		ftp://ftp.billsgames.com/unix/x/defendguin/src/ \
		http://www.newbreedsoftware.com/images/prodicons/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}.gif:icons
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Your mission is to defend little penguinoids

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_SDL=	mixer sdl

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.gif

PORTDATA=	*
PORTDOCS=	AUTHORS.txt CHANGES.txt README.txt TODO.txt

MAN6=		${PORTNAME}.6

.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -DDATA_PREFIX=\"${DATADIR}/\" \
		`${SDL_CONFIG} --cflags` defendguin.c -o defendguin \
		`${SDL_CONFIG} --libs` -lSDL_mixer

do-install:
# Executable
	${INSTALL_PROGRAM} ${WRKSRC}/defendguin ${PREFIX}/bin

# Manuall
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${MAN6PREFIX}/man/man6

# Data
	@(cd ${WRKSRC}/../data && ${COPYTREE_SHARE} "images music sounds" ${DATADIR})

# Pixmaps
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}.gif ${PREFIX}/share/pixmaps/

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/../docs/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>
