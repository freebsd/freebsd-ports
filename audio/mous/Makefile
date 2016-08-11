# Created by: Yanhui Shen <shen.elf@gmail.com>
# $FreeBSD$

PORTNAME=	mous
PORTVERSION=	1.1a
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	GHC

MAINTAINER=	shen.elf@gmail.com
COMMENT=	Simple yet powerful audio player

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		cmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	bsdelf

OPTIONS_DEFINE=		ALSA ASSEMBLY FAAC FAAD FLAC LAME AO CUE MAC4DECODER \
			MACDECODER MPG123 NCURSES OSS QT4 SDK TAGLIB VORBIS \
			WAVDECODER WAVENCODER WMA
OPTIONS_DEFAULT=	FAAC FAAD FLAC LAME CUE MAC4DECODER \
			MPG123 NCURSES OSS QT4 TAGLIB VORBIS WAVDECODER \
			WAVENCODER
OPTIONS_DEFAULT_amd64=	ASSEMBLY WMA
OPTIONS_DEFAULT_i386=	ASSEMBLY WMA

OPTIONS_SUB=		yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CMAKE_ON=		-DWithPluginAlsaRenderer=1
ALSA_CMAKE_OFF=		-DWithPluginAlsaRenderer=0

AO_LIB_DEPENDS=		libao.so:audio/libao
AO_CMAKE_ON=		-DWithPluginAoRenderer=1
AO_CMAKE_OFF=		-DWithPluginAoRenderer=0

ASSEMBLY_DESC=		Enable assembly optimizations
ASSEMBLY_BUILD_DEPENDS=	${LOCALBASE}/bin/yasm:devel/yasm
ASSEMBLY_CMAKE_ON=	-DWithAssembly=1
ASSEMBLY_CMAKE_OFF=	-DWithAssembly=0

CUE_LIB_DEPENDS=	libcue.so:textproc/libcue
CUE_CMAKE_ON=		-DWithPluginCuePack=1
CUE_CMAKE_OFF=		-DWithPluginCuePack=0

FAAC_LIB_DEPENDS=	libfaac.so:audio/faac
FAAC_CMAKE_ON=		-DWithPluginFaacEncoder=1
FAAC_CMAKE_OFF=		-DWithPluginFaacEncoder=0

FAAD_LIB_DEPENDS=	libfaad.so:audio/faad
FAAD_CMAKE_ON=		-DWithPluginFaadDecoder=1
FAAD_CMAKE_OFF=		-DWithPluginFaadEncoder=0

FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_CMAKE_ON=		-DWithPluginFlacDecoder=1
FLAC_CMAKE_OFF=		-DWithPluginFlacDecoder=0

LAME_LIB_DEPENDS=	libmp3lame.so:audio/lame
LAME_CMAKE_ON=		-DWithPluginLameEncoder=1
LAME_CMAKE_OFF=		-DWithPluginLameEncoder=0

MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123
MPG123_CMAKE_ON=	-DWithPluginMpg123Decoder=1
MPG123_CMAKE_OFF=	-DWithPluginMpg123Decoder=0

MAC4DECODER_DESC=	Newest mac4.11 decoder (*.ape)
MAC4DECODER_CMAKE_ON=	-DWithPluginMac4Decoder=1
MAC4DECODER_CMAKE_OFF=	-DWithPluginMac4Decoder=0

MACDECODER_DESC=	Old mac3.99 ape decoder (*.ape)
MACDECODER_LIB_DEPENDS=	libmac.so:audio/mac
MACDECODER_CMAKE_ON=	-DWithPluginMacDecoder=1
MACDECODER_CMAKE_OFF=	-DWithPluginMacDecoder=0

NCURSES_DESC=		Ncurses frontend
NCURSES_USES=		ncurses
NCURSES_CMAKE_ON=	-DWithFrontendNcurses=1
NCURSES_CMAKE_OFF=	-DWithFrontendNcurses=0

OSS_CMAKE_ON=		-DWithPluginOssRenderer=1
OSS_CMAKE_OFF=		-DWithPluginOssRenderer=0

QT4_DESC=		QT4 frontend
QT4_USE=		QT4=corelib,gui,linguisttools_build
QT4_USE+=		QT4=qmake_build,moc_build,rcc_build,uic_build
QT4_CMAKE_ON=		-DWithFrontendQt=1
QT4_CMAKE_OFF=		-DWithFrontendQt=0

SDK_DESC=		Install SDK
SDK_CMAKE_ON=		-DWithHeadFiles=1
SDK_CMAKE_OFF=		-DWithHeadFiles=0

TAGLIB_DESC=		TagLib plugin (recommended)
TAGLIB_LIB_DEPENDS=	libtag.so:audio/taglib
TAGLIB_CMAKE_ON=	-DWithPluginTagLibParser=1
TAGLIB_CMAKE_OFF=	-DWithPluginTagLibParser=0

VORBIS_LIB_DEPENDS=	libvorbisfile.so:audio/libvorbis
VORBIS_CMAKE_ON=	-DWithPluginOggDecoder=1
VORBIS_CMAKE_OFF=	-DWithPluginOggDecoder=0

WAVDECODER_DESC=	Decode Wav
WAVDECODER_CMAKE_ON=	-DWithPluginWavDecoder=1
WAVDECODER_CMAKE_OFF=	-DWithPluginWavEncoder=0

WAVENCODER_DESC=	Encode Wav
WAVENCODER_CMAKE_ON=	-DWithPluginWavEncoder=1
WAVENCODER_CMAKE_OFF=	-DWithPluginWavEncoder=0

WMA_DESC=		WMA decoder plugin
WMA_CMAKE_ON=		-DWithPluginWmaDecoder=1
WMA_CMAKE_OFF=		-DWithPluginWmaDecoder=0

post-patch:
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
		-e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/CMakeLists.txt

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mous/*

.include <bsd.port.mk>
