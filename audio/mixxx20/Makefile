# $FreeBSD$

PORTNAME=	mixxx
PORTVERSION=	2.0.0
DISTVERSIONSUFFIX=	-src
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://downloads.mixxx.org/${PORTNAME}-${PORTVERSION}/
PKGNAMESUFFIX=	20

MAINTAINER=	acm@FreeBSD.org
COMMENT=	DJ mixing application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BROKEN_aarch64=		fails to compile: Exception("invalid machine type")
BROKEN_powerpc64=	fails to configure: unmet dependencies: Could not find libprotobuf, libchromaprint, libmp4, and libwavpack

LIB_DEPENDS=	libchromaprint.so:audio/chromaprint \
		libFLAC.so:audio/flac \
		libid3tag.so:audio/libid3tag \
		libmad.so:audio/libmad \
		libportaudio.so:audio/portaudio \
		librubberband.so:audio/rubberband \
		libsndfile.so:audio/libsndfile \
		libvamp-sdk.so:audio/vamp-plugin-sdk \
		libvorbisfile.so:audio/libvorbis \
		libtag.so:audio/taglib \
		libprotobuf.so:devel/protobuf

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		compiler:c++11-lang iconv pkgconfig qt:4 scons
USE_CXXSTD=	c++11
USE_QT=		corelib gui network opengl script scripttools sql sql-sqlite3 \
		svg testlib xml xmlpatterns linguisttools_build moc_build \
		qmake_build rcc_build uic_build
USE_GL=		gl glu
MAKE_ARGS=	qtdir="${PREFIX}" install_root="${PREFIX}" \
		build=release optimize=native
LATE_INSTALL_ARGS=	--install-sandbox=${STAGEDIR}

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS FAAD GPERFTOOLS HID LAME OPUS SHOUTCAST WAVPACK
OPTIONS_DEFAULT=	FAAD HID SHOUTCAST OPUS WAVPACK
OPTIONS_SUB=		yes

FAAD_LIB_DEPENDS=	libfaad.so:audio/faad \
			libmp4v2.so:multimedia/mp4v2
FAAD_MAKE_ARGS=		faad=1
FAAD_MAKE_ARGS_OFF=	faad=0
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
		 s|^Icon=.*|Icon=${PREFIX}/share/pixmaps/mixxx-icon.png|" \
		${WRKSRC}/res/linux/mixxx.desktop
.for i in midi/midimessage.h qtscript-bytearray/bytearrayclass.h
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
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/doc/HID
.for i in *.odt *.pdf
	(cd ${WRKSRC}/doc/HID && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR}/doc/HID)
.endfor

.include <bsd.port.mk>
