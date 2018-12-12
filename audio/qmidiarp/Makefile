# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	qmidiarp
DISTVERSIONPREFIX=	qmidiarp-
DISTVERSION=	0.6.5
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	MIDI arpeggiator, sequencer and LFO for JACK

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	lv2>0:audio/lv2
LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		liblo.so:audio/liblo \
		libjack.so:audio/jack

PORTSCOUT=	limit:^qmidiarp

USES=		autoreconf compiler:c++11-lib desktop-file-utils \
		gmake localbase libtool pkgconfig qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	emuse
USE_QT=		core gui network widgets buildtools_build \
		linguisttools_build
USE_CXXSTD=	c++11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-qt5 --enable-translations=yes
INSTALLS_ICONS=	yes

CXXFLAGS+=	-Duint=uint32_t # workaround for https://sourceforge.net/p/qmidiarp/bugs/27/

OPTIONS_DEFINE=	NLS LV2
OPTIONS_DEFAULT=LV2
OPTIONS_SUB=	yes

LV2_DESC=	Build and install LV2 plugins
LV2_CONFIGURE_OFF=	--disable-lv2plugins

NLS_CONFIGURE_ON=	--enable-translations

post-install-LV2-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lv2/qmidiarp_[lsa][fer][oqp].lv2/*.so

.include <bsd.port.mk>
