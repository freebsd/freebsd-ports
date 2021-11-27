PORTNAME=	drumstick
DISTVERSION=	2.4.0
PORTREVISION=	2
CATEGORIES=	audio multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MIDI libraries for Qt5/C++

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
RUN_DEPENDS=	${LOCALBASE}/share/sounds/sf2/FluidR3_GM.sf2:audio/fluid-soundfont

USES=		compiler:c++11-lang cmake pkgconfig qt:5 shared-mime-info tar:bz2
USE_QT=		core gui network svg testlib uiplugin widgets buildtools_build linguisttools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		PULSEAUDIO MANPAGES
OPTIONS_DEFAULT=	PULSEAUDIO MANPAGES
OPTIONS_SUB=		yes

PULSEAUDIO_CMAKE_BOOL=	USE_PULSEAUDIO
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

MANPAGES_CMAKE_BOOL=	BUILD_DOCS
MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			docbook-xsl>0:textproc/docbook-xsl

post-patch:
	# instead of default.sf2 use FluidR3_GM.sf2 installed by fluid-soundfont
	@${REINPLACE_CMD} -e 's|"default.sf2"|"${LOCALBASE}/share/sounds/sf2/FluidR3_GM.sf2"|' \
		${WRKSRC}/library/widgets/fluidsettingsdialog.cpp \
		${WRKSRC}/library/rt-backends/fluidsynth/synthengine.cpp

.include <bsd.port.mk>
