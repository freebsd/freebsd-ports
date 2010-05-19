# New ports collection makefile for:	cueplayer
# Date created:		2010-01-17
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	cueplayer
PORTVERSION=	0.25
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	CUE player

USE_QT_VER=	4
QT_COMPONENTS=	gui xml qmake_build uic_build moc_build rcc_build network
USE_GSTREAMER=	flac good dvd lame ugly ffmpeg taglib ogg vorbis soup libmms wavpack

DESKTOP_ENTRIES="Cueplayer" "Lightweight media player based on Qt and Gstreamer" \
		"${DATADIR}/${PORTNAME}.png" "${PORTNAME}" \
		"AudioVideo;Audio;Video;" ${FALSE}

post-patch:
	cd ${WRKSRC} && ${REINPLACE_CMD} -e 's,/usr/share/cueplayer/,${DATADIR}/,g' \
		main.cpp ${PORTNAME}.pro
	${REINPLACE_CMD} -e 's,/usr/share,${PREFIX},g' \
		${WRKSRC}/${PORTNAME}.pro

do-configure:
	cd ${WRKSRC} && ${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/images/${PORTNAME}.png ${DATADIR}

.include <bsd.port.mk>
