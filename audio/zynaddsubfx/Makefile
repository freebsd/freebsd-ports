# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	zynaddsubfx
PORTVERSION=	2.4.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	ZynAddSubFX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Realtime software synthesizer

LICENSE=	GPLv2

LIB_DEPENDS=	fftw3:${PORTSDIR}/math/fftw3 \
		mxml:${PORTSDIR}/textproc/mxml

USE_BZIP2=	yes
USES=		cmake pkgconfig

OPTIONS_DEFINE=	DOCS EXAMPLES GUI LASH LO JACK PORTAUDIO
OPTIONS_DEFAULT=	GUI PORTAUDIO
OPTIONS_RADIO=		AUDIO
OPTIONS_RADIO_AUDIO=	ALSAMIDI DSSI
OPTIONS_SUB=		yes

ALSAMIDI_DESC=	MIDI input through ALSA
DSSI_DESC=	DSSI Plugin
LO_DESC=	Open Sound Control support via LibLO

ALSAMIDI_LIB_DEPENDS=		libasound.so:${PORTSDIR}/audio/alsa-lib
ALSAMIDI_CMAKE_OFF=		-DAlsaEnable:BOOL=OFF

DSSI_LIB_DEPENDS=		libdssialsacompat.so:${PORTSDIR}/audio/libdssialsacompat
DSSI_BUILD_DEPENDS=		dssi>0:${PORTSDIR}/audio/dssi
DSSI_RUN_DEPENDS=		dssi>0:${PORTSDIR}/audio/dssi
DSSI_CFLAGS=			-I${LOCALBASE}/include/dssi
DSSI_CMAKE_OFF=			-DDssiEnable:BOOL=OFF

GUI_LIB_DEPENDS=		libfltk.so:${PORTSDIR}/x11-toolkits/fltk
GUI_ON=				-DGuiModule:STRING=fltk
GUI_CMAKE_OFF=			-DGuiModule:STRING=OFF

LO_LIB_DEPENDS=			liblo.so:${PORTSDIR}/audio/liblo
LO_CMAKE_OFF=			-DLibloEnable:BOOL=OFF

LASH_LIB_DEPENDS=		liblash.so:${PORTSDIR}/audio/lash
LASH_CMAKE_OFF=			-DLashEnabe:BOOL=OFF

JACK_LIB_DEPENDS=		libjack.so:${PORTSDIR}/audio/jack
JACK_CMAKE_OFF=			-DJackEnable:BOOL=OFF

PORTAUDIO_BUILD_DEPENDS=	portaudio2>=0:${PORTSDIR}/audio/portaudio2
PORTAUDIO_RUN_DEPENDS=		portaudio2>=0:${PORTSDIR}/audio/portaudio2
PORTAUDIO_CFLAGS=		-I${LOCALBASE}/include/portaudio2
PORTAUDIO_CMAKE_OFF=		-DPaEnabe:BOOL=OFF
PORTAUDIO_LDFLAGS=		${LOCALBASE}/lib/portaudio2/libportaudio.so

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS.txt ChangeLog FAQ.txt HISTORY.txt README.txt

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	adsynth.txt controller.txt envelope.txt filter.txt intro.txt \
		lfo.txt mididefaults.txt nrpn.txt saving.txt zynaddsubfx.txt

DOCSRCDIR3=	${WRKSRC}/doc/images
DOCSDIR3=	${DOCSDIR}/doc/images
DOC_FILES3=	*.png *.jpg

PORTEXAMPLES=	*

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
	@${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|' ${WRKSRC}/src/Misc/Config.cpp
	@${REINPLACE_CMD} -e 's|portaudio.h|portaudio2/portaudio.h|' ${WRKSRC}/src/Nio/PaEngine.h


post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/banks
	(cd ${WRKDIR}/${DISTNAME}/instruments/banks \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/banks)

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}
	@${MKDIR} ${STAGEDIR}${DOCSDIR3}
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${STAGEDIR}${DOCSDIR3}

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@(cd ${WRKSRC}/instruments/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.post.mk>
