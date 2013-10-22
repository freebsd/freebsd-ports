# Created by: Lars Engels <lme@FreeBSD.org>
# $FreeBSD$

PORTNAME=	atunes
PORTVERSION=	3.1.1
CATEGORIES=	audio java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/aTunes%20${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-bin

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Full-featured audio player and manager developed in Java

NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
SUB_FILES=	atunes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=		CDDA2WAV

OPTIONS_MULTI=		ENCODER ENGINE

OPTIONS_MULTI_ENCODER=	LAME VORBIS FLAC
OPTIONS_MULTI_ENGINE=	MPLAYER XINE

OPTIONS_DEFAULT=	MPLAYER CDDA2WAV LAME VORBIS

MPLAYER_DESC=		Engine:  Use Mplayer
XINE_DESC=		Engine:  Use Xine
CDDA2WAV_DESC=		Ripper:  Enable cdrtools support
LAME_DESC=		Encoder: Enable lame MP3 encoder
VORBIS_DESC=		Encoder: Enable vorbis OGG encoder
FLAC_DESC=		Encoder: Enable FLAC encoder

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if ${PORT_OPTIONS:MXINE}
LIB_DEPENDS+=	libxine.so:${PORTSDIR}/multimedia/libxine
.endif

.if ${PORT_OPTIONS:MCDDA2WAV}
RUN_DEPENDS+=	cdda2wav:${PORTSDIR}/sysutils/cdrtools
.endif

.if ${PORT_OPTIONS:MLAME}
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if ${PORT_OPTIONS:MVORBIS}
RUN_DEPENDS+=	ogg123:${PORTSDIR}/audio/vorbis-tools
.endif

.if ${PORT_OPTIONS:MFLAC}
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

DESKTOP_ENTRIES="aTunes" \
		"Audio player and manager" \
		"${PREFIX}/share/pixmaps/atunes.png" \
		"aTunes" \
		"Audio;AudioVideo;Java;" \
		true

INSTALL_FILES=	aTunes.ico aTunes.jar splash.gif changelog.txt

PIXMAPS=	atunes.png

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	@${INSTALL_SCRIPT} ${WRKDIR}/atunes ${STAGEDIR}${PREFIX}/bin
.for file in ${INSTALL_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DATADIR}/${file}
.endfor
	@(cd ${WRKSRC} && ${FIND} lib -type f -name "*.jar" -exec ${INSTALL_DATA} {} \
		${STAGEDIR}${DATADIR}/{} \;)
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} settings ${STAGEDIR}${DATADIR}/)
.for file in ${PIXMAPS}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/share/pixmaps
.endfor

.include <bsd.port.mk>
