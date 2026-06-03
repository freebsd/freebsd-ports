PORTNAME=	amnesia-tdd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	shamaz.mazum@gmail.com
COMMENT=	Amnesia: The Dark Descent

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	Bundled AngelScript does not work on this architecture.

LIB_DEPENDS=	libIL.so:graphics/devil \
		libvorbis.so:audio/libvorbis \
		libtheora.so:multimedia/libtheora \
		libogg.so:audio/libogg

USES=		cmake gl sdl openal perl5
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	shamazmazum
GH_PROJECT=	AmnesiaTheDarkDescent
USE_GL=		gl glew glu
USE_PERL5=	build
USE_SDL=	sdl2

CMAKE_ARGS=	-DSYSTEMWIDE_RESOURCES_LOCATION=${PREFIX}/share/${PORTNAME}
CMAKE_ON=	SYSTEMWIDE_RESOURCES
CMAKE_SOURCE_PATH=	${WRKSRC}/amnesia/src

SUB_FILES=	pkg-message

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/${PORTNAME}

.include <bsd.port.mk>
