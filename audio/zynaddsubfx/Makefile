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

OPTIONS_DEFINE=	GUI LASH LO JACK PORTAUDIO DOCS EXAMPLES
OPTIONS_DEFAULT=	GUI
OPTIONS_RADIO=		AUDIO
OPTIONS_RADIO_AUDIO=	ALSAMIDI DSSI
OPTIONS_SUB=		yes

ALSAMIDI_DESC=	MIDI input through ALSA
DSSI_DESC=	DSSI Plugin
LO_DESC=	Open Sound Control support via LibLO

ALSAMIDI_CMAKE_OFF=		-DAlsaEnable:BOOL=OFF
ALSAMIDI_LIB_DEPENDS=		asound:${PORTSDIR}/audio/alsa-lib
DSSI_BUILD_DEPENDS=		dssi>0:${PORTSDIR}/audio/dssi
DSSI_CFLAGS=			-I${LOCALBASE}/include/dssi
DSSI_CMAKE_OFF=			-DDssiEnable:BOOL=OFF
DSSI_LIB_DEPENDS=		dssialsacompat:${PORTSDIR}/audio/libdssialsacompat
DSSI_RUN_DEPENDS=		dssi>0:${PORTSDIR}/audio/dssi
GUI_CMAKE_OFF=			-DGuiModule:STRING=OFF
GUI_LIB_DEPENDS=		fltk:${PORTSDIR}/x11-toolkits/fltk
GUI_ON=				-DGuiModule:STRING=fltk
JACK_CMAKE_OFF=			-DJackEnable:BOOL=OFF
JACK_LIB_DEPENDS=		jack:${PORTSDIR}/audio/jack
LASH_CMAKE_OFF=			-DLashEnabe:BOOL=OFF
LASH_LIB_DEPENDS=		lash:${PORTSDIR}/audio/lash
LO_CMAKE_OFF=			-DLibloEnable:BOOL=OFF
LO_LIB_DEPENDS=			lo:${PORTSDIR}/audio/liblo
PORTAUDIO_BUILD_DEPENDS=	portaudio>=19:${PORTSDIR}/audio/portaudio2
PORTAUDIO_CFLAGS=		-I${LOCALBASE}/include/portaudio2
PORTAUDIO_CMAKE_OFF=		-DPaEnabe:BOOL=OFF
PORTAUDIO_LDFLAGS=		${LOCALBASE}/lib/portaudio2/libportaudio.so
PORTAUDIO_RUN_DEPENDS=		portaudio>=19:${PORTSDIR}/audio/portaudio2

USE_BZIP2=	yes
USES=		cmake pkgconfig

.include <bsd.port.options.mk>
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
	${MKDIR} ${STAGEDIR}${DATADIR}/banks
	(cd ${WRKDIR}/${DISTNAME}/instruments/banks \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/banks)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS.txt FAQ.txt HISTORY.txt README.txt
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKDIR}/${DISTNAME}/instruments/examples \
		&& ${INSTALL_DATA} * ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.post.mk>
