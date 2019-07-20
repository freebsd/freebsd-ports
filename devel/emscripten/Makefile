# $FreeBSD$

PORTNAME=	emscripten
DISTVERSION=	1.38.39
CATEGORIES=	devel www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	LLVM-to-Web Compiler

LICENSE=	MIT NCSA
LICENSE_COMB=	dual

RUN_DEPENDS=	llvm-devel>0:devel/llvm-devel # the upstream requires to use either the latest llvm version, or their own llvm fork called emscripten-fastcomp

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	emscripten-core
GH_PROJECT=	emscripten
SHEBANG_FILES=	${PYSCRIPTS} emcmake tools/emdump system/bin/sdl-config system/bin/sdl2-config third_party/websockify/run third_party/websockify/websockify.py
SHEBANG_GLOB=	*.py

PYSCRIPTS=	em++ emar emcc em-config emconfigure emmake emranlib emrun emscons

NO_BUILD=	yes
NO_ARCH=	yes

PORTSCOUT=	limit:^[0-9] # prevent versions like "i64"

post-patch:
	@${REINPLACE_CMD} -i '' -E "s|^__rootpath__ = .*|__rootpath__ = '${PREFIX}/lib/${PORTNAME}'|" ${WRKSRC}/tools/shared.py

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	cd ${WRKSRC} && ${CP} -r em* cmake site src system third_party tools ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/
	${FIND} ${STAGEDIR}${PREFIX}/lib/${PORTNAME} \( -name "*.bat" -o -name "*.orig" \) -delete
.for s in ${PYSCRIPTS}
	${RLN} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/${s} ${STAGEDIR}${PREFIX}/bin/${s}
.endfor
	${RM} -rf ${STAGEDIR}${PREFIX}/lib/emscripten/system/lib/pkgconfig

.include <bsd.port.mk>
