# Created by: David O'Brien <obrien@cs.ucdavis.edu>
# $FreeBSD$

PORTNAME=	vim
PORTVERSION=	7.4.1832
DISTVERSIONPREFIX=	v
CATEGORIES?=	editors

MAINTAINER?=	sunpoet@FreeBSD.org
COMMENT?=	Improved version of the vi editor

OPTIONS_DEFINE=	CSCOPE DEFAULT_VIMRC EXUBERANT_CTAGS LUA NLS PERL PYTHON RUBY TCL XTERM_SAVE
OPTIONS_SINGLE=	UI
OPTIONS_SINGLE_UI=	ATHENA CONSOLE GNOME GTK2 MOTIF X11
OPTIONS_SUB=	yes
ATHENA_DESC=		Athena GUI toolkit
CSCOPE_DESC=		cscope support
CONSOLE_DESC=		Console/terminal mode
DEFAULT_VIMRC_DESC=	Install bundled vimrc as default setting
EXUBERANT_CTAGS_DESC=	Use exctags instead of ctags
UI_DESC=		User interface
XTERM_SAVE_DESC=	Restore xterm screen after exit

PORTSCOUT=	site:https://github.com/vim/vim/releases

ALL_TARGET=	# empty
MAKE_ARGS+=	CC="${CC}" CONF_ARGS="--prefix=${PREFIX} ${CSCOPE_ARG}" STRIP="${STRIP_CMD}" CONF_OPT_MULTIBYTE=--enable-multibyte CONF_TERM_LIB=--with-tlib=termlib
MAKE_ARGS+=	VIMRUNTIMEDIR=${PREFIX}/share/vim/${VIM_VER} VIMRCLOC=${ETCDIR}
REINPLACE_ARGS=	-i ''
USES=		cpe iconv ncurses pkgconfig shebangfix
WANT_GNOME=	yes

PLIST_SUB=	VIM_VER=${VIM_VER}
PORTDATA=	${VIM_VER}

VIM_VER=	${PORTNAME}${PORTVERSION:R:S|.||g}

USE_GITHUB=	yes

CPE_VERSION=	${PORTVERSION:R}

SLAVEDIRS=	editors/vim-lite

SHEBANG_FILES=	runtime/tools/efm_perl.pl

.if defined(LITE)
PKGNAMESUFFIX+=	-lite
CONFLICTS_INSTALL=	vim-[0-9]*
OPTIONS_DEFAULT=DEFAULT_VIMRC
OPTIONS_EXCLUDE=ATHENA CSCOPE EXUBERANT_CTAGS GNOME GTK2 LUA MOTIF NLS PERL PYTHON RUBY TCL X11 XTERM_SAVE
OPTIONS_SLAVE=	CONSOLE
MAKE_ARGS+=	CONF_OPT_GUI="--enable-gui=no --without-x" \
		CONF_OPT_LUA=--disable-luainterp \
		CONF_OPT_PERL=--disable-perlinterp \
		CONF_OPT_PYTHON="--disable-pythoninterp --disable-python3interp" \
		CONF_OPT_RUBY=--disable-rubyinterp \
		CONF_OPT_TCL=--disable-tclinterp
PLIST_SUB+=	NON_LITE="@comment "
.else
CONFLICTS_INSTALL=	vim-lite-[0-9]*
OPTIONS_DEFAULT=CSCOPE DEFAULT_VIMRC EXUBERANT_CTAGS GTK2 LUA PERL PYTHON RUBY TCL
MAKE_ARGS+=	CONF_OPT_FEAT=--with-features=huge \
		CONF_OPT_INPUT=--enable-xim \
		CONF_OPT_OUTPUT=--enable-fontset
PLIST_SUB+=	NON_LITE=""
.endif

ATHENA_MAKE_ARGS=	CONF_OPT_GUI=--enable-gui=athena
ATHENA_PLIST_SUB=	GUI=""
ATHENA_USE=		XORG=xaw
CONSOLE_MAKE_ARGS=	CONF_OPT_GUI="--enable-gui=no --without-x"
CONSOLE_PLIST_SUB=	GUI="@comment "
CSCOPE_MAKE_ARGS=	CONF_OPT_CSCOPE=--enable-cscope
CSCOPE_RUN_DEPENDS=	cscope:devel/cscope
EXUBERANT_CTAGS_RUN_DEPENDS=	exctags:devel/ctags
GNOME_MAKE_ARGS=	CONF_OPT_GUI=--enable-gui=gnome2 X_LIBS="$(X_LIBS) -lX11 -lXpm -lXt"
GNOME_PLIST_SUB=	GUI=""
GNOME_USE=		GNOME=libgnomeui XORG=glproto,xpm,xt
GTK2_MAKE_ARGS=		CONF_OPT_GUI=--enable-gui=gtk2 X_LIBS="$(X_LIBS) -lX11 -lXpm -lXt"
GTK2_PLIST_SUB=		GUI=""
GTK2_USE=		GNOME=gtk20 XORG=xpm,xt
LUA_MAKE_ARGS=		CONF_OPT_LUA=--enable-luainterp=dynamic CONF_OPT_LUA_PREFIX=--with-lua-prefix=${LOCALBASE}
LUA_USES=		lua
MOTIF_MAKE_ARGS=	CONF_OPT_GUI='--enable-gui=motif --with-motif-lib="${MOTIFLIB}"' MOTIFHOME=${LOCALBASE}
MOTIF_PLIST_SUB=	GUI=""
MOTIF_USES=		motif
NLS_MAKE_ARGS=		CONF_OPT_NLS=--enable-nls
NLS_MAKE_ARGS_OFF=	CONF_OPT_NLS=--disable-nls
NLS_USES=		gettext
PERL_MAKE_ARGS=		CONF_OPT_PERL=--enable-perlinterp
PERL_USES=		perl5
PYTHON_USES=		python
RUBY_MAKE_ARGS=		CONF_OPT_RUBY=--enable-rubyinterp
RUBY_USE=		RUBY=yes
TCL_MAKE_ARGS=		CONF_OPT_TCL="--enable-tclinterp --with-tclsh=tclsh${TCL_VER}"
TCL_USES=		tcl:85+
X11_MAKE_ARGS=		CONF_OPT_GUI="--enable-gui=no --with-x" X_LIBS="$(X_LIBS) -lX11 -lXt"
X11_PLIST_SUB=		GUI="@comment "
X11_USE=		XORG=x11,xt

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPYTHON}
.if ${PYTHON_REL} < 3000
MAKE_ARGS+=	CONF_OPT_PYTHON="--enable-pythoninterp --disable-python3interp"
.else
MAKE_ARGS+=	CONF_OPT_PYTHON="--enable-python3interp --disable-pythoninterp"
.endif
.endif

post-patch:
	@${FIND} ${WRKSRC}/ -name 'Makefile' | ${XARGS} ${REINPLACE_CMD} -e 's| $$<| $$>|'
	@${REINPLACE_CMD} -e '/^install_normal: / s|install-icons|# &|; /cd $$(DEST_BIN); ln -s/d' ${WRKSRC}/src/Makefile
	@${REINPLACE_CMD} -e 's|-liconv|${ICONV_LIB}|g' ${WRKSRC}/src/auto/configure
	@${ECHO_CMD} '#define SYS_VIMRC_FILE "'${ETCDIR}'/vimrc"' >> ${WRKSRC}/src/feature.h
	@${ECHO_CMD} '#define SYS_GVIMRC_FILE "'${ETCDIR}'/gvimrc"' >> ${WRKSRC}/src/feature.h

post-patch-EXUBERANT_CTAGS-off:
	@${FIND} ${WRKSRC}/runtime/ -name 'menu*.vim' -print0 | ${XARGS} -0 ${REINPLACE_CMD} -e 's|ctags -R \.|${FIND} . -type f \\\| ${XARGS} ctags|g'

post-patch-EXUBERANT_CTAGS-on:
	@${FIND} ${WRKSRC}/runtime/ -name 'menu*.vim' -print0 | ${XARGS} -0 ${REINPLACE_CMD} -e 's|ctags -R \.|exctags -R .|g'

pre-configure:
	@${CP} ${WRKSRC}/src/config.mk.dist ${WRKSRC}/src/auto/config.mk
	@(cd ${WRKSRC}/src/ && ${MAKE_CMD} distclean)
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|\$$gtk_config_prefix/bin/gtk-config|\$${GTK_CONFIG}|g' \
		-e 's|\$$gtk_config_exec_prefix/bin/gtk-config|\$${GTK_CONFIG}|g' \
		-e 's|set dummy lua;|set dummy ${LUA_CMD};|g' ${WRKSRC}/src/auto/configure

pre-configure-XTERM_SAVE-on:
	@${REINPLACE_CMD} -e '/FEAT_XTERM_SAVE/ s|.*|#define FEAT_XTERM_SAVE|' ${WRKSRC}/src/feature.h

post-configure:
	@(cd ${WRKSRC}/src/ && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} scratch config)
	@${REINPLACE_CMD} -e 's|#define HAVE_SYSINFO 1|/* #undef HAVE_SYSINFO */|' ${WRKSRC}/src/auto/config.h

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/${VIM_VER}/lang/
.for file in evim rview rvim vimdiff
	${TEST} -e ${STAGEDIR}${PREFIX}/bin/${file} || ${LN} -fs vim ${STAGEDIR}${PREFIX}/bin/${file}
.endfor
.if !${PORT_OPTIONS:MCONSOLE} && !${PORT_OPTIONS:MX11}
.for file in eview gview gvim gvimdiff rgview rgvim
	${TEST} -e ${STAGEDIR}${PREFIX}/bin/${file} || ${LN} -fs vim ${STAGEDIR}${PREFIX}/bin/${file}
.endfor
.endif

post-install-DEFAULT_VIMRC-on:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/vimrc ${STAGEDIR}${ETCDIR}/gvimrc.sample
	${INSTALL_DATA} ${FILESDIR}/vimrc ${STAGEDIR}${ETCDIR}/vimrc.sample

post-install-NLS-off:
	${MKDIR} ${STAGEDIR}${DATADIR}/${VIM_VER}/keymap/
	${INSTALL_DATA} ${WRKSRC}/runtime/keymap/* ${STAGEDIR}${DATADIR}/${VIM_VER}/keymap/
	${INSTALL_DATA} ${FILESDIR}/vietnamese_viscii.vim ${STAGEDIR}${DATADIR}/${VIM_VER}/keymap/

post-install-NLS-on:
	${INSTALL_DATA} ${FILESDIR}/vietnamese_viscii.vim ${STAGEDIR}${DATADIR}/${VIM_VER}/keymap/

.include <bsd.port.post.mk>
