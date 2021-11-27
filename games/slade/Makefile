# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	slade
PORTVERSION=	3.1.13
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Modern editor for Doom-engine based games and source ports

LICENSE=	GPLv2

BUILD_DEPENDS=	zip:archivers/zip
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libfreeimage.so:graphics/freeimage \
		libfreetype.so:print/freetype2 \
		libftgl.so:graphics/ftgl \
		libsfml-system.so:devel/sfml

USE_GITHUB=	yes
GH_ACCOUNT=	sirjuddington
GH_PROJECT=	${PORTNAME:tu}

USES=		cmake compiler:c++14-lang gl pkgconfig
USE_WX=		3.0
USE_GL=		gl glew glu

CMAKE_ARGS=	-DwxWidgets_CONFIG_EXECUTABLE:FILEPATH="${WX_CONFIG}" \
		-DNO_WEBVIEW:BOOL=ON

PLIST_FILES=	bin/slade share/slade3/slade.pk3 \
		share/applications/net.mancubus.SLADE.desktop \
		share/metainfo/net.mancubus.SLADE.metainfo.xml \
		share/icons/net.mancubus.SLADE.png

OPTIONS_DEFINE=	FLUIDSYNTH GTK3
OPTIONS_DEFAULT=	FLUIDSYNTH

FLUIDSYNTH_LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth
FLUIDSYNTH_RUN_DEPENDS=	${LOCALBASE}/share/sounds/sf2/FluidR3_GM.sf2:audio/fluid-soundfont
FLUIDSYNTH_CMAKE_OFF=	-DNO_FLUIDSYNTH:BOOL=ON

GTK3_CMAKE_OFF=		-DWX_GTK3:BOOL=OFF
GTK3_VARS_OFF=		WANT_WXGTK_VER=2

post-patch:
	@${REINPLACE_CMD} -e 's,"alsa","oss", ; \
		/share\/sounds\/sf2/s,/usr,${LOCALBASE},g' \
			${WRKSRC}/src/Audio/MIDIPlayer.cpp
	@${REINPLACE_CMD} -e 's,OpenBSD,${OPSYS},' \
		${WRKSRC}/src/External/zreaders/portable_endian.h
	@${REINPLACE_CMD} -e 's,wxVSCROLL,static_cast<long>(&),' \
		${WRKSRC}/src/MapEditor/UI/Dialogs/ActionSpecialDialog.cpp

.include <bsd.port.mk>
