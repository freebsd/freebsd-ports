# New ports collection makefile for:   kid3
# Date created:                2006-08-02
# Whom:                        Max Brazhnikov <makc@issp.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	kid3
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	audio kde
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	MP3/Ogg/FLAC tag editor for KDE

LICENSE=	GPLv2

LATEST_LINK=	${PORTNAME}-kde4

USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT4=	svg gui network dbus xml \
		qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
# libchromaprint has not been ported yet
CMAKE_ARGS=	-DWITH_CHROMAPRINT=off
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	FLAC ID3LIB MP4V2 VORBIS TAGLIB
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

FLAC_DESC=	Support for FLAC files
ID3LIB_DESC=	Support for mp3 files
MP4V2_DESC=	Support for mp4 files
VORBIS_DESC=	Support for Ogg/Vorbis files
TAGLIB_DESC=	Support for various audio formats

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFLAC}
CMAKE_ARGS+=	-DWITH_FLAC=OFF
.else
CMAKE_ARGS+=	-DWITH_FLAC=ON
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
.endif

.if ${PORT_OPTIONS:MID3LIB}
CMAKE_ARGS+=	-DWITH_ID3LIB=OFF
.else
CMAKE_ARGS+=	-DWITH_ID3LIB=ON
LIB_DEPENDS+=	id3-3.8.3:${PORTSDIR}/audio/id3lib
.endif

.if ${PORT_OPTIONS:MMP4V2}
CMAKE_ARGS+=	-DWITH_MP4V2=OFF
.else
CMAKE_ARGS+=	-DWITH_MP4V2=ON
LIB_DEPENDS+=	mp4v2.10:${PORTSDIR}/multimedia/mp4v2
.endif

.if ${PORT_OPTIONS:MVORBIS}
CMAKE_ARGS+=	-DWITH_VORBIS=OFF
.else
CMAKE_ARGS+=	-DWITH_VORBIS=ON
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		ogg:${PORTSDIR}/audio/libogg
.endif

.if ${PORT_OPTIONS:MTAGLIB}
CMAKE_ARGS+=	-DWITH_TAGLIB=OFF
.else
CMAKE_ARGS+=	-DWITH_TAGLIB=ON
LIB_DEPENDS+=	tag.1:${PORTSDIR}/audio/taglib
.endif

pre-configure:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
