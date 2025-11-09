PORTNAME=	qmidiarp
DISTVERSIONPREFIX=	qmidiarp-
DISTVERSION=	0.7.1
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

USES=		autoreconf compiler:c++11-lib desktop-file-utils \
		gl gmake gnome localbase:ldflags libtool pkgconfig qt:5 xorg
USE_QT=		core gui network widgets buildtools:build \
		linguisttools:build
USE_GL=		glu opengl
USE_GNOME=	cairo pango
USE_XORG=	x11
USE_CXXSTD=	c++11

USE_GITHUB=	yes
GH_ACCOUNT=	emuse
GH_TUPLE=	x42:robtk:ec6456e:robtk/robtk

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--enable-qt5 --enable-translations=yes

CXXFLAGS+=	-Duint=uint32_t # workaround for https://sourceforge.net/p/qmidiarp/bugs/27/

BINARY_ALIAS=	sed=gsed

OPTIONS_DEFINE=	NLS LV2
OPTIONS_DEFAULT=LV2
OPTIONS_SUB=	yes

LV2_DESC=	Build and install LV2 plugins
LV2_CONFIGURE_OFF=	--disable-lv2plugins

NLS_CONFIGURE_ON=	--enable-translations

post-install-LV2-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/qmidiarp_[lsa][fer][oqp].lv2/*.so

.include <bsd.port.mk>
