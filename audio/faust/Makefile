# Created by: Yuri Victorovich <yuri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	faust
DISTVERSION=	2.27.2
CATEGORIES=	audio devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Functional programming language for realtime audio signal processing

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS=	libLLVM-${LLVM_VERSION:C/([1-9])([0-9])/\1/}.so:devel/llvm${LLVM_VERSION}

USES=		compiler:c++11-lang cmake ncurses python pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm
GH_TUPLE=	\
		grame-cncm:faustlibraries:cde57d76dd8c4b124998a5490164e4b58ae9495f:grame_cncm_faustlibraries/libraries \
		google:oboe:f644b60eaf0deea5b9c7af443e28d42c4995b59e:google_oboe/architecture/android/app/oboe \
		google:oboe:f644b60eaf0deea5b9c7af443e28d42c4995b59e:google_oboe/architecture/smartKeyboard/android/app/oboe \

SHEBANG_FILES=	tools/faust2appls/* tools/benchmark/faustbench tools/sound2faust/sound2reader

LLVM_VERSION=	${LLVM_DEFAULT}

CMAKE_SOURCE_PATH=	${WRKSRC}/build
CMAKE_ARGS=	-DLLVM_BACKEND=COMPILER -DLLVM_CONFIG=${LOCALBASE}/bin/llvm-config${LLVM_VERSION}

CXXFLAGS+=	-DCPP_BUILD -DOCPP_BUILD # enable backends
LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=		EXAMPLES HIGHLIGHT HTTPD_LIB
OPTIONS_DEFAULT=	HIGHLIGHT
OPTIONS_SUB=		yes

EXAMPLES_CMAKE_BOOL=	FREEBSD_INSTALL_EXAMPLES

HIGHLIGHT_DESC=		Syntax highlighting in Kate, gedit, Highlight, vim
HTTPD_LIB_DESC=		Build httpd support library

HTTPD_LIB_ALL_TARGET=	all httpd
HTTPD_LIB_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd
HTTPD_LIB_BROKEN=	TODO fix after change to cmake

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
