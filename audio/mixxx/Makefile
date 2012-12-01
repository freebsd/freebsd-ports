# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	mixxx
PORTVERSION=	1.10.1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	audio
MASTER_SITES=	http://moo.glines.org/mixxx/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A DJ mixing application

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	portaudio>=19:${PORTSDIR}/audio/portaudio2
LIB_DEPENDS=	FLAC:${PORTSDIR}/audio/flac \
		id3tag:${PORTSDIR}/audio/libid3tag \
		mad:${PORTSDIR}/audio/libmad \
		sndfile:${PORTSDIR}/audio/libsndfile \
		vorbis:${PORTSDIR}/audio/libvorbis \
		tag:${PORTSDIR}/audio/taglib
RUN_DEPENDS=	portaudio>=19:${PORTSDIR}/audio/portaudio2

OPTIONS_DEFINE=	LAME SHOUTCAST FAAD WAVPACK DOCS
SHOUTCAST_DESC=	Shoutcast Broadcasting
WAVPACK_DESC=	WavPack audio support plugin

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_QT4=	corelib gui network opengl script sql svg webkit xml \
		xmlpatterns linguist_build moc_build qmake_build rcc_build \
		uic_build
USE_GL=		glu
USE_SCONS=	yes
SCONS_BUILDENV=	${SCONS_ENV}
SCONS_ARGS=	qtdir="${QT_PREFIX}" optimize=0
MAKE_JOBS_SAFE=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLAME}
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if ${PORT_OPTIONS:MSHOUTCAST}
LIB_DEPENDS+=	shout.5:${PORTSDIR}/audio/libshout2
SCONS_ARGS+=	shoutcast=1
.else
SCONS_ARGS+=	shoutcast=0
.endif

.if ${PORT_OPTIONS:MFAAD}
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad \
		mp4v2.10:${PORTSDIR}/multimedia/mp4v2
SCONS_ARGS+=	faad=1
PLIST_SUB+=	FAAD=""
.else
SCONS_ARGS+=	faad=0
PLIST_SUB+=	FAAD="@comment "
.endif

.if ${PORT_OPTIONS:MWAVPACK}
LIB_DEPENDS+=	wavpack.2:${PORTSDIR}/audio/wavpack
SCONS_ARGS+=	wv=1
PLIST_SUB+=	WAVPACK=""
.else
SCONS_ARGS+=	wv=0
PLIST_SUB+=	WAVPACK="@comment "
.endif

post-patch:
.for FILE in build/depends.py src/soundsourceproxy.cpp src/recording/encodermp3.cpp
	@${REINPLACE_CMD} -e \
		"s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${FILE}
.endfor
	@${REINPLACE_CMD} -e \
		"/_get_bzr_/s|^|#| ; \
		 /('install', docs)/d" ${WRKSRC}/src/SConscript
	@${REINPLACE_CMD} -e \
		"s|^Exec=.*|Exec=mixxx|" ${WRKSRC}/src/mixxx.desktop

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/mixxx
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for FILE in Mixxx-Manual.pdf README
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
