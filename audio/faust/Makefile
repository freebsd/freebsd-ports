# Created by: Yuri Victorovich <yuri@FreeBSD.org>
# $FreeBSD$

PORTNAME=	faust
DISTVERSION=	2.5.23
CATEGORIES=	audio devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Functional programming language for realtime audio signal processing

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libLLVM-${LLVM_VERSION:C/([1-9])([0-9])/\1.\2/}.so:devel/llvm${LLVM_VERSION}

USES=		gmake ncurses python pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	grame-cncm
GH_TUPLE=	grame-cncm:faustlibraries:f889fe1:libs/libraries \
		ThatOtherPerson:xxd:cd8ecce:xxd/xxd-replacement
USE_CXXSTD=	c++11
SHEBANG_FILES=	tools/faust2appls/* tools/benchmark/faustbench
LLVM_VERSION=	50
MAKE_ENV=	LLVM_CONFIG=${LOCALBASE}/bin/llvm-config${LLVM_VERSION}

OPTIONS_DEFINE=	HIGHLIGHT HTTPD_LIB
OPTIONS_DEFAULT=	HIGHLIGHT HTTPD_LIB
HIGHLIGHT_DESC=	Syntax highlighting in Kate, gedit, Highlight, vim
HTTPD_LIB_DESC=	Build httpd support library
OPTIONS_SUB=	yes

HTTPD_LIB_ALL_TARGET=	all httpd
HTTPD_LIB_LIB_DEPENDS=	libmicrohttpd.so:www/libmicrohttpd

# Fix of the upstream bug https://github.com/grame-cncm/faust/issues/76 will kill most of the patches.
post-patch:
	@${REINPLACE_CMD} -i '' -e 's|make -C|$$(MAKE) -C| ; s|share/man|man|g' \
		${WRKSRC}/Makefile \
		${WRKSRC}/architecture/osclib/Makefile
	@${REINPLACE_CMD} -i '' -e 's| -O1|| ; s|-o faust|-lexecinfo -o faust|' \
		${WRKSRC}/compiler/Makefile.unix
	@${RM} -r ${WRKSRC}/architecture/osclib/oscpack/ip/win32
	@${REINPLACE_CMD} -i '' -e 's|__linux__|__FreeBSD__|' \
		${WRKSRC}/architecture/faust/dsp/timed-dsp.h
	@${REINPLACE_CMD} -i '' -e 's|jack_midi_reset_buffer|jack_midi_clear_buffer|' \
		${WRKSRC}/architecture/faust/gui/ControlUI.h \
		${WRKSRC}/architecture/faust/midi/jack-midi.h
	@${REINPLACE_CMD} -i '' -e "s|CXX='g++'|CXX='clang++'|" \
		${WRKSRC}/benchmark/Makefile
	@${REINPLACE_CMD} -i '' -e 's|CXX=g++|CXX=clang++|' \
		${WRKSRC}/tools/faust2appls/faust2* \
		${WRKSRC}/tools/dx72faust/Makefile \
		${WRKSRC}/tools/physicalModeling/mesh2faust/vega/Makefile-headers/Makefile-header.*
	@${REINPLACE_CMD} -i '' -e 's|g++|clang++|' \
		${WRKSRC}/embedded/faustcsound/Makefile \
		${WRKSRC}/embedded/faustremote/Makefile \
		${WRKSRC}/embedded/faustremote/RemoteClient/Example/Makefile \
		${WRKSRC}/embedded/faustremote/RemoteClient/Example/Makefile \
		${WRKSRC}/embedded/faustremote/RemoteClient/SimpleExample/Makefile_Linux \
		${WRKSRC}/embedded/faustremote/RemoteServer/Makefile \
		${WRKSRC}/run_test_cpp.sh \
		${WRKSRC}/tests/impulse-tests/faust2* \
		${WRKSRC}/tests/impulse-tests/install.sh \
		${WRKSRC}/tools/benchmark/faustbench \
		${WRKSRC}/tools/faust2appls/faust2ros \
		${WRKSRC}/tools/faust2appls/faust2rosgtk \
		${WRKSRC}/tools/faust2appls/faust2vst \
		${WRKSRC}/tools/faust2appls/faust2vsti \
		${WRKSRC}/tools/faust2appls/faust2w32max6 \
		${WRKSRC}/tools/faust2appls/faust2w32msp \
		${WRKSRC}/tools/faust2appls/faust2w32puredata \
		${WRKSRC}/tools/faust2appls/faust2w32vst \
		${WRKSRC}/tools/physicalModeling/mesh2faust/vega/libraries/glui/Makefile \
		${WRKSRC}/tools/physicalModeling/mesh2faust/vega/libraries/glui/glui-2.35/src/makefile
	@${GREP} -rl llvm-config ${WRKSRC} | \
		${XARGS} -L 1 ${REINPLACE_CMD} -i '' -e "s|llvm-config|llvm-config${LLVM_VERSION}|"
	@${REINPLACE_CMD} -i '' -e "s|LLVM_VERSION), 4.0.0))|LLVM_VERSION), $$(llvm-config${LLVM_VERSION} --version)))|" \
		${WRKSRC}/compiler/Makefile.unix
	@${REINPLACE_CMD} -i '' "s|^CC|#CC|; s|^CFLAGS|#CFLAGS|" \
		${WRKSRC}/xxd-replacement/Makefile
	@${REINPLACE_CMD} -i '' "s|xxd|${WRKSRC}/xxd-replacement/xxd|" \
		${WRKSRC}/compiler/Makefile.unix \
		${WRKSRC}/architecture/httpdlib/src/Makefile

pre-build:
	cd ${WRKSRC}/xxd-replacement && ${MAKE_CMD}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/faust
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/faust # https://github.com/grame-cncm/faust/issues/135

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
