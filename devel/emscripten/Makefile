PORTNAME=	emscripten
DISTVERSION=	3.1.64
CATEGORIES=	devel www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LLVM-to-Web Compiler
WWW=		https://emscripten.org/

LICENSE=	MIT NCSA
LICENSE_COMB=	dual

RUN_DEPENDS=	bash:shells/bash \
		binaryen>0:devel/binaryen
		# the upstream requires to use either the latest llvm version, or their own llvm fork called emscripten-fastcomp

USES=		nodejs:run llvm:19 python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	emscripten-core

SHEBANG_FILES=	${PYSCRIPTS} emcmake system/bin/sdl-config system/bin/sdl2-config
SHEBANG_GLOB=	*.py *.sh

PYSCRIPTS=	em++ em-config emar embuilder emcc emcmake emconfigure emmake emranlib emrun emscons emsize

NO_BUILD=	yes
NO_ARCH=	yes

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} CLANG_CC=${LOCALBASE}/bin/clang${LLVM_VERSION}

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

do-test: # some tests fail: Unknown option '--no-stack-ir', see https://github.com/emscripten-core/emscripten/issues/22408
	@cd ${WRKSRC} && \
		${SETENV} ${TEST_ENV} test/runner core3.test_*i64* && \
		${SETENV} ${TEST_ENV} test/runner wasm2js1

.include <bsd.port.mk>
