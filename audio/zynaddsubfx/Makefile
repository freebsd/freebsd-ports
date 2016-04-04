# Created by: trasz <trasz@pin.if.uz.zgora.pl>
# $FreeBSD$

PORTNAME=	zynaddsubfx
PORTVERSION=	2.4.3
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF
DISTNAME=	ZynAddSubFX-${PORTVERSION}

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Realtime software synthesizer

LICENSE=	GPLv2

LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libmxml.so:textproc/mxml

USES=		tar:bzip2 cmake pkgconfig

OPTIONS_DEFINE=		JACK GUI PORTAUDIO LASH LO DOCS EXAMPLES
OPTIONS_DEFAULT=	JACK GUI PORTAUDIO
OPTIONS_RADIO=		AUDIO
OPTIONS_RADIO_AUDIO=	ALSAMIDI DSSI
OPTIONS_SUB=		yes

ALSAMIDI_DESC=	MIDI input through ALSA
DSSI_DESC=	DSSI Plugin
LO_DESC=	Open Sound Control support via LibLO

ALSAMIDI_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSAMIDI_CMAKE_OFF=		-DAlsaEnable:BOOL=OFF

DSSI_LIB_DEPENDS=		libdssialsacompat.so:audio/libdssialsacompat
DSSI_BUILD_DEPENDS=		dssi>0:audio/dssi
DSSI_RUN_DEPENDS=		dssi>0:audio/dssi
DSSI_CFLAGS=			-I${LOCALBASE}/include/dssi
DSSI_CMAKE_OFF=			-DDssiEnable:BOOL=OFF

GUI_LIB_DEPENDS=		libfltk.so:x11-toolkits/fltk
GUI_ON=				-DGuiModule:STRING=fltk
GUI_CMAKE_OFF=			-DGuiModule:STRING=OFF

LO_LIB_DEPENDS=			liblo.so:audio/liblo
LO_CMAKE_OFF=			-DLibloEnable:BOOL=OFF

LASH_LIB_DEPENDS=		liblash.so:audio/lash
LASH_CMAKE_OFF=			-DLashEnabe:BOOL=OFF

JACK_LIB_DEPENDS=		libjack.so:audio/jack
JACK_CMAKE_OFF=			-DJackEnable:BOOL=OFF

PORTAUDIO_LIB_DEPENDS=		libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_OFF=		-DPaEnabe:BOOL=OFF
PORTAUDIO_LDFLAGS=		-lportaudio

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

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/banks \
		${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${DOCSDIR2} \
		${STAGEDIR}${DOCSDIR3} \
		${STAGEDIR}${EXAMPLESDIR}

	(cd ${WRKDIR}/${DISTNAME}/instruments/banks && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/banks)
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${STAGEDIR}${DOCSDIR3}
	(cd ${WRKSRC}/instruments/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.post.mk>
