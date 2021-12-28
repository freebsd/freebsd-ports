# Created by: trasz <trasz@pin.if.uz.zgora.pl>

PORTNAME=	zynaddsubfx
DISTVERSION=	3.0.6-rc5
PORTEPOCH=	1
PORTREVISION=	3
CATEGORIES=	audio

MAINTAINER=	hselasky@FreeBSD.org
COMMENT=	Realtime software synthesizer

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/fftw3.h:math/fftw3

LIB_DEPENDS=	libfftw3f.so:math/fftw3-float \
		libmxml.so:textproc/mxml \
		liblo.so:audio/liblo

USES=		cmake:insource compiler:c++11-lang pkgconfig tar:bzip2
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_TUPLE=	DISTRHO:DPF:86a621bfd86922a49ce593fec2a618a1e0cc6ef3:d/DPF \
		fundamental:rtosc:75a58931f633ce77b08ce5ef86d7db58434af3ac:e/rtosc \
		zynaddsubfx:instruments:c5c912131b31df5fdf372d2f06a25aaf2375837f:f/instruments

OPTIONS_DEFINE=		BASH OSS JACK GUI PORTAUDIO SNDIO LASH DOCS EXAMPLES
OPTIONS_DEFAULT=	OSS JACK GUI PORTAUDIO
OPTIONS_RADIO=		AUDIO
OPTIONS_RADIO_AUDIO=	ALSAMIDI DSSI
OPTIONS_SUB=		yes

ALSAMIDI_DESC=	MIDI input through ALSA
DSSI_DESC=	DSSI Plugin

ALSAMIDI_LIB_DEPENDS=		libasound.so:audio/alsa-lib
ALSAMIDI_CMAKE_OFF=		-DAlsaEnable:BOOL=OFF

BASH_DESC=			Support for bash auto-completion
BASH_BUILD_DEPENDS=		bash-completion>=0:shells/bash-completion

DSSI_LIB_DEPENDS=		libdssialsacompat.so:audio/libdssialsacompat
DSSI_BUILD_DEPENDS=		dssi>0:audio/dssi
DSSI_RUN_DEPENDS=		dssi>0:audio/dssi
DSSI_CFLAGS=			-I${LOCALBASE}/include/dssi
DSSI_CMAKE_OFF=			-DDssiEnable:BOOL=OFF

GUI_LIB_DEPENDS=		libntk.so:x11-toolkits/ntk \
				libpng.so:graphics/png \
				libfontconfig.so:x11-fonts/fontconfig
GUI_CMAKE_ON=			-DGuiModule:STRING=ntk
GUI_CMAKE_OFF=			-DGuiModule:STRING=OFF
GUI_USE+=			XORG=x11,xext,xfixes,xcursor,xrender,ice,sm,xpm,xinerama,xft
GUI_USE+=			GL=gl,glu
GUI_USES=			gl gnome jpeg xorg

OSS_CMAKE_ON=			-DOssEnable:BOOL=ON
OSS_CMAKE_OFF=			-DOssEnable:BOOL=OFF

LASH_LIB_DEPENDS=		liblash.so:audio/lash
LASH_CMAKE_OFF=			-DLashEnable:BOOL=OFF

JACK_LIB_DEPENDS=		libjack.so:audio/jack
JACK_CMAKE_OFF=			-DJackEnable:BOOL=OFF

PORTAUDIO_LIB_DEPENDS=		libportaudio.so:audio/portaudio
PORTAUDIO_CMAKE_OFF=		-DPaEnable:BOOL=OFF

SNDIO_LIB_DEPENDS=		libsndio.so:audio/sndio
SNDIO_CMAKE_OFF=		-DSndioEnable:BOOL=OFF

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS.txt NEWS.txt

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	adsynth.txt controller.txt envelope.txt filter.txt intro.txt \
		lfo.txt mididefaults.txt nrpn.txt saving.txt zynaddsubfx.txt

DOCSRCDIR3=	${WRKSRC}/doc/images
DOCSDIR3=	${DOCSDIR}/doc/images
DOC_FILES3=	*.png *.jpg

PORTEXAMPLES=	*

CMAKE_ARGS+=	-DZYN_DATADIR:STRING=${DATADIR}
CMAKE_ARGS+=	-DZYN_EXAMPLESDIR:STRING=${EXAMPLESDIR}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${ARCH} == "amd64"
CFLAGS+=	-DASM_F2I_YES
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-O3 .* -fomit-frame-pointer|| ; \
		 /-DASM_F2I_YES/d ; \
		 /-g #/d' ${WRKSRC}/src/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/banks \
		${STAGEDIR}${DOCSDIR} \
		${STAGEDIR}${DOCSDIR2} \
		${STAGEDIR}${DOCSDIR3} \
		${STAGEDIR}${EXAMPLESDIR}

	(cd ${WRKSRC}/instruments/banks && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/banks)
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES3:S|^|${DOCSRCDIR3}/|} ${STAGEDIR}${DOCSDIR3}

.include <bsd.port.post.mk>
