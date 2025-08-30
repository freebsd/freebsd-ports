PORTNAME=	chromaprint
DISTVERSION=	1.6.0
CATEGORIES=	audio
MASTER_SITES=	https://github.com/acoustid/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	AcoustID audio fingerprinting library
WWW=		https://acoustid.org/chromaprint

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USES=		cmake:testing compiler:c++14-lang
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DAUDIO_PROCESSOR_LIB:STRING=swresample \
		-DFFT_LIB:STRING=`if [ -f ${LOCALBASE}/include/libavcodec/avfft.h ]; then ${ECHO_CMD} avfft; else ${ECHO_CMD} avtx; fi`
CMAKE_ON=	BUILD_TOOLS
CMAKE_OFF=	BUILD_TESTS
CMAKE_TESTING_ON=	BUILD_TESTS

OPTIONS_DEFINE=		DOCS DOXYGEN

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
DOXYGEN_PORTDOCS=	*

do-build-DOXYGEN-on:
	@(cd ${BUILD_WRKSRC}; ${DO_MAKE_BUILD} docs)

do-install-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${INSTALL_WRKSRC}/doc; ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
