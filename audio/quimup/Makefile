# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	quimup
PORTVERSION=	1.4.1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}_source

MAINTAINER=	cmangin@arobas.net
COMMENT=	Qt5 client for MPD (the Music Player Daemon)

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmpdclient.so:audio/libmpdclient \
		libtag.so:audio/taglib

WRKSRC=		${WRKDIR}/${PORTNAME}\ ${PORTVERSION}

USES=		pkgconfig qmake
USE_QT5=	core gui network widgets buildtools_build
USE_GL=		gl

PLIST_FILES=	bin/quimup \
		share/pixmaps/quimup.png

DESKTOP_ENTRIES="Quimup" "MPD client" "quimup" "quimup" \
		"Audio;AudioVideo;Qt;" true

post-patch:
	@${REINPLACE_CMD} -e \
		'/^#define get_time/d' ${WRKSRC}/src/qm_playlistview.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quimup ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/resources/mn_icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/quimup.png

.include <bsd.port.mk>
