# $FreeBSD$

PORTNAME=	libprojectM
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.3
CATEGORIES=	graphics audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Awesome music visualiser

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm \
		bash:shells/bash
LIB_DEPENDS=	libftgl.so:graphics/ftgl \
		libfreetype.so:print/freetype2 \
		libvisual-0.4.so:graphics/libvisual04
RUN_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm

USES=		autoreconf:build compiler:c++11-lang gl gmake libtool \
		localbase:ldflags pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	projectM-visualizer
GH_PROJECT=	projectm
USE_SDL=	sdl2
USE_GL=		gl glu glew

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sdl --enable-gles
INSTALL_TARGET=	install-strip

CONFIGURE_SHELL=	${PREFIX}/bin/bash # https://github.com/projectM-visualizer/projectm/issues/319

USE_LDCONFIG=	yes

USE_CXXSTD=	c++98
CXXFLAGS+=	-DDATADIR_PATH='\"${LOCALBASE}/share/projectM\"'
LDFLAGS+=	-L${LOCALBASE}/lib/qt5 # https://github.com/projectM-visualizer/projectm/issues/320

BINARY_ALIAS=	make=${GMAKE}

OPTIONS_DEFINE=			PULSEAUDIO JACK
OPTIONS_DEFAULT=		PULSEAUDIO
OPTIONS_SUB=			yes

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:audio/pulseaudio
PULSEAUDIO_USES=		qt:5
PULSEAUDIO_USE=			qt=core,gui,opengl,widgets,xml,buildtools_build,qmake_build #qt=declarative,network,script,sensors,serialport,sql,xmlpatterns
PULSEAUDIO_CONFIGURE_ENABLE=	pulseaudio
PULSEAUDIO_CONFIGURE_ON=	--enable-qt

JACK_LIB_DEPENDS=		libjack.so:audio/jack
JACK_USES=			qt:5
JACK_USE=			qt=core,gui,opengl,widgets,xml,buildtools_build,qmake_build #qt=declarative,network,script,sensors,serialport,sql,xmlpatterns
JACK_CONFIGURE_ENABLE=		jack
JACK_CONFIGURE_ON=		--enable-qt

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MPULSEAUDIO} && ! ${PORT_OPTIONS:MJACK}
CONFIGURE_ARGS+=	--disable-qt
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO} || ${PORT_OPTIONS:MJACK}
PLIST_FILES+=	share/icons/hicolor/scalable/apps/projectM.svg
.endif

pre-configure:
	@cd ${WRKSRC}/ && ${SH} autogen.sh

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/share/projectM/config.inp ${STAGEDIR}${PREFIX}/share/projectM/config.inp.sample
	${INSTALL_DATA} ${WRKSRC}/fonts/Vera.ttf ${STAGEDIR}${PREFIX}/share/projectM/fonts/

.include <bsd.port.mk>
