PORTNAME=	faust
DISTVERSION=	2.81.2
CATEGORIES=	audio devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	e4e9e51a1a12ef0806fc7c8439fa817a98ec57ce.patch:-p1 # https://github.com/grame-cncm/faust/pull/1170: Fix compilation flags for generated projects: use c++17 instead of c++14

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Functional programming language for realtime audio signal processing
WWW=		https://faust.grame.fr/ \
		https://github.com/grame-cncm/faust

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

BROKEN_armv7=	compilation broken: the faust executable SEGVs while compiling examples during build: faust -a lv2.cpp -cn amp -I examples examples/amp.dsp -o examples/amp.cpp

LIB_DEPENDS=	libLLVM-${LLVM_VERSION}.so:devel/llvm${LLVM_VERSION} \
		libzstd.so:archivers/zstd
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++17-lang cmake localbase:ldflags llvm:min=${LLVM_VER},lib ncurses python pkgconfig shebangfix # llvm: versions <11 lacked dump() function(s) that cause unresolved symbols in libfaust.so
USE_LDCONFIG=	yes
USE_CXXSTD=	c++17

USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm
GH_TUPLE=	\
		grame-cncm:faustlibraries:9e866dc047433cedeb250cf6e58310a8d3f79803:grame_cncm_faustlibraries/libraries \
		ccrma:faust2ck:db879cb:faust2ck/tools/faust2ck \
		shakfu:py2max:3aaa8ca:py2max/architecture/max-msp/py2max \
		yixuan:spectra:8c7242e:spectra/tools/physicalModeling/mesh2faust/spectra

#LLVM_VER=	15 # not c++17 by default
LLVM_VER=	19

SHEBANG_FILES=	tools/faust-config \
		tools/faust2appls/* \
		tools/benchmark/faustbench \
		tools/sound2faust/sound2reader

CMAKE_SOURCE_PATH=	${WRKSRC}/build
CMAKE_ON=	INCLUDE_DYNAMIC # only installs headers and not libs without INCLUDE_DYNAMIC or INCLUDE_STATIC: https://github.com/grame-cncm/faust/issues/553
CMAKE_ARGS=	-C ${FILESDIR}/backends.cmake -DLLVM_CONFIG=${LOCALBASE}/bin/llvm-config${LLVM_VERSION} \

CXXFLAGS+=	-I${WRKSRC}/compiler/generator/cpp # fatal error: 'cpp_code_container.hh' file not found WHEN INCLUDE_STATIC=TRUE
CXXFLAGS+=	`llvm-config${LLVM_VERSION} --cflags` -DLLVM_${LLVM_VERSION}0 # for the llvm backend
CXXFLAGS_riscv64=	-fPIC # attempt to fix failure: can't create dynamic relocation R_RISCV_HI20 against symbol: vtable for LV2UI in readonly segment; recompile object files with -fPIC or pass '-Wl,-z,notext' to allow text relocations in the output
LDFLAGS+=	-lexecinfo

TEST_ENV=	PATH=${STAGEDIR}${PREFIX}/bin:${PATH}

OPTIONS_DEFINE=		EXAMPLES HIGHLIGHT HTTPD_LIB
OPTIONS_DEFAULT=	HIGHLIGHT HTTPD_LIB
OPTIONS_SUB=		yes

EXAMPLES_CMAKE_BOOL=	FREEBSD_INSTALL_EXAMPLES

HIGHLIGHT_DESC=		Syntax highlighting in Kate, gedit, Highlight, vim
HTTPD_LIB_DESC=		Build httpd support library

HTTPD_LIB_CMAKE_BOOL=	INCLUDE_HTTP HTTPDYNAMIC
HTTPD_LIB_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd

PORTEXAMPLES=		*

post-patch:
	# change qmake (5) -> qmake6
	@cd ${WRKSRC} && \
		${REINPLACE_CMD} -i '' -e 's|echo qmake)|echo qmake6)|; s|echo qmake-qt5)|echo qmake6)|' \
			tools/faust2appls/faust2*

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/faust
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/faust # https://github.com/grame-cncm/faust/issues/135
	@${FIND} ${STAGEDIR} -name android | ${XARGS} ${RM} -r

post-install-HIGHLIGHT-on:
	# 1) kate
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/apps/katepart/syntax
	${INSTALL_DATA} ${WRKSRC}/syntax-highlighting/faust.xml ${STAGEDIR}${PREFIX}/share/apps/katepart/syntax/
	# 2) gedit
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/gtksourceview-2.0/language-specs ${STAGEDIR}${PREFIX}/share/gtksourceview-3.0/language-specs
	${INSTALL_DATA} ${WRKSRC}/syntax-highlighting/faust.lang ${STAGEDIR}${PREFIX}/share/gtksourceview-2.0/language-specs/
	${INSTALL_DATA} ${WRKSRC}/syntax-highlighting/faust.lang ${STAGEDIR}${PREFIX}/share/gtksourceview-3.0/language-specs/
	# 4) Highlight
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/highlight/langDefs
	${INSTALL_DATA} ${WRKSRC}/syntax-highlighting/dsp.lang ${STAGEDIR}${PREFIX}/share/highlight/langDefs/
	# 5) VIM
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/vim/vimfiles/syntax
	${INSTALL_DATA} ${WRKSRC}/syntax-highlighting/faust.vim ${STAGEDIR}${PREFIX}/share/vim/vimfiles/syntax/
	# 6) EMACS TODO

do-test:
	@${CP} ${FILESDIR}/example-freeverb_demo.dsp ${TEST_WRKSRC}
	@cd ${TEST_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${TEST_ENV} faust2jaqt example-freeverb_demo.dsp && \
		${SETENV} ${TEST_ENV} ./example-freeverb_demo

.include <bsd.port.mk>
