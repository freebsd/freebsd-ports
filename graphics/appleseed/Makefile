# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	appleseed
DISTVERSION=	1.2.0-beta
CATEGORIES=	graphics

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Modern, physically-based production renderer

LICENSE=	MIT

LIB_DEPENDS=	libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libpng.so:${PORTSDIR}/graphics/png \
		libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libxerces-c.so:${PORTSDIR}/textproc/xerces-c3

USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}hq

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	uses SSE instructions

USES=		cmake:outsource
USE_GL=		gl
USE_QT4=	moc_build qmake_build rcc_build uic_build opengl

CMAKE_ARGS=	-DUSE_STATIC_BOOST:BOOL=OFF -DWITH_DOXYGEN:BOOL=OFF \
		-DWITH_TESTS:BOOL=OFF -DWITH_HEADERS:BOOL=OFF \
		-DWITH_PYTHON:BOOL=OFF

.for lib in ZLIB PNG EXR XERCES
CMAKE_ARGS+=	-DUSE_EXTERNAL_${lib}:BOOL=ON
.endfor

# Not ready for hier(7)-conforming installation yet
CMAKE_INSTALL_PREFIX=	${PREFIX}/${PKGBASE}
PLIST_SUB=	APPHOME=${CMAKE_INSTALL_PREFIX}

SUB_FILES=	pkg-message
SUB_LIST:=	${PLIST_SUB}

.include <bsd.port.pre.mk>

post-patch:
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1100074
# Fix "undefined reference to `LZ4_compressBound'" upon linking with Clang
# on -CURRENT (I'm not sure how it can be mapped to specific Clang version)
	@${REINPLACE_CMD} -e '/LZ4_compressBound/s,static inline ,,' \
		${WRKSRC}/src/lz4/lz4.h
.endif
	@${REINPLACE_CMD} -e 's,Linux,${OPSYS},' \
		${WRKSRC}/src/appleseed.cli/CMakeLists.txt \
		${WRKSRC}/src/appleseed.studio/CMakeLists.txt \
		${WRKSRC}/src/tools/animatecamera/CMakeLists.txt \
		${WRKSRC}/src/tools/convertmeshfile/CMakeLists.txt \
		${WRKSRC}/src/tools/dumpmetadata/CMakeLists.txt \
		${WRKSRC}/src/tools/makefluffy/CMakeLists.txt \
		${WRKSRC}/src/tools/updateprojectfile/CMakeLists.txt
	@${RMDIR} ${WRKSRC}/sandbox/docs/api

.include <bsd.port.post.mk>
