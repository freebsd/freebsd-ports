# $FreeBSD$

PORTNAME=	faustlive
PORTVERSION=	g20171205
PORTREVISION=	4
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Standalone application that embeds Faust

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GPL.txt

BUILD_DEPENDS=	${LOCALBASE}/lib/libfaust.a:audio/faust
LIB_DEPENDS=	libLLVM-${LLVM_VERSION:C/([1-9])([0-9])/\1.\2/}.so:devel/llvm${LLVM_VERSION} \
		libasound.so:audio/alsa-lib \
		libcurl.so:ftp/curl \
		libjack.so:audio/jack \
		libmicrohttpd.so:www/libmicrohttpd \
		libqrencode.so:graphics/libqrencode # audio/alsa-lib isn't really needed: https://github.com/grame-cncm/faustlive/issues/3

USES=		compiler:c++11-lang gl gmake qt:5 ssl 
USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm
GH_TAGNAME=	281fcb8
USE_QT=		core gui network widgets buildtools_build qmake_build
USE_GL=		gl

LLVM_VERSION=	60 # llvm version should be the same as in audio/faust
CXXFLAGS+=	$$(llvm-config${LLVM_VERSION} --cflags)
LDFLAGS+=	-lexecinfo

PLIST_FILES=	bin/FaustLive \
		share/applications/FaustLive.desktop \
		share/icons/hicolor/32x32/apps/Faustlive.png \
		share/icons/hicolor/scalable/apps/Faustlive.svg \
		share/pixmaps/Faustlive.xpm

OPTIONS_DEFINE=		PORTAUDIO

PORTAUDIO_MAKE_ARGS=	PORTAUDIO=1
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio

post-patch:
	@${MV} ${WRKSRC}/Build/Linux ${WRKSRC}/Build/FreeBSD
	@${REINPLACE_CMD} -e ' \
		s|SPEC := ""|SPEC := "FaustLive.pro"|; \
		s|PREFIX :=|PREFIX ?=|; \
		s|DESTDIR :=|DESTDIR ?=|; \
		s|llvm-config|llvm-config${LLVM_VERSION}|g' \
		${WRKSRC}/Build/FreeBSD/Makefile
	@${REINPLACE_CMD} -e ' \
		s|########## LIBS AND FLAGS|CXXFLAGS+=$$$$system($$$$LLVM_CONFIG --cflags)| ; \
		s|/use/local|${LOCALBASE}| ; \
		s|-L/opt/local/lib$$|-L${LOCALBASE}/lib -lexecinfo|' \
		${WRKSRC}/Build/FreeBSD/FaustLive.pro
	@${REINPLACE_CMD} -e ' \
		s|#!/bin/bash|#!/bin/sh|' \
		${WRKSRC}/Build/FreeBSD/buildversion

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/FaustLive

.include <bsd.port.mk>
