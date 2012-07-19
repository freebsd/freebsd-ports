# New ports collection makefile for:	Mixxx
# Date created:			25 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	mixxx
PORTVERSION=	1.10.0
PORTREVISION=	3
DISTVERSIONSUFFIX=	-src
CATEGORIES=	audio
MASTER_SITES=	http://mixxx.rasant-records.de/downloads/%SUBDIR%/ \
		http://moo.glines.org/mixxx/%SUBDIR%/ \
		http://web.mit.edu/rryan/www/downloads.mixxx.org/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A DJ mixing application

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		mad.2:${PORTSDIR}/audio/libmad \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		portaudio.2:${PORTSDIR}/audio/portaudio2 \
		tag.1:${PORTSDIR}/audio/taglib

OPTIONS_DEFINE=	LAME FAAD WAVPACK SHOUTCAST DOCS
SHOUTCAST_DESC=	Enable Shoutcast Broadcasting
WAVPACK_DESC=	Enable WavPack audio support plugin

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GL=		glu
USE_QT4=	corelib gui network opengl script sql svg webkit xml \
		xmlpatterns linguist_build moc_build qmake_build rcc_build \
		uic_build
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
		"/('install', docs)/d" ${WRKSRC}/src/SConscript
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
