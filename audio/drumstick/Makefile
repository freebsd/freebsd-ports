PORTNAME=	drumstick
DISTVERSION=	2.9.0
CATEGORIES=	audio multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MIDI libraries for Qt/C++
WWW=		https://sourceforge.net/projects/drumstick

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++17-lang cmake desktop-file-utils gl pkgconfig qt:6 shared-mime-info tar:bz2
USE_QT=		base svg 5compat tools:build
USE_GL=		gl opengl
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DUSE_QT=6
CMAKE_OFF=	BUILD_TESTING

OPTIONS_DEFINE=		ALSA MANPAGES
OPTIONS_MULTI=			RT_BACKEND
OPTIONS_MULTI_RT_BACKEND=	FLUIDSYNTH NETWORK SONIVOX
OPTIONS_DEFAULT=	ALSA MANPAGES ${OPTIONS_MULTI_RT_BACKEND}
OPTIONS_SUB=		yes

ALSA_CMAKE_BOOL=	BUILD_ALSA
ALSA_USES=		localbase
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

MANPAGES_CMAKE_BOOL=	BUILD_DOCS
MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			docbook-xsl>0:textproc/docbook-xsl

FLUIDSYNTH_DESC=	Build FluidSynth RT backend
FLUIDSYNTH_CMAKE_BOOL=	USE_FLUIDSYNTH
FLUIDSYNTH_RUN_DEPENDS=	${LOCALBASE}/share/sounds/sf2/FluidR3_GM.sf2:audio/fluid-soundfont
FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

NETWORK_DESC=		Build Network RT backend
NETWORK_CMAKE_BOOL=	USE_NETWORK # QtNetwork is used

SONIVOX_DESC=		Build FluidSynth RT backend
SONIVOX_CMAKE_BOOL=	USE_SONIVOX USE_PULSEAUDIO # these two options have to be always equal
SONIVOX_LIB_DEPENDS=	libpulse.so:audio/pulseaudio \
			libsonivox.so:audio/sonivox

post-patch:
	# instead of default.sf2 use FluidR3_GM.sf2 installed by fluid-soundfont
	@${REINPLACE_CMD} -e 's|"default.sf2"|"${LOCALBASE}/share/sounds/sf2/FluidR3_GM.sf2"|' \
		${WRKSRC}/library/rt-backends/fluidsynth/fluidsynthengine.cpp

.include <bsd.port.mk>
