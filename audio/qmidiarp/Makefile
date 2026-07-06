PORTNAME=	qmidiarp
DISTVERSIONPREFIX=	qmidiarp-
DISTVERSION=	0.7.4
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MIDI arpeggiator, sequencer and LFO for JACK
WWW=		https://github.com/emuse/qmidiarp \
		https://qmidiarp.sourceforge.net/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsed:textproc/gsed \
		lv2>0:audio/lv2
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		liblo.so:audio/liblo \
		libjack.so:audio/jack

PORTSCOUT=	limit:^qmidiarp

USES=		cmake compiler:c++11-lib desktop-file-utils \
		gl gnome localbase:ldflags libtool pkgconfig qt:6 xorg
USE_QT=		base tools:build
USE_GL=		glu opengl
USE_GNOME=	cairo pango
USE_XORG=	x11
USE_CXXSTD=	c++11

USE_GITHUB=	yes
GH_ACCOUNT=	emuse
GH_TUPLE=	x42:robtk:ec6456e:robtk/robtk

BINARY_ALIAS=	sed=gsed

OPTIONS_DEFINE=		NLS LV2
OPTIONS_DEFAULT=	LV2
OPTIONS_SUB=		yes

LV2_DESC=	Build and install LV2 plugins
LV2_CMAKE_BOOL=	CONFIG_LV2 \
		CONFIG_LV2_UI \
		CONFIG_LV2_UI_RTK

NLS_CMAKE_BOOL=	CONFIG_TRANSLATIONS

.include <bsd.port.mk>
