# New ports collection makefile for:   kid3
# Date created:                2006-08-02
# Whom:                        Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kid3
PORTVERSION=	2.0.1
PORTREVISION=	1
CATEGORIES=	audio kde
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	MP3/Ogg/FLAC tag editor for KDE

LICENSE=	GPLv2

LATEST_LINK=	${PORTNAME}-kde4

USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT_VER=	4
QT_COMPONENTS=	svg gui network dbus xml \
		qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	FLAC "Support for FLAC files" on \
		ID3LIB "Support for mp3 files" on \
		MP4V2 "Support for mp4 files" on \
		VORBIS "Support for Ogg/Vorbis files" on \
		TAGLIB "Support for various audio formats" on \
		TUNEPIMP "Support for MusicBrainz service" on

.include <bsd.port.options.mk>

.if defined(WITHOUT_FLAC)
CMAKE_ARGS+=	-DWITH_FLAC=OFF
.else
CMAKE_ARGS+=	-DWITH_FLAC=ON
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
.endif

.if defined(WITHOUT_ID3LIB)
CMAKE_ARGS+=	-DWITH_ID3LIB=OFF
.else
CMAKE_ARGS+=	-DWITH_ID3LIB=ON
LIB_DEPENDS+=	id3-3.8.3:${PORTSDIR}/audio/id3lib
.endif

.if defined(WITHOUT_MP4V2)
CMAKE_ARGS+=	-DWITH_MP4V2=OFF
.else
CMAKE_ARGS+=	-DWITH_MP4V2=ON
LIB_DEPENDS+=	mp4v2.10:${PORTSDIR}/multimedia/mp4v2
.endif

.if defined(WITHOUT_VORBIS)
CMAKE_ARGS+=	-DWITH_VORBIS=OFF
.else
CMAKE_ARGS+=	-DWITH_VORBIS=ON
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		ogg.7:${PORTSDIR}/audio/libogg
.endif

.if defined(WITHOUT_TAGLIB)
CMAKE_ARGS+=	-DWITH_TAGLIB=OFF
.else
CMAKE_ARGS+=	-DWITH_TAGLIB=ON
LIB_DEPENDS+=	tag.1:${PORTSDIR}/audio/taglib
.endif

.if defined(WITHOUT_TUNEPIMP)
CMAKE_ARGS+=	-DWITH_TUNEPIMP=OFF
.else
CMAKE_ARGS+=	-DWITH_TUNEPIMP=ON
LIB_DEPENDS+=	tunepimp.5:${PORTSDIR}/audio/libtunepimp
.endif

pre-configure:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
