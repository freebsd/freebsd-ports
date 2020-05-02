# $FreeBSD$

PORTNAME=	emscripten
DISTVERSION=	1.39.14
CATEGORIES=	devel www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LLVM-to-Web Compiler

LICENSE=	MIT NCSA
LICENSE_COMB=	dual

RUN_DEPENDS=	llvm-devel>0:devel/llvm-devel \
		node:www/node \
		bash:shells/bash \
		binaryen>0:devel/binaryen
		# the upstream requires to use either the latest llvm version, or their own llvm fork called emscripten-fastcomp

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	emscripten-core
GH_PROJECT=	emscripten
SHEBANG_FILES=	${PYSCRIPTS} emcmake tools/emdump system/bin/sdl-config system/bin/sdl2-config third_party/websockify/run
SHEBANG_GLOB=	*.py *.sh

PYSCRIPTS=	em++ emar emcc emconfigure emmake emranlib emrun emscons

NO_BUILD=	yes
NO_ARCH=	yes

PORTSCOUT=	limit:^\d+\. # prevent i64

post-patch:
	@${REINPLACE_CMD} -i '' -E " \
			s|BINARYEN_ROOT = None|BINARYEN_ROOT = '${LOCALBASE}'| ; \
			s|LLVM_ROOT = None|LLVM_ROOT = '${LOCALBASE}'| ; \
			s|LLVM_ADD_VERSION = None|LLVM_ADD_VERSION = 'devel'| ; \
			s|CLANG_ADD_VERSION = None|CLANG_ADD_VERSION = 'devel'| ; \
			s|^__rootpath__ = .*|__rootpath__ = '${PREFIX}/lib/${PORTNAME}'| ; \
			s|find_executable\('llvm-dis'\) or '/usr/bin/llvm-dis'|'${LOCALBASE}/bin/llvm-dis'|" \
			${WRKSRC}/tools/shared.py
	@${REINPLACE_CMD} -i '' -E " \
			s|os.getenv\('BINARYEN', ''\)|os.getenv('BINARYEN', '${LOCALBASE}')|" \
			${WRKSRC}/tools/settings_template.py

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	cd ${WRKSRC} && ${CP} -r em* cmake site src system third_party tools ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
	${FIND} ${STAGEDIR}${PREFIX}/lib/${PORTNAME} \( -name "*.bat" -o -name "*.orig" \) -delete
.for s in ${PYSCRIPTS}
	${RLN} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${s} ${STAGEDIR}${PREFIX}/bin/${s}
.endfor
	${RM} -rf ${STAGEDIR}${PREFIX}/lib/emscripten/system/lib/pkgconfig
	${RM} -rf ${STAGEDIR}${PREFIX}/lib/emscripten/tools/websocket_to_posix_proxy

.include <bsd.port.mk>
