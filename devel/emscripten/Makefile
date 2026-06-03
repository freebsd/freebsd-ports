PORTNAME=	emscripten
DISTVERSION=	5.0.7
CATEGORIES=	devel www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LLVM-to-Web Compiler
WWW=		https://emscripten.org/ \
		https://github.com/emscripten-core/emscripten

LICENSE=	MIT NCSA
LICENSE_COMB=	dual

# USES doesn't support llvm:devel, so we add it here:
BUILD_DEPENDS=	llvm-devel>0:devel/llvm-devel
RUN_DEPENDS=	bash:shells/bash \
		binaryen>0:devel/binaryen \
		llvm-devel>0:devel/llvm-devel
		# the upstream requires to use either the latest llvm version, or their own llvm fork called emscripten-fastcomp

USES=		nodejs:run python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	emscripten-core

LLVM_VERSION=	devel

SHEBANG_FILES=	system/bin/sdl-config system/bin/sdl2-config
SHEBANG_GLOB=	*.py *.sh

PYSCRIPTS=	em++ em-config emar embuilder emcc emcmake emconfigure emmake emranlib emrun emscons emsize

NO_BUILD=	yes
NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} CLANG_CC=${LOCALBASE}/bin/clang-${LLVM_VERSION}

BINARY_ALIAS=	python=${PYTHON_CMD} # for tests

PORTSCOUT=	limit:^\d+\. # prevent i64

post-patch:
	@${REINPLACE_CMD} -i '' -E " \
			s|BINARYEN_ROOT = None|BINARYEN_ROOT = '${LOCALBASE}'| ; \
			s|LLVM_ROOT = None|LLVM_ROOT = '${LOCALBASE}/bin'| ; \
			s|LLVM_ADD_VERSION = None|LLVM_ADD_VERSION = '${LLVM_VERSION}'| ; \
			s|CLANG_ADD_VERSION = None|CLANG_ADD_VERSION = '${LLVM_VERSION}'| ; \
			s|^__rootpath__ = .*|__rootpath__ = '${PREFIX}/lib/${PORTNAME}'| ; \
			s|find_executable\('llvm-dis'\) or '/usr/bin/llvm-dis'|'${LOCALBASE}/bin/llvm-dis'|" \
			${WRKSRC}/tools/config.py

do-install: # the native install target installs files into root, see https://github.com/emscripten-core/emscripten/issues/17193
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	cd ${WRKSRC} && ${CP} -r em* cmake site src system third_party tools ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
	${FIND} ${STAGEDIR}${PREFIX}/lib/${PORTNAME} \( -name "*.bat" -o -name "*.orig" \) -delete
.for s in ${PYSCRIPTS}
	@(echo "#!/bin/sh"; \
	  echo ""; \
	  echo "${PYTHON_CMD} ${PREFIX}/lib/${PORTNAME}/${s}.py \"$$"@"\"" \
	) > ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${s}
	@${CHMOD} +x ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${s}
	${RLN} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${s} ${STAGEDIR}${PREFIX}/bin/${s}
.endfor

do-test: install # some tests fail: Unknown option '--no-stack-ir', see https://github.com/emscripten-core/emscripten/issues/22408
	@cd ${WRKDIR} && \
		${ECHO} "==> Testing basic arithmetic" && \
		${PREFIX}/bin/emcc -c ${FILESDIR}/hello_world.c -o test.o && \
		${ECHO} "==> Testing array operations" && \
		echo 'int arr[10]; int main() { arr[5] = 42; return arr[5] - 42; }' > test2.c && \
		${PREFIX}/bin/emcc test2.c -o test2.js && \
		node test2.js && \
		${ECHO} "==> Testing function calls" && \
		echo 'int add(int a, int b) { return a + b; } int main() { return add(3, 4) - 7; }' > test3.c && \
		${PREFIX}/bin/emcc test3.c -o test3.js && \
		node test3.js && \
		${ECHO} "==> Testing loops" && \
		echo 'int main() { int sum = 0; for(int i = 0; i < 10; i++) sum += i; return sum - 45; }' > test4.c && \
		${PREFIX}/bin/emcc test4.c -o test4.js && \
		node test4.js && \
		${ECHO} "Test suite completed successfully."

test-quick: install
	@cd ${WRKSRC} && \
		${ECHO} "==> Running the test" && \
		${PREFIX}/bin/emcc ${FILESDIR}/hello_world.c && \
		node a.out.js && \
		${ECHO} "Test succeeded."

.include <bsd.port.mk>
