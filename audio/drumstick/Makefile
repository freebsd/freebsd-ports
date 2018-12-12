# $FreeBSD$

PORTNAME=	drumstick
DISTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	audio multimedia
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MIDI libraries for Qt5/C++

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
RUN_DEPENDS=	${LOCALBASE}/share/sounds/sf2/FluidR3_GM.sf2:audio/fluid-soundfont

USES=		compiler:c++11-lang cmake:outsource pkgconfig qt:5 shared-mime-info tar:bz2
USE_QT=		core gui network svg testlib widgets buildtools_build qmake_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=		PULSEAUDIO MANPAGES
OPTIONS_DEFAULT=	PULSEAUDIO MANPAGES
OPTIONS_SUB=		yes
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
PULSEAUDIO_CMAKE_BOOL=	USE_PULSEAUDIO
MANPAGES_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
			docbook-xsl>0:textproc/docbook-xsl
MANPAGES_CMAKE_BOOL=	BUILD_DOCS

PLIST_SUB=	SHL3=${PORTVERSION} SHL1=${PORTVERSION:R:R}

post-patch:
	@${REINPLACE_CMD} -e 's|"default.sf2"|"${LOCALBASE}/share/sounds/sf2/FluidR3_GM.sf2"|' \
		${WRKSRC}/utils/vpiano/fluidsettingsdialog.cpp \
		${WRKSRC}/library/rt-backends/synth/synthengine.cpp
	@${REINPLACE_CMD} -e 's|"$${CMAKE_INSTALL_DATAROOTDIR}/man/man1"|"${PREFIX}/man/man1"|' \
		${WRKSRC}/cmake_admin/CreateManpages.cmake

.include <bsd.port.mk>
