# $FreeBSD$

PORTNAME=	chromaprint
PORTVERSION=	1.4.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	https://github.com/acoustid/${PORTNAME}/releases/download/v${PORTVERSION}/ \
		https://bitbucket.org/acoustid/${PORTNAME}/downloads/

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	AcoustID audio fingerprinting library

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg

USES=		cmake:outsource compiler:c++11-lib pathfix
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DBUILD_TOOLS:BOOL=true \
		-DFFT_LIB:STRING=avfft

OPTIONS_DEFINE=		DOXYGEN TEST

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			dot:graphics/graphviz
DOXYGEN_PORTDOCS=	*
# PORTDOCS macro won't work if NOPORTDOCS is defined or if DOCS is disabled
DOXYGEN_IMPLIES=	DOCS
.undef NOPORTDOCS

TEST_BUILD_DEPENDS=	${NONEXISTENT}:devel/googletest:patch
TEST_CMAKE_BOOL=	BUILD_TESTS
TEST_CMAKE_ON=		-DGTEST_ROOT:PATH=`${MAKE} -C ${PORTSDIR}/devel/googletest -VWRKSRC`
TEST_TARGET=		check

do-build-DOXYGEN-on:
	@(cd ${BUILD_WRKSRC}; ${DO_MAKE_BUILD} docs)

do-install-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${INSTALL_WRKSRC}/doc; ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
