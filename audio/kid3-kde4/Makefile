# $FreeBSD$

PORTNAME=	kid3
PORTVERSION=	2.3
PORTREVISION=	2
CATEGORIES=	audio kde
MASTER_SITES=	SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	MP3/Ogg/FLAC tag editor for KDE

LICENSE=	GPLv2

LATEST_LINK=	${PORTNAME}-kde4

USE_KDE4=	kdelibs kdeprefix kdehier automoc4
USE_QT4=	qmake_build moc_build rcc_build uic_build
USES=		cmake gettext
MAKE_JOBS_SAFE=	yes

OPTIONS_DEFINE=	FLAC ID3LIB MP4V2 VORBIS TAGLIB CHROMAPRINT
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

FLAC_DESC=	Support for FLAC files
ID3LIB_DESC=	Support for mp3 files
MP4V2_DESC=	Support for mp4 files
VORBIS_DESC=	Support for Ogg/Vorbis files
TAGLIB_DESC=	Support for various audio formats
CHROMAPRINT_DESC=	Support for Chromaprint audio fingerprints

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFLAC}
CMAKE_ARGS+=	-DWITH_FLAC=ON
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
.else
CMAKE_ARGS+=	-DWITH_FLAC=OFF
.endif

.if ${PORT_OPTIONS:MID3LIB}
CMAKE_ARGS+=	-DWITH_ID3LIB=ON
LIB_DEPENDS+=	id3-3.8.3:${PORTSDIR}/audio/id3lib
.else
CMAKE_ARGS+=	-DWITH_ID3LIB=OFF
.endif

.if ${PORT_OPTIONS:MMP4V2}
CMAKE_ARGS+=	-DWITH_MP4V2=ON
LIB_DEPENDS+=	mp4v2.10:${PORTSDIR}/multimedia/mp4v2
.else
CMAKE_ARGS+=	-DWITH_MP4V2=OFF
.endif

.if ${PORT_OPTIONS:MVORBIS}
CMAKE_ARGS+=	-DWITH_VORBIS=ON
LIB_DEPENDS+=	vorbis.4:${PORTSDIR}/audio/libvorbis \
		ogg:${PORTSDIR}/audio/libogg
.else
CMAKE_ARGS+=	-DWITH_VORBIS=OFF
.endif

.if ${PORT_OPTIONS:MTAGLIB}
CMAKE_ARGS+=	-DWITH_TAGLIB=ON
LIB_DEPENDS+=	tag.1:${PORTSDIR}/audio/taglib
.else
CMAKE_ARGS+=	-DWITH_TAGLIB=OFF
.endif

.if ${PORT_OPTIONS:MCHROMAPRINT}
CMAKE_ARGS+=	-DWITH_CHROMAPRINT=ON \
		-DWITH_FFMPEG=ON
LIB_DEPENDS+=	chromaprint:${PORTSDIR}/audio/chromaprint
.else
CMAKE_ARGS+=	-DWITH_CHROMAPRINT=OFF
.endif

pre-configure:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
