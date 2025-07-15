PORTNAME=	odin
DISTVERSIONPREFIX=	dev-
DISTVERSION=	2025-07
CATEGORIES=	lang devel
PKGNAMESUFFIX=	-lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Odin programming language
WWW=		https://odin-lang.org \
		https://github.com/odin-lang/Odin

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails:  use of undeclared identifier 'LLVMInitializeWebAssemblyTargetInfo'
BROKEN_i386=	compilation fails:  use of undeclared identifier 'LLVMInitializeAArch64TargetInfo', see https://github.com/odin-lang/Odin/issues/4875

USES=		gmake llvm:20,lib python:test

USE_GITHUB=	yes
GH_ACCOUNT=	odin-lang
GH_PROJECT=	Odin

ALL_TARGET=	release

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

do-install:
	# binary
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	# libs and binary
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} core ${STAGEDIR}${PREFIX}/lib/${PORTNAME} && \
		${COPYTREE_SHARE} base ${STAGEDIR}${PREFIX}/lib/${PORTNAME} && \
		${COPYTREE_SHARE} vendor ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	# binary symlink
	${RLN} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	# examples
	cd ${WRKSRC}/examples && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

do-test:
	@${ECHO} "===> Compiling vendor libraries"
.for dir in vendor/stb/src vendor/cgltf/src vendor/miniaudio/src
	@${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC}/${dir}
.endfor
	@${ECHO} "===> Running tests"
	@cd ${WRKSRC} && \
		 ${SETENV} ${TEST_ENV} ./odin test tests/core/normal.odin -file -all-packages -define:ODIN_TEST_FANCY=false && \
		 ${SETENV} ${TEST_ENV} ./odin test tests/core/speed.odin -o:speed -file -all-packages -define:ODIN_TEST_FANCY=false && \
		 ${SETENV} ${TEST_ENV} ./odin test tests/vendor -all-packages -define:ODIN_TEST_FANCY=false && \
		 ${SETENV} ${TEST_ENV} ./odin test tests/internal -all-packages -define:ODIN_TEST_FANCY=false

# tests as of 2025-02:
#   Finished 398 tests in 7.059992681s. All tests were successful.
#   Finished 41 tests in 575.880234ms. All tests were successful.
#   Finished 20 tests in 4.259498249s. All tests were successful.

.include <bsd.port.mk>
