PORTNAME=	faustlive
DISTVERSION=	2.5.7
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Standalone application that embeds Faust

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GPL.txt

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libLLVM-${LLVM_VERSION}.so:devel/llvm${LLVM_VERSION} \
		libasound.so:audio/alsa-lib \
		libcurl.so:ftp/curl \
		libfaust.so:audio/faust \
		libjack.so:audio/jack \
		libmicrohttpd.so:www/libmicrohttpd \
		libqrencode.so:graphics/libqrencode \
		libsndfile.so:audio/libsndfile # audio/alsa-lib isn't really needed: https://github.com/grame-cncm/faustlive/issues/3

USES=		compiler:c++11-lang gl pkgconfig qmake qt:5 shebangfix
USE_QT=		core gui network widgets buildtools_build
USE_GL=		gl

USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm
GH_TUPLE=	grame-cncm:faustlibraries:0dce1a5:grame_cncm_faustlibraries/Resources/Libs

SHEBANG_GLOB=	build install makelibs

LLVM_VERSION=	11 # llvm version should be the same as in audio/faust

QMAKE_ARGS=	Build/FaustLive.pro

CXXFLAGS+=	$$(llvm-config${LLVM_VERSION} --cflags)
LDFLAGS+=	-lexecinfo

BINARY_ALIAS=	llvm-config=llvm-config${LLVM_VERSION}

PLIST_FILES=	bin/FaustLive \
		share/applications/FaustLive.desktop \
		share/icons/hicolor/32x32/apps/Faustlive.png \
		share/icons/hicolor/scalable/apps/Faustlive.svg \
		share/pixmaps/Faustlive.xpm

OPTIONS_DEFINE=		PORTAUDIO

PORTAUDIO_MAKE_ARGS=	PORTAUDIO=1
PORTAUDIO_LIB_DEPENDS=	libportaudio.so:audio/portaudio
PORTAUDIO_BROKEN=	PORTAUDIO support needs to be updated for qmake

post-extract:
	@${RM} ${WRKSRC}/version # mixup with STL header 'version'

do-install: # workaround for https://github.com/grame-cncm/faustlive/issues/38
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_PROGRAM} ${WRKSRC}/Build/FaustLive/FaustLive ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Build/rsrc/FaustLive.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/Resources/Images/Faustlive.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/32x32/apps
	${INSTALL_DATA} ${WRKSRC}/Resources/Images/Faustlive.svg ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/Resources/Images/Faustlive.xpm ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
