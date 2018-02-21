# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bloboats
PORTVERSION=	1.0.2
DISTVERSIONSUFFIX=	-source
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://bloboats.dy.fi/mirror/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Boat racing game in the spirit of Elasto Mania or X-Moto

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/copying.txt

BROKEN_FreeBSD_12=	does not build on 12.X

USES=		dos2unix gmake
USE_SDL=	mixer image net sdl
USE_GL=		gl glu

DESKTOP_ENTRIES="Bloboats" \
		"${COMMENT}" \
		"${PORTNAME}" \
		"${PORTNAME}" \
		"Game;" \
		false

MAKE_ENV+=	DATADIR="${DATADIR}" STAGEDIR=${STAGEDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DOS2UNIX_FILES=	src/*.cpp

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/images/icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
