# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lastfm-desktop
PORTVERSION=	2.1.36
PORTREVISION=	8
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Official Last.fm desktop application suite

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Requires vlc-qt4 which was deprecated on 2018-12-31
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	liblastfm.so:audio/liblastfm \
		libavcodec.so:multimedia/ffmpeg \
		libgpod.so:audio/libgpod \
		libimobiledevice.so:comms/libimobiledevice \
		libplist.so:devel/libplist

USE_GITHUB=	yes
GH_ACCOUNT=	lastfm

USES=		gettext pkgconfig qmake gmake qt:4
USE_QT=		corelib dbus gui linguist_build moc_build network phonon \
		rcc_build sql uic_build webkit xml
SUB_FILES=	lastfm-desktop.sh

DESKTOP_ENTRIES="Last.fm Scrobbler" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/audioscrobbler.ico" \
		"lastfm-desktop" \
		"AudioVideo;Audio;Qt;" \
		true

OPTIONS_SINGLE=		PHONON
OPTIONS_SINGLE_PHONON=	GSTREAMER VLC
OPTIONS_DEFAULT=	VLC
GSTREAMER_DESC=		Multimedia via Phonon-GStreamer
GSTREAMER_USES=	qt:4
GSTREAMER_USE=		QT=phonon-gst_run
VLC_DESC=		Multimedia via Phonon-VLC
#multimedia/phonon-vlc@qt4 flavor was removed due to depreciation of vlc-qt4
#VLC_RUN_DEPENDS=	phonon-vlc-qt4>=0.6.1:multimedia/phonon-vlc@qt4

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/lastfm-desktop.sh ${STAGEDIR}${PREFIX}/bin/lastfm-desktop
	${INSTALL_PROGRAM} ${WRKSRC}/_bin/fingerprinter ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/_bin/lastfm-scrobbler ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/app/client/Last.fm\ Scrobbler.css ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/app/client/audioscrobbler.ico ${STAGEDIR}${PREFIX}/share/pixmaps/
	(cd ${WRKSRC}/app/client && ${COPYTREE_SHARE} qrc ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
