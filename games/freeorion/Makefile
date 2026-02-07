PORTNAME=	freeorion
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1.1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Turn-based space empire and galactic conquest game
WWW=		https://www.freeorion.org/

LICENSE=	GPLv2 CC-BY-SA-3.0
LICENSE_COMB=	multi

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		${PY_BOOST}

USE_GITHUB=	yes

USES=		cmake compiler:c++17-lang python
CMAKE_ARGS=	-Wno-dev

LDFLAGS_i386=	-Wl,-znotext

PORTDOCS=	ChangeLog.md README.md
PORTDATA=	*

OPTIONS_DEFINE=	DOCS TEST CLIENT_GG
OPTIONS_DEFAULT=DOCS TEST CLIENT_GG
OPTIONS_SUB=	yes

TEST_CMAKE_BOOL=	BUILD_TESTING
TEST_TEST_TARGET=	unittest
TEST_USES=		localbase

CLIENT_GG_DESC=		Build GiGi client
CLIENT_GG_CMAKE_BOOL=	BUILD_CLIENT_GG
CLIENT_GG_USES=		gl openal sdl
CLIENT_GG_USE=		SDL=sdl2 GL=gl,glu,glew
CLIENT_GG_LIB_DEPENDS=	libfreetype.so:print/freetype2 \
			libogg.so:audio/libogg \
			libvorbis.so:audio/libvorbis \
			libpng.so:graphics/png

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} != ${PYTHON_DEFAULT}
# unable to detect boost_python otherwise since required files are
# not installed by boost-python-libs
CMAKE_ARGS+=	-DBoost_NO_BOOST_CMAKE:BOOL=YES
.endif

post-patch:
	@${REINPLACE_CMD} -e '/        system/d' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e '/^find_package(Boost /s| system||' \
		${WRKSRC}/GG/CMakeLists.txt
	@${REINPLACE_CMD} -e '/Boost::system/d' \
		${WRKSRC}/GG/test/unit/CMakeLists.txt \
		${WRKSRC}/test/UI/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.post.mk>
