# $FreeBSD$

PORTNAME=	bioparser
DISTVERSION=	3.0.12
CATEGORIES=	biology devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ header only parsing library for several formats in bioinformatics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	rvaser
GH_TUPLE=	rvaser:biosoup:e2b39f1:biosoup/vendor/biosoup

NO_ARCH=	yes

PLIST_FILES=	include/bioparser/fasta_parser.hpp \
		include/bioparser/fastq_parser.hpp \
		include/bioparser/mhap_parser.hpp \
		include/bioparser/paf_parser.hpp \
		include/bioparser/parser.hpp \
		include/bioparser/sam_parser.hpp

do-install:
	cd ${WRKSRC}/include && ${COPYTREE_SHARE} ${PORTNAME} ${STAGEDIR}${PREFIX}/include

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -Dbioparser_build_tests:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${BUILD_WRKSRC}/bin/bioparser_test

.include <bsd.port.mk>
