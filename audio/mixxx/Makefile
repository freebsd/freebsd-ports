# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	mixxx
PORTVERSION=	1.11.0
PORTREVISION=	1
DISTVERSIONSUFFIX=	-src
CATEGORIES=	audio
MASTER_SITES=	http://downloads.mixxx.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DJ mixing application

LICENSE=	GPLv2 # (or later)

BUILD_DEPENDS=	portaudio>=19:${PORTSDIR}/audio/portaudio2
LIB_DEPENDS=	FLAC:${PORTSDIR}/audio/flac \
		id3tag:${PORTSDIR}/audio/libid3tag \
		mad:${PORTSDIR}/audio/libmad \
		sndfile:${PORTSDIR}/audio/libsndfile \
		vorbis:${PORTSDIR}/audio/libvorbis \
		tag:${PORTSDIR}/audio/taglib \
		protobuf:${PORTSDIR}/devel/protobuf
RUN_DEPENDS=	portaudio>=19:${PORTSDIR}/audio/portaudio2

OPTIONS_DEFINE=	FAAD LAME SHOUTCAST TCMALLOC WAVPACK DOCS
TCMALLOC_DESC=	Use Google's TCMalloc

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_STAGE=	yes
USE_QT4=	corelib gui network opengl script sql svg xml \
		linguist_build moc_build qmake_build rcc_build uic_build
USE_GL=		glu
USE_SCONS=	yes
SCONS_BUILDENV=	${SCONS_ENV}
SCONS_ARGS=	qtdir="${QT_PREFIX}" optimize=0

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFAAD}
LIB_DEPENDS+=	faad:${PORTSDIR}/audio/faad \
		mp4v2:${PORTSDIR}/multimedia/mp4v2
SCONS_ARGS+=	faad=1
PLIST_SUB+=	FAAD=""
.else
SCONS_ARGS+=	faad=0
PLIST_SUB+=	FAAD="@comment "
.endif

.if ${PORT_OPTIONS:MLAME}
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if ${PORT_OPTIONS:MSHOUTCAST}
LIB_DEPENDS+=	shout:${PORTSDIR}/audio/libshout2
SCONS_ARGS+=	shoutcast=1
.else
SCONS_ARGS+=	shoutcast=0
.endif

.if ${PORT_OPTIONS:MTCMALLOC}
LIB_DEPENDS+=	tcmalloc:${PORTSDIR}/devel/google-perftools
SCONS_ARGS+=	perftools=1
.else
SCONS_ARGS+=	perftools=0
.endif

.if ${PORT_OPTIONS:MWAVPACK}
LIB_DEPENDS+=	wavpack:${PORTSDIR}/audio/wavpack
SCONS_ARGS+=	wv=1
PLIST_SUB+=	WAVPACK=""
.else
SCONS_ARGS+=	wv=0
PLIST_SUB+=	WAVPACK="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g ; \
		 s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/build/depends.py
	@${REINPLACE_CMD} -e "/('install', docs)/d" \
		${WRKSRC}/src/SConscript
	@${REINPLACE_CMD} -e "s|^Exec=.*|Exec=mixxx| ; \
		 s|^Icon=.*|Icon=${PREFIX}/share/pixmaps/mixxx-icon.png|" \
		${WRKSRC}/src/mixxx.desktop
.for i in midi/midimessage.h qtscript-bytearray/bytearrayclass.h
	@${ECHO_CMD} >> ${WRKSRC}/src/controllers/${i}
.endfor

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/mixxx
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in Mixxx-Manual.pdf README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
