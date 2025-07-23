PORTNAME=	chromaprint
DISTVERSION=	1.5.1.20221217
PORTREVISION=	1
CATEGORIES=	audio
#MASTER_SITES=	https://github.com/acoustid/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	AcoustID audio fingerprinting library
WWW=		https://acoustid.org/chromaprint

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	acoustid
GH_TAGNAME=	aa67c95
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_TOOLS:BOOL=true \
		-DAUDIO_PROCESSOR_LIB=swresample \
		-DFFT_LIB:STRING=avfft

OPTIONS_DEFINE=		DOCS DOXYGEN TEST

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
DOXYGEN_PORTDOCS=	*
DOXYGEN_IMPLIES=	DOCS

TEST_BUILD_DEPENDS=	${NONEXISTENT}:devel/googletest:patch
TEST_CMAKE_BOOL=	BUILD_TESTS
TEST_CMAKE_ON=		-DGTEST_ROOT:PATH=`${MAKE} -C ${PORTSDIR}/devel/googletest -VWRKSRC`/googletest
TEST_TARGET=		check

do-build-DOXYGEN-on:
	@(cd ${BUILD_WRKSRC}; ${DO_MAKE_BUILD} docs)

do-install-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${INSTALL_WRKSRC}/doc; ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
