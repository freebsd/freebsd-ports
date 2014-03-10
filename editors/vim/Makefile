# Created by: David O'Brien <obrien@cs.ucdavis.edu>
# $FreeBSD$

PORTNAME=	vim
PORTVERSION=	7.4.${PATCHLEVEL}
PORTREVISION?=	1
CATEGORIES?=	editors
MASTER_SITES=	VIM:source \
		${MASTER_SITE_VIM:S|unix|patches/${PORTVERSION:R}|}:patch \
		LOCAL/sunpoet/${PORTNAME}:source,patch
DISTFILES=	${PORTNAME}-${PORTVERSION:R}${EXTRACT_SUFX}:source
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION:R}${EXTRACT_SUFX}

PATCH_SITES=	${MASTER_SITE_VIM:S|unix|patches/${PORTVERSION:R}|} \
		LOCAL/sunpoet/${PORTNAME}

MAINTAINER?=	sunpoet@FreeBSD.org
COMMENT?=	Improved version of the vi editor

OPTIONS_DEFINE=	CSCOPE EXUBERANT_CTAGS LUA NLS PERL PYTHON RUBY TCL XTERM_SAVE
OPTIONS_SINGLE=	UI
OPTIONS_SINGLE_UI=	ATHENA CONSOLE GNOME GTK2 MOTIF X11
OPTIONS_SUB=	yes
ATHENA_DESC=		Athena GUI toolkit
CSCOPE_DESC=		cscope support
CONSOLE_DESC=		Console/terminal mode
EXUBERANT_CTAGS_DESC=	Use exctags instead of ctags
UI_DESC=		User interface
XTERM_SAVE_DESC=	Restore xterm screen after exit

ALL_TARGET=	# empty
MAKE_ARGS+=	CC=${CC} CONF_ARGS="--prefix=${PREFIX} ${CSCOPE_ARG}" STRIP=${STRIP_CMD} CONF_OPT_MULTIBYTE=--enable-multibyte CONF_TERM_LIB=--with-tlib=termlib
MAKE_JOBS_UNSAFE=	yes
PATCH_DIST_ARGS=--batch --directory ${WRKSRC} --forward --quiet --remove-empty-files ${PATCH_DIST_STRIP}
REINPLACE_ARGS=	-i ''
USE_BZIP2=	yes
USES=		iconv pkgconfig shebangfix
WANT_GNOME=	yes

PATCHLEVEL=	193
PATCHFILES!=	/usr/bin/jot -s " " -w "%03d" ${PATCHLEVEL} 1 ${PATCHLEVEL}
BADPATCHES=	064 087 147 # empty
.for p in ${BADPATCHES}
DISTFILES+=	${PORTVERSION:R}.${p}:patch
PATCHFILES:=	${PATCHFILES:N${p}}
.endfor
PATCHFILES:=	${PATCHFILES:C/^/${PORTVERSION:R}./g}

BUILD_WRKSRC=	${WRKDIR}/${VIM_VER}/src
CONFIGURE_WRKSRC=	${WRKDIR}/${VIM_VER}/src
INSTALL_WRKSRC=	${WRKDIR}/${VIM_VER}/src
WRKSRC=		${WRKDIR}/${VIM_VER}

PLIST_SUB=	VIM_VER=${VIM_VER}
PORTDATA=	*

VIM_VER=	${PORTNAME}${PORTVERSION:R:S/.//g}

SLAVEDIRS=	editors/vim-lite

SHEBANG_FILES=	runtime/tools/efm_perl.pl

.if defined(LITE)
PKGNAMESUFFIX+=	-lite
CONFLICTS_INSTALL=	vim-[0-9]*
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
OPTIONS_DEFAULT=CSCOPE EXUBERANT_CTAGS GTK2 LUA PERL PYTHON RUBY TCL
MAKE_ARGS+=	CONF_OPT_FEAT=--with-features=big \
		CONF_OPT_INPUT=--enable-xim \
		CONF_OPT_OUTPUT=--enable-fontset
PLIST_SUB+=	NON_LITE=""
.endif

ATHENA_MAKE_ARGS=	CONF_OPT_GUI=--enable-gui=athena
ATHENA_USE=		XORG=xaw
CONSOLE_MAKE_ARGS=	CONF_OPT_GUI="--enable-gui=no --without-x"
CSCOPE_MAKE_ARGS=	CONF_OPT_CSCOPE=--enable-cscope
CSCOPE_RUN_DEPENDS=	${LOCALBASE}/bin/cscope:${PORTSDIR}/devel/cscope
EXUBERANT_CTAGS_RUN_DEPENDS=	${LOCALBASE}/bin/exctags:${PORTSDIR}/devel/ctags
GNOME_MAKE_ARGS=	CONF_OPT_GUI=--enable-gui=gnome2 X_LIBS="$(X_LIBS) -lX11 -lXpm -lXt"
GNOME_USE=		GNOME=libgnomeui XORG=glproto,xpm,xt
GTK2_MAKE_ARGS=		CONF_OPT_GUI=--enable-gui=gtk2 X_LIBS="$(X_LIBS) -lX11 -lXpm -lXt"
GTK2_USE=		GNOME=gtk20 XORG=xpm,xt
LUA_MAKE_ARGS=		CONF_OPT_LUA=--enable-luainterp=dynamic CONF_OPT_LUA_PREFIX=--with-lua-prefix=${LOCALBASE}
LUA_USES=		lua
MOTIF_MAKE_ARGS=	CONF_OPT_GUI='--enable-gui=motif --with-motif-lib="${MOTIFLIB}"' MOTIFHOME=${LOCALBASE}
MOTIF_USES=		motif
NLS_MAKE_ARGS=		CONF_OPT_NLS=--enable-nls
NLS_MAKE_ARGS_OFF=	CONF_OPT_NLS=--disable-nls
NLS_USES=		gettext
PERL_MAKE_ARGS=		CONF_OPT_PERL=--enable-perlinterp
PERL_USES=		perl5
PYTHON_USE=		PYTHON=yes
RUBY_MAKE_ARGS=		CONF_OPT_RUBY=--enable-rubyinterp
RUBY_USE=		RUBY=yes
TCL_MAKE_ARGS=		CONF_OPT_TCL="--enable-tclinterp --with-tclsh=tclsh${TCL_VER}"
TCL_USES=		tcl:85+
X11_MAKE_ARGS=		CONF_OPT_GUI="--enable-gui=no --with-x" X_LIBS="$(X_LIBS) -lX11 -lXt"
X11_USE=		XORG=x11,xt

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MATHENA} && !${PORT_OPTIONS:MCONSOLE} && !${PORT_OPTIONS:MGNOME} && !${PORT_OPTIONS:MGTK2} && !${PORT_OPTIONS:MMOTIF} && !${PORT_OPTIONS:MX11}
IGNORE=		this port has new UI option (CONSOLE) for users who do not need GUI support. Please run "make config" to modify your setting
.endif

.if ${PORT_OPTIONS:MCONSOLE} || ${PORT_OPTIONS:MX11}
PLIST_SUB+=	GUI="@comment "
.else
PLIST_SUB+=	GUI=""
.endif

.if ${PORT_OPTIONS:MEXUBERANT_CTAGS}
CTAGS_CMD=	exctags -R .
.else
CTAGS_CMD=	${FIND} . -type f \\| ${XARGS} ctags
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPYTHON}
.if ${PYTHON_REL} < 300
MAKE_ARGS+=	CONF_OPT_PYTHON="--enable-pythoninterp --disable-python3interp"
.else
MAKE_ARGS+=	CONF_OPT_PYTHON="--enable-python3interp --disable-pythoninterp"
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^install_normal: / s|install-icons|# &|; /cd $$(DEST_BIN); ln -s/d' ${WRKSRC}/src/Makefile
	@${FIND} ${WRKSRC}/runtime/ -name menu\*.vim -print0 | ${XARGS} -0 ${REINPLACE_CMD} -e 's,ctags -R \\.,${CTAGS_CMD},g'
.for badpatch in ${BADPATCHES}
	@${ECHO_MSG} "===>   Applying distribution patch ${badpatch}"
	@${PATCH} ${PATCH_DIST_ARGS} -i ${_DISTDIR}/${PORTVERSION:R}.${badpatch}
.endfor

pre-configure:
	@${CP} ${WRKSRC}/src/config.mk.dist ${WRKSRC}/src/auto/config.mk
	@(cd ${WRKSRC}/src/ && ${MAKE} distclean)
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|\$$gtk_config_prefix/bin/gtk-config|\$${GTK_CONFIG}|g' \
		-e 's|\$$gtk_config_exec_prefix/bin/gtk-config|\$${GTK_CONFIG}|g' \
		-e 's|set dummy lua;|set dummy ${LUA_CMD};|g' ${WRKSRC}/src/auto/configure
.if ${PORT_OPTIONS:MXTERM_SAVE}
	@${REINPLACE_CMD} -e '/FEAT_XTERM_SAVE/ s|.*|#define FEAT_XTERM_SAVE|' ${WRKSRC}/src/feature.h
.endif

post-configure:
	@(cd ${WRKSRC}/src/ && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} scratch config)
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
.if !${PORT_OPTIONS:MNLS}
	${MKDIR} ${STAGEDIR}${DATADIR}/${VIM_VER}/keymap/
	${INSTALL_DATA} ${WRKSRC}/runtime/keymap/* ${STAGEDIR}${DATADIR}/${VIM_VER}/keymap/
.endif
	${INSTALL_DATA} ${FILESDIR}/vietnamese_viscii.vim ${STAGEDIR}${DATADIR}/${VIM_VER}/keymap/
	${TOUCH} ${STAGEDIR}${DATADIR}/${VIM_VER}/lang/.keepme

.include <bsd.port.post.mk>
