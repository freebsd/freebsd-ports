# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lastfm-desktop
PORTVERSION=	2.1.36
PORTREVISION=	9
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Official Last.fm desktop application suite

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	liblastfm.so:audio/liblastfm \
		libavcodec.so:multimedia/ffmpeg \
		libgpod.so:audio/libgpod \
		libimobiledevice.so:comms/libimobiledevice \
		libplist.so:devel/libplist

USES=		gettext pkgconfig qmake gmake qt:4
USE_QT=		corelib dbus gui linguist_build moc_build network phonon \
		phonon-gst_run rcc_build sql uic_build webkit xml

USE_GITHUB=	yes
GH_ACCOUNT=	lastfm

SUB_FILES=	lastfm-desktop.sh

DESKTOP_ENTRIES="Last.fm Scrobbler" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/audioscrobbler.ico" \
		"lastfm-desktop" \
		"AudioVideo;Audio;Qt;" \
		true

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/lastfm-desktop.sh ${STAGEDIR}${PREFIX}/bin/lastfm-desktop
	${INSTALL_PROGRAM} ${WRKSRC}/_bin/fingerprinter ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/_bin/lastfm-scrobbler ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/app/client/Last.fm\ Scrobbler.css ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/app/client/audioscrobbler.ico ${STAGEDIR}${PREFIX}/share/pixmaps/
	(cd ${WRKSRC}/app/client && ${COPYTREE_SHARE} qrc ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
