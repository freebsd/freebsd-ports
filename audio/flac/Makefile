PORTNAME=	flac
DISTVERSION=	1.4.3
CATEGORIES=	audio
MASTER_SITES=	https://github.com/xiph/${PORTNAME}/releases/download/${DISTVERSION}/ \
		https://downloads.xiph.org/releases/${PORTNAME}/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Free lossless audio codec
WWW=		https://www.xiph.org/flac/

LICENSE=	BSD3CLAUSE GFDL GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/COPYING.Xiph
LICENSE_FILE_GFDL=	${WRKSRC}/COPYING.FDL

LIB_DEPENDS=	libogg.so:audio/libogg

USES=		cmake:testing compiler:c11 cpe gettext-runtime iconv \
		pathfix pkgconfig tar:xz
CPE_VENDOR=	flac_project
USE_LDCONFIG=	yes

# Preserve UTF-8 filenames in test/flac-to-flac-metadata-test-files/.
# They are referenced by the test suite.
EXTRACT_CMD=	${SETENV} LC_ALL=C.UTF-8 ${TAR}

CMAKE_TESTING_ARGS=	-DCMAKE_CTEST_ARGUMENTS="-E;libFLAC"

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR=${PREFIX}/man
CMAKE_OFF=	BUILD_DOCS BUILD_TESTING WITH_STACK_PROTECTOR
CMAKE_ON=	BUILD_SHARED_LIBS

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/*/*.m4 ${STAGEDIR}${PREFIX}/share/aclocal

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/api
	${INSTALL_MAN} ${WRKSRC}/doc/api/* ${STAGEDIR}${DOCSDIR}/api
	${MKDIR} ${STAGEDIR}${DOCSDIR}/images
	${INSTALL_MAN} ${WRKSRC}/doc/images/*.gif ${STAGEDIR}${DOCSDIR}/images
	${INSTALL_MAN} ${WRKSRC}/doc/images/*.svg ${STAGEDIR}${DOCSDIR}/images
	${INSTALL_MAN} ${WRKSRC}/doc/*.tag ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/isoflac.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
