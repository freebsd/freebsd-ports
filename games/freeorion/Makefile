PORTNAME=	freeorion
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.10.2
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Turn-based space empire and galactic conquest game

LICENSE=	GPLv2 CC-BY-SA-3.0
LICENSE_COMB=	multi

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		${PY_BOOST}

USE_GITHUB=	yes

USES=		cmake compiler:c++14-lang python:3.8-3.10  # inherited from boost-python-libs
CMAKE_ARGS=	-Wno-dev

LDFLAGS_i386=	-Wl,-znotext

PORTDOCS=	ChangeLog.md README.md
PORTDATA=	*

OPTIONS_DEFINE=	DOCS TEST HEADLESS
OPTIONS_SUB=	yes

TEST_CMAKE_BOOL=	BUILD_TESTING
TEST_TEST_TARGET=	unittest
TEST_USES=		localbase

HEADLESS_DESC=		Build only headless components: server and AI
HEADLESS_CMAKE_BOOL=	BUILD_HEADLESS
HEADLESS_USES_OFF=	gl openal sdl
HEADLESS_USE_OFF=	SDL=sdl2 GL=gl,glu,glew
HEADLESS_LIB_DEPENDS_OFF= \
			libfreetype.so:print/freetype2 \
			libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis \
			libpng.so:graphics/png

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} != ${PYTHON_DEFAULT}
# unable to detect boost_python otherwise since required files are
# not installed by boost-python-libs
CMAKE_ARGS+=	-DBoost_NO_BOOST_CMAKE:BOOL=YES
.endif

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.post.mk>
