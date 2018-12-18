# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	appleseed
DISTVERSION=	1.7.1-beta
PORTREVISION=	5
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Modern, physically-based production renderer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN=		fails to build

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libpng.so:graphics/png \
		libIlmImf.so:graphics/openexr \
		libxerces-c.so:textproc/xerces-c3 \
		liboslexec.so:graphics/openshadinglanguage

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}hq

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	not ported to it yet

USES=		cmake:outsource compiler:env

LDFLAGS+=	-lboost_atomic
CMAKE_ARGS=	-DUSE_STATIC_BOOST:BOOL=OFF -DUSE_STATIC_OIIO:BOOL=OFF \
		-DUSE_STATIC_OSL:BOOL=OFF -DWITH_DOXYGEN:BOOL=OFF \
		-DWITH_HEADERS:BOOL=OFF -DWITH_PYTHON:BOOL=OFF \
		-DWITH_TESTS:BOOL=OFF -DWARNINGS_AS_ERRORS:BOOL=OFF

.for lib in EXR OIIO OSL PNG SEEXPR XERCES ZLIB
CMAKE_ARGS+=	-DUSE_EXTERNAL_${lib}:BOOL=ON
.endfor

# Not ready for hier(7)-conforming installation yet
CMAKE_INSTALL_PREFIX=	${PREFIX}/${PKGBASE}
PLIST_SUB=	APPHOME=${CMAKE_INSTALL_PREFIX}

SUB_FILES=	pkg-message
SUB_LIST:=	${PLIST_SUB}

OPTIONS_DEFINE=	CPP11 EXAMPLES DISNEY STUDIO
OPTIONS_DEFAULT=	DISNEY STUDIO
OPTIONS_SUB=	yes

CPP11_DESC=	Build in C++11 mode
DISNEY_DESC=	Disney material support
STUDIO_DESC=	Build appleseed.studio (Qt-based GUI program)

CPP11_CMAKE_ON=	-DUSE_CPP11:BOOL=ON

EXAMPLES_CMAKE_OFF=	-DWITH_SAMPLES:BOOL=OFF

DISNEY_LIB_DEPENDS=	libSeExpr.so:graphics/seexpr
DISNEY_CMAKE_ON=	-DWITH_DISNEY_MATERIAL:BOOL=ON

STUDIO_USES=	qt:4
STUDIO_USE=	QT=moc_build,qmake_build,rcc_build,uic_build,opengl
STUDIO_CMAKE_OFF=	-DWITH_STUDIO:BOOL=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTUDIO}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${RMDIR} ${WRKSRC}/sandbox/docs/api
.if ${COMPILER_TYPE} == clang && ${COMPILER_VERSION} < 39
	@${ECHO_MSG} "===>  Patching for Core Working Group (CWG) Defect 253 (see r455830)"
	@${REINPLACE_CMD} -E 's,const (.*MDF ),\1,' \
		${WRKSRC}/src/appleseed/renderer/modeling/bsdf/disneybrdf.cpp \
		${WRKSRC}/src/appleseed/renderer/modeling/bsdf/microfacetbrdf.cpp \
		${WRKSRC}/src/appleseed/foundation/meta/tests/test_microfacet.cpp
.endif

.include <bsd.port.post.mk>
