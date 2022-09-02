PORTNAME=	drumstick
DISTVERSION=	2.7.1
PORTREVISION=	1
CATEGORIES=	audio multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MIDI libraries for Qt/C++

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth \
		libsonivox.so:audio/sonivox
RUN_DEPENDS=	${LOCALBASE}/share/sounds/sf2/FluidR3_GM.sf2:audio/fluid-soundfont

USES=		compiler:c++11-lang cmake desktop-file-utils pkgconfig qt:6 shared-mime-info tar:bz2
USE_QT=		base svg 5compat tools_build
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DUSE_QT=6

OPTIONS_DEFINE=		ALSA PULSEAUDIO MANPAGES
OPTIONS_DEFAULT=	ALSA PULSEAUDIO MANPAGES
OPTIONS_SUB=		yes

ALSA_CMAKE_BOOL=	BUILD_ALSA
ALSA_USES=		localbase
ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib

PULSEAUDIO_CMAKE_BOOL=	USE_PULSEAUDIO
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

MANPAGES_CMAKE_BOOL=	BUILD_DOCS
MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			docbook-xsl>0:textproc/docbook-xsl

post-patch:
	# instead of default.sf2 use FluidR3_GM.sf2 installed by fluid-soundfont
	@${REINPLACE_CMD} -e 's|"default.sf2"|"${LOCALBASE}/share/sounds/sf2/FluidR3_GM.sf2"|' \
		${WRKSRC}/library/widgets/fluidsettingsdialog.cpp

.include <bsd.port.mk>
