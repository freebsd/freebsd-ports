# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	mixxx
DISTVERSIONPREFIX=	release-
DISTVERSION=	2.2.3
CATEGORIES=	audio

MAINTAINER=	acm@FreeBSD.org
COMMENT=	DJ mixing application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	lv2>=1.14.0:audio/lv2
LIB_DEPENDS=	libchromaprint.so:audio/chromaprint \
		libFLAC.so:audio/flac \
		libfftw3.so:math/fftw3 \
		libhidapi.so:comms/hidapi \
		libid3tag.so:audio/libid3tag \
		libmad.so:audio/libmad \
		libmodplug.so:audio/libmodplug \
		libportaudio.so:audio/portaudio \
		libSoundTouch.so:audio/soundtouch \
		libebur128.so:audio/libebur128 \
		librubberband.so:audio/rubberband \
		libsndfile.so:audio/libsndfile \
		libvamp-sdk.so:audio/vamp-plugin-sdk \
		libogg.so:audio/libogg \
		libvorbisfile.so:audio/libvorbis \
		libtag.so:audio/taglib \
		libprotobuf.so:devel/protobuf \
		liblilv-0.so:audio/lilv

USES=		compiler:c++11-lang gl iconv qt:5 pkgconfig scons xorg
USE_XORG=	x11
USE_GL=		gl glu
USE_GITHUB=	yes
GH_ACCOUNT=	mixxxdj
USE_QT=		buildtools concurrent core dbus gui network opengl script scripttools \
		sql sql-sqlite3 svg testlib xml xmlpatterns linguisttools_build \
		qmake_build widgets

CONFLICTS=	mixxx20* mixxx21*

MAKE_ARGS=	qtdir="${PREFIX}" install_root="${PREFIX}" \
		build=release optimize=off ${GUI} battery=0 vamp=1 modplug=1 mad=1
LATE_INSTALL_ARGS=	--install-sandbox=${STAGEDIR}

GUI=		qt5=1

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS FAAD FFMPEG GPERFTOOLS HID LAME OPUS SHOUTCAST WAVPACK
OPTIONS_DEFAULT=	FAAD FFMPEG HID SHOUTCAST OPUS WAVPACK
OPTIONS_SUB=		yes

FAAD_LIB_DEPENDS=	libfaad.so:audio/faad \
			libmp4v2.so:multimedia/mp4v2
FAAD_MAKE_ARGS=		faad=1
FAAD_MAKE_ARGS_OFF=	faad=0
FFMPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
FFMPEG_MAKE_ARGS=	ffmpeg=1
FFMPEG_MAKE_ARGS_OFF=	ffmpeg=0
GPERFTOOLS_LIB_DEPENDS=	libtcmalloc.so:devel/google-perftools
GPERFTOOLS_MAKE_ARGS=	perftools=1
GPERFTOOLS_MAKE_ARGS_OFF=	perftools=0
HID_DESC=			USB HID controllers support
HID_MAKE_ARGS=		hid=1
HID_MAKE_ARGS_OFF=	hid=0
LAME_RUN_DEPENDS=	lame:audio/lame
OPUS_LIB_DEPENDS=	libopus.so:audio/opus \
		libopusfile.so:audio/opusfile
OPUS_MAKE_ARGS=		opus=1
OPUS_MAKE_ARGS_OFF=	opus=0
SHOUTCAST_LIB_DEPENDS=	libshout.so:audio/libshout
SHOUTCAST_MAKE_ARGS=	shoutcast=1
SHOUTCAST_MAKE_ARGS_OFF=	shoutcast=0
WAVPACK_LIB_DEPENDS=	libwavpack.so:audio/wavpack
WAVPACK_MAKE_ARGS=	wv=1
WAVPACK_MAKE_ARGS_OFF=	wv=0

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/build/depends.py
	@${REINPLACE_CMD} -e "s|bzr |true |g" \
		${WRKSRC}/build/util.py
	@${REINPLACE_CMD} -e "/('install', docs)/d" \
		${WRKSRC}/src/SConscript
	@${REINPLACE_CMD} -e "s|^Exec=.*|Exec=mixxx| ; \
		 s|^Icon=.*|Icon=${PREFIX}/share/pixmaps/mixxx_icon.svg|" \
		${WRKSRC}/res/linux/mixxx.desktop
	@${REINPLACE_CMD} -e "s,(Q_OS_LINUX),(Q_OS_LINUX) || defined(Q_OS_FREEBSD),g" \
		${WRKSRC}/src/util/screensaver.h
.for i in midi/midimessage.h
	@${ECHO_CMD} >> ${WRKSRC}/src/controllers/${i}
.endfor

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mixxx
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mixxx/plugins/*/*.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/mixxx/plugins/soundsource
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in Mixxx-Manual.pdf README README.md
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} Mixxx-Manual.pdf \
		${STAGEDIR}${DOCSDIR}
	@${FIND} ${STAGEDIR}${PREFIX}/lib/mixxx/plugins/soundsource -type d -empty -delete

.include <bsd.port.mk>
