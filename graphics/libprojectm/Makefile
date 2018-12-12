# $FreeBSD$

PORTNAME=	libprojectM
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.0
PORTREVISION=	1
CATEGORIES=	graphics audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Awesome music visualiser

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm
LIB_DEPENDS=	libftgl.so:graphics/ftgl \
		libfreetype.so:print/freetype2 \
		libvisual-0.4.so:graphics/libvisual04
RUN_DEPENDS=	${LOCALBASE}/include/glm/glm.hpp:math/glm

USES=		autoreconf:build compiler:c++11-lang gl gmake libtool \
		localbase:ldflags pkgconfig qt:5

USE_GITHUB=	yes
GH_ACCOUNT=	projectM-visualizer
GH_PROJECT=	projectm
USE_SDL=	sdl2
USE_QT=		buildtools core gui opengl qmake_build widgets xml
USE_GL=		gl glu glew
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sdl --enable-qt --enable-gles
INSTALL_TARGET=	install-strip

USE_LDCONFIG=	yes

USE_CXXSTD=	c++98
CXXFLAGS+=	-DDATADIR_PATH='\"${LOCALBASE}/share/projectM\"'

OPTIONS_DEFINE=		PULSEAUDIO JACK
OPTIONS_DEFAULT=	PULSEAUDIO
OPTIONS_SUB=		yes

PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
JACK_LIB_DEPENDS=	libjack.so:audio/jack

pre-configure:
	@cd ${WRKSRC}/ && ${SH} autogen.sh

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/share/projectM/config.inp ${STAGEDIR}${PREFIX}/share/projectM/config.inp.sample
	${INSTALL_DATA} ${WRKSRC}/fonts/Vera.ttf ${STAGEDIR}${PREFIX}/share/projectM/fonts/

.include <bsd.port.mk>
