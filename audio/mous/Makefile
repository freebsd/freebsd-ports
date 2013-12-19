# Created by: Yanhui Shen <shen.elf@gmail.com>
# $FreeBSD$

PORTNAME=	mous
PORTVERSION=	1.1a
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://cloud.github.com/downloads/0x02/mous/

MAINTAINER=	shen.elf@gmail.com
COMMENT=	A simple yet powerful audio player

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cmake
NO_STAGE=	yes

OPTIONS_DEFINE=	ALSA ASSEMBLY FAAC FAAD FLAC LAME AO CUE MAC4DECODER \
		MACDECODER MPG123 NCURSES OSS QT4 SDK TAGLIB VORBIS \
		WAVDECODER WAVENCODER WMA
OPTIONS_DEFAULT=	ASSEMBLY FAAC FAAD FLAC LAME CUE MAC4DECODER \
			MPG123 NCURSES OSS QT4 TAGLIB VORBIS WAVDECODER \
			WAVENCODER WMA

ASSEMBLY_DESC=		Enable assembly optimize
MAC4DECODER_DESC=	Newest mac4.11 decoder(*.ape)
MACDECODER_DESC=	Old mac3.99 ape decoder(*.ape)
NCURSES_DESC=		Ncurses frontend
QT4_DESC=		QT4 frontend
SDK_DESC=		Install SDK
TAGLIB_DESC=		TagLib plugin(recommended)
WAVDECODER_DESC=	Decode Wav
WAVENCODER_DESC=	Encode Wav
WMA_DESC=		WMA decoder plugin

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKSRC}/pkg-message

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDK}
CMAKE_ARGS+=	-DWithHeadFiles=1
PLIST_SUB+=	SDK=""
.else
CMAKE_ARGS+=	-DWithHeadFiles=0
PLIST_SUB+=	SDK="@comment "
.endif

.if ${PORT_OPTIONS:MASSEMBLY}
BUILD_DEPENDS+=	${LOCALBASE}/bin/yasm:${PORTSDIR}/devel/yasm
CMAKE_ARGS+=	-DWithAssembly=1
.else
CMAKE_ARGS+=	-DWithAssembly=0
.endif

.if ${PORT_OPTIONS:MNCURSES}
USES+=		ncurses
CMAKE_ARGS+=	-DWithFrontendNcurses=1
PLIST_SUB+=	NCURSES=""
.else
CMAKE_ARGS+=	-DWithFrontendNcurses=0
PLIST_SUB+=	NCURSES="@comment "
.endif

.if ${PORT_OPTIONS:MQT4}
USE_QT4=	gui linguist moc_build qmake_build rcc_build uic_build
CMAKE_ARGS+=	-DWithFrontendQt=1
PLIST_SUB+=	QT4=""
.else
CMAKE_ARGS+=	-DWithFrontendQt=0
PLIST_SUB+=	QT4="@comment "
.endif

.if ${PORT_OPTIONS:MOSS}
CMAKE_ARGS+=	-DWithPluginOssRenderer=1
PLIST_SUB+=	OSS=""
.else
CMAKE_ARGS+=	-DWithPluginOssRenderer=0
PLIST_SUB+=	OSS="@comment "
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	libasound.so:${PORTSDIR}/audio/alsa-lib
CMAKE_ARGS+=	-DWithPluginAlsaRenderer=1
PLIST_SUB+=	ALSA=""
.else
CMAKE_ARGS+=	-DWithPluginAlsaRenderer=0
PLIST_SUB+=	ALSA="@comment "
.endif

.if ${PORT_OPTIONS:MAO}
LIB_DEPENDS+=	libao.so:${PORTSDIR}/audio/libao
CMAKE_ARGS+=	-DWithPluginAoRenderer=1
PLIST_SUB+=	AO=""
.else
CMAKE_ARGS+=	-DWithPluginAoRenderer=0
PLIST_SUB+=	AO="@comment "
.endif

.if ${PORT_OPTIONS:MTAGLIB}
LIB_DEPENDS+=	libtag.so:${PORTSDIR}/audio/taglib
CMAKE_ARGS+=	-DWithPluginTagLibParser=1
PLIST_SUB+=	TAGLIB=""
.else
CMAKE_ARGS+=	-DWithPluginTagLibParser=0
PLIST_SUB+=	TAGLIB="@comment "
.endif

.if ${PORT_OPTIONS:MCUE}
LIB_DEPENDS+=	libcue.so:${PORTSDIR}/textproc/libcue
CMAKE_ARGS+=	-DWithPluginCuePack=1
PLIST_SUB+=	CUE=""
.else
CMAKE_ARGS+=	-DWithPluginCuePack=0
PLIST_SUB+=	CUE="@comment "
.endif

.if ${PORT_OPTIONS:MWAVDECODER}
CMAKE_ARGS+=	-DWithPluginWavDecoder=1
PLIST_SUB+=	WAVDECODER=""
.else
CMAKE_ARGS+=	-DWithPluginWavEncoder=0
PLIST_SUB+=	WAVDECODER="@comment "
.endif

.if ${PORT_OPTIONS:MWAVDECODER}
CMAKE_ARGS+=	-DWithPluginWavEncoder=1
PLIST_SUB+=	WAVENCODER=""
.else
CMAKE_ARGS+=	-DWithPluginWavEncoder=0
PLIST_SUB+=	WAVENCODER="@comment "
.endif

.if ${PORT_OPTIONS:MFAAD}
LIB_DEPENDS+=	libfaad.so:${PORTSDIR}/audio/faad
CMAKE_ARGS+=	-DWithPluginFaadDecoder=1
PLIST_SUB+=	FAAD=""
.else
CMAKE_ARGS+=	-DWithPluginFaadEncoder=0
PLIST_SUB+=	FAAD="@comment "
.endif

.if ${PORT_OPTIONS:MFAAC}
LIB_DEPENDS+=	libfaac.so:${PORTSDIR}/audio/faac
CMAKE_ARGS+=	-DWithPluginFaacEncoder=1
PLIST_SUB+=	FAAC=""
.else
CMAKE_ARGS+=	-DWithPluginFaacEncoder=0
PLIST_SUB+=	FAAC="@comment "
.endif

.if ${PORT_OPTIONS:MMPG123}
LIB_DEPENDS+=	libmpg123.so:${PORTSDIR}/audio/mpg123
CMAKE_ARGS+=	-DWithPluginMpg123Decoder=1
PLIST_SUB+=	MPG123=""
.else
CMAKE_ARGS+=	-DWithPluginMpg123Decoder=0
PLIST_SUB+=	MPG123="@comment "
.endif

.if ${PORT_OPTIONS:MLAME}
LIB_DEPENDS+=	libmp3lame.so:${PORTSDIR}/audio/lame
CMAKE_ARGS+=	-DWithPluginLameEncoder=1
PLIST_SUB+=	LAME=""
.else
CMAKE_ARGS+=	-DWithPluginLameEncoder=0
PLIST_SUB+=	LAME="@comment "
.endif

.if ${PORT_OPTIONS:MWMA}
CMAKE_ARGS+=	-DWithPluginWmaDecoder=1
PLIST_SUB+=	WMA=""
.else
CMAKE_ARGS+=	-DWithPluginWmaDecoder=0
PLIST_SUB+=	WMA="@comment "
.endif

.if ${PORT_OPTIONS:MMAC4DECODER}
CMAKE_ARGS+=	-DWithPluginMac4Decoder=1
PLIST_SUB+=	MAC4=""
.else
CMAKE_ARGS+=	-DWithPluginMac4Decoder=0
PLIST_SUB+=	MAC4="@comment "
.endif

.if ${PORT_OPTIONS:MMACDECODER}
LIB_DEPENDS+=	libmac.so:${PORTSDIR}/audio/mac
CMAKE_ARGS+=	-DWithPluginMacDecoder=1
PLIST_SUB+=	MAC=""
.else
CMAKE_ARGS+=	-DWithPluginMacDecoder=0
PLIST_SUB+=	MAC="@comment "
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	libFLAC.so:${PORTSDIR}/audio/flac
CMAKE_ARGS+=	-DWithPluginFlacDecoder=1
PLIST_SUB+=	FLAC=""
.else
CMAKE_ARGS+=	-DWithPluginFlacDecoder=0
PLIST_SUB+=	FLAC="@comment "
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbisfile.so:${PORTSDIR}/audio/libvorbis
CMAKE_ARGS+=	-DWithPluginOggDecoder=1
PLIST_SUB+=	OGG=""
.else
CMAKE_ARGS+=	-DWithPluginOggDecoder=0
PLIST_SUB+=	OGG="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's|%%DATADIR%%|${DATADIR}|' \
		${WRKSRC}/CMakeLists.txt

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
