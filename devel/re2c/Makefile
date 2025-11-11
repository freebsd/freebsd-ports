PORTNAME=	re2c
DISTVERSION=	4.3
CATEGORIES=	devel
MASTER_SITES=	https://github.com/skvadrik/re2c/releases/download/${DISTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lexer generator for C, C++ and Go with a focus on generating fast code
WWW=		https://re2c.org/ \
		https://github.com/skvadrik/re2c

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	bash:shells/bash

USES=		cmake:testing compiler:c++11-lib cpe python:test shebangfix tar:xz

CMAKE_OFF=	RE2C_REBUILD_DOCS
CMAKE_ON=	BUILD_SHARED_LIBS \
		RE2C_BUILD_LIBS
CMAKE_TESTING_ON=	RE2C_BUILD_TESTS
CMAKE_TESTING_TARGET=	check

SHEBANG_FILES=	test/__run_unicode_tests.sh \
		test/captures/posix/.gen/__gen.sh \
		test/captures/posix/.run/__run.sh

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_SUB=	yes

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
