# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	quimup
PORTVERSION=	1.4.0
CATEGORIES=	audio
MASTER_SITES=	SF/musicpd/Quimup/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt4 client for MPD (the Music Player Daemon)

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libmpdclient.so:${PORTSDIR}/audio/libmpdclient \
		libtag.so:${PORTSDIR}/audio/taglib

WRKSRC=		${WRKDIR}/${PORTNAME}\ ${PORTVERSION}

USES=		pkgconfig qmake
USE_QT5=	core gui network widgets buildtools_build

PLIST_FILES=	bin/quimup \
		share/pixmaps/quimup.png

DESKTOP_ENTRIES="Quimup" "MPD client" "quiump" "quiump" \
		"Audio;AudioVideo;Qt;" true

post-patch:
	@${REINPLACE_CMD} -e \
		'/^#define get_time/d' ${WRKSRC}/src/qm_playlistview.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quimup ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/src/resources/mn_icon.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/quimup.png

.include <bsd.port.mk>
