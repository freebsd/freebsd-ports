# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	zynaddsubfx
PORTVERSION=	2.4.3
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	ZynAddSubFX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Realtime software synthesizer

LICENSE=	GPLv2

LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3 \
		mxml:${PORTSDIR}/textproc/mxml

OPTIONS_DEFINE=	ALSAMIDI DSSI GUI LASH LO JACK PORTAUDIO DOCS EXAMPLES
OPTIONS_DEFAULT=	GUI
ALSAMIDI_DESC=	MIDI input through ALSA
DSSI_DESC=	DSSI Plugin
LO_DESC=	Open Sound Control support via LibLO

USE_BZIP2=	yes
USES=		cmake

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MALSAMIDI}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
.else
CMAKE_ARGS+=	-DAlsaEnable:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MDSSI}
BUILD_DEPENDS+=	dssi>0:${PORTSDIR}/audio/dssi
LIB_DEPENDS+=	dssialsacompat:${PORTSDIR}/audio/libdssialsacompat
RUN_DEPENDS+=	dssi>0:${PORTSDIR}/audio/dssi
CFLAGS+=	-I${LOCALBASE}/include/dssi
PLIST_SUB+=	DSSI=""
.else
CMAKE_ARGS+=	-DDssiEnable:BOOL=OFF
PLIST_SUB+=	DSSI="@comment "
.endif

.if ${PORT_OPTIONS:MGUI}
LIB_DEPENDS+=	fltk:${PORTSDIR}/x11-toolkits/fltk
CMAKE_ARGS+=	-DGuiModule:STRING=fltk
.else
CMAKE_ARGS+=	-DGuiModule:STRING=OFF
.endif

.if ${PORT_OPTIONS:MJACK}
LIB_DEPENDS+=	jack:${PORTSDIR}/audio/jack
.else
CMAKE_ARGS+=	-DJackEnable:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MLASH}
LIB_DEPENDS+=	lash:${PORTSDIR}/audio/lash
.else
CMAKE_ARGS+=	-DLashEnable:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MLO}
LIB_DEPENDS+=	lo:${PORTSDIR}/audio/liblo
.else
CMAKE_ARGS+=	-DLibloEnable:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MPORTAUDIO}
BUILD_DEPENDS+=	portaudio>=19:${PORTSDIR}/audio/portaudio2
RUN_DEPENDS+=	portaudio>=19:${PORTSDIR}/audio/portaudio2
CFLAGS+=	-I${LOCALBASE}/include/portaudio2
LDFLAGS+=	${LOCALBASE}/lib/portaudio2/libportaudio.so
.else
CMAKE_ARGS+=	-DPaEnable:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MALSAMIDI} && ${PORT_OPTIONS:MDSSI}
IGNORE=		selected mutually exclusive options: ALSAMIDI and DSSI
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64: invokes i386 asm
.endif

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
CFLAGS+=	-DASM_F2I_YES
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/FILES/s|^|#| ; \
		 /DESTINATION/s|^|#| ; \
		 /[[:blank:]])/s|^|#|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|-O3 .* -fomit-frame-pointer|| ; \
		 /-DASM_F2I_YES/d ; \
		 /-g #/d ; \
		 /pthread/d ; \
		 s|lib64|lib|' ${WRKSRC}/src/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/src/Misc/Config.cpp

post-install:
	@${MKDIR} ${DATADIR}/banks
	@(cd ${WRKDIR}/${DISTNAME}/instruments/banks \
		&& ${COPYTREE_SHARE} . ${DATADIR}/banks)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS.txt FAQ.txt HISTORY.txt README.txt
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKDIR}/${DISTNAME}/instruments/examples \
		&& ${INSTALL_DATA} * ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
