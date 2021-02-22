# $FreeBSD$

PORTNAME=	polyphone
DISTVERSION=	2.2.0.20210109
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical user interface for editing soundfont (sf2 and sfz) files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/../LICENSE.txt

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libjack.so:audio/jack \
		libogg.so:audio/libogg \
		libportaudio.so:audio/portaudio \
		libQCustomPlot-qt5.so:graphics/qcustomplot-qt5 \
		librtmidi.so:audio/rtmidi \
		libstk.so:audio/stk \
		libvorbisfile.so:audio/libvorbis

USES=		compiler:c++11-lang desktop-file-utils dos2unix gl gnome pkgconfig qmake:outsource qt:5 shared-mime-info ssl xorg
DOS2UNIX_FILES=	polyphone.pro \
		editor/graphics/graphiquefourier.cpp \
		editor/tree/treeitemdelegate.cpp
USE_GL=		gl
USE_QT=		core concurrent gui network printsupport svg widgets buildtools_build linguisttools_build qmake_build
USE_GNOME=	glib20
USE_CXXSTD=	c++11

USE_GITHUB=	yes
GH_ACCOUNT=	davy7125
GH_TAGNAME=	75a5e88

CXXFLAGS+=	-D__UNIX_JACK__
LIBS+=		-lssl -lcrypto

WRKSRC_SUBDIR=	sources

INSTALLS_ICONS=	yes

post-extract: # unbundle
	@${RM} -r ${WRKSRC}/lib/_option_qcustomplot ${WRKSRC}/lib/_option_rtmidi ${WRKSRC}/lib/_option_stk

.include <bsd.port.mk>
