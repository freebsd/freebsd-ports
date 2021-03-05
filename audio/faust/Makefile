# Created by: Yuri Victorovich <yuri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	faust
DISTVERSION=	2.30.5
PORTREVISION=	2
CATEGORIES=	audio devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Functional programming language for realtime audio signal processing

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libLLVM-${LLVM_VERSION}.so:devel/llvm${LLVM_VERSION}
RUN_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang cmake ncurses python pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm
GH_TUPLE=	\
		grame-cncm:faustlibraries:41b6ba7:grame_cncm_faustlibraries/libraries \
		google:oboe:5eb2ea6:google_oboe/architecture/android/app/oboe \
		google:oboe:5eb2ea6:google_oboe/architecture/smartKeyboard/android/app/oboe

SHEBANG_FILES=	tools/faust2appls/* tools/benchmark/faustbench tools/sound2faust/sound2reader

LLVM_VERSION=	11 # earlier versions lack dump() function(s) that cause unresolved symbols in libfaust.so

CMAKE_SOURCE_PATH=	${WRKSRC}/build
CMAKE_ON=	INCLUDE_DYNAMIC # only installs headers and not libs without INCLUDE_DYNAMIC or INCLUDE_STATIC: https://github.com/grame-cncm/faust/issues/553
CMAKE_ARGS=	-C ${FILESDIR}/backends.cmake -DLLVM_CONFIG=${LOCALBASE}/bin/llvm-config${LLVM_VERSION} \

CXXFLAGS+=	-I${WRKSRC}/compiler/generator/cpp # fatal error: 'cpp_code_container.hh' file not found WHEN INCLUDE_STATIC=TRUE
CXXFLAGS+=	`llvm-config${LLVM_VERSION} --cflags` -DLLVM_${LLVM_VERSION}0 # for the llvm backend
LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=		EXAMPLES HIGHLIGHT HTTPD_LIB
OPTIONS_DEFAULT=	HIGHLIGHT HTTPD_LIB
OPTIONS_SUB=		yes

EXAMPLES_CMAKE_BOOL=	FREEBSD_INSTALL_EXAMPLES

HIGHLIGHT_DESC=		Syntax highlighting in Kate, gedit, Highlight, vim
HTTPD_LIB_DESC=		Build httpd support library

HTTPD_CMAKE_BOOL=	INCLUDE_HTTP
HTTPD_LIB_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd

PORTEXAMPLES=		*

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

.include <bsd.port.mk>
