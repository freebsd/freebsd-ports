# $FreeBSD$

PORTNAME=	libprojectM
DISTVERSION=	2.1.0
CATEGORIES=	graphics audio
MASTER_SITES=	SF/${PORTNAME:tl:S/lib//}/${PORTVERSION}/
DISTNAME=	${PORTNAME:S/lib//}-complete-${DISTVERSION}-Source

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Awesome music visualiser

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libftgl.so:graphics/ftgl \
		libfreetype.so:print/freetype2 \
		libvisual-0.4.so:graphics/libvisual04

USES=		cmake:outsource localbase:ldflags pkgconfig qt:4
USE_QT=		corelib gui opengl xml moc_build qmake_build rcc_build uic_build
USE_SDL=	sdl
USE_GL=		gl glu glew
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DUSE_OPENMP=OFF # openmp breaks build on 11.x
CMAKE_OFF=	INCLUDE-PROJECTM-TEST

OPTIONS_DEFINE=		PULSEAUDIO JACK
OPTIONS_DEFAULT=	PULSEAUDIO
OPTIONS_SUB=		yes

PULSEAUDIO_CMAKE_BOOL=	INCLUDE-PROJECTM-PULSEAUDIO
PULSEAUDIO_LIB_DEPENDS=	libpulse.so:audio/pulseaudio

JACK_CMAKE_BOOL=	INCLUDE-PROJECTM-JACK
JACK_LIB_DEPENDS=	libjack.so:audio/jack

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/share/projectM/config.inp ${STAGEDIR}${PREFIX}/share/projectM/config.inp.sample
	${INSTALL_DATA} ${WRKSRC}/fonts/Vera.ttf ${STAGEDIR}${PREFIX}/share/projectM/fonts/

.include <bsd.port.mk>
