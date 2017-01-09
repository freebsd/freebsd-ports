# Created by: David O'Brien <obrien@cs.ucdavis.edu>
# $FreeBSD$

PORTNAME=	vim
PORTVERSION=	8.0.0149
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	adamw@FreeBSD.org
COMMENT?=	Improved version of the vi editor

LICENSE=	VIM
LICENSE_NAME=	VIM License
LICENSE_FILE=	${WRKSRC}/runtime/doc/uganda.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

OPTIONS_DEFINE=		CSCOPE DEFAULT_VIMRC EXUBERANT_CTAGS NLS XTERM_SAVE
OPTIONS_SINGLE=		UI
OPTIONS_SINGLE_UI=	ATHENA CONSOLE GNOME GTK2 GTK3 MOTIF X11
OPTIONS_GROUP=		LANGBIND
OPTIONS_GROUP_LANGBIND=	LUA PERL PYTHON RUBY TCL
OPTIONS_SUB=		yes

DEFAULT_VIMRC_DESC=	Install bundled vimrc as default setting
EXUBERANT_CTAGS_DESC=	Use exctags instead of ctags
XTERM_SAVE_DESC=	Restore xterm screen after exit

UI_DESC=		User interface
ATHENA_DESC=		Athena GUI toolkit
CSCOPE_DESC=		cscope support
CONSOLE_DESC=		Console/terminal mode

LANGBIND_DESC=		Optional language bindings

ALL_TARGET=	# empty
MAKE_ARGS+=	CC="${CC}" CONF_ARGS="--prefix=${PREFIX} ${CSCOPE_ARG}" STRIP="${STRIP_CMD}"
MAKE_ARGS+=	VIMRUNTIMEDIR=${PREFIX}/share/vim/${VIM_VER} VIMRCLOC=${ETCDIR}
MAKE_ARGS+=	CONF_OPT_MULTIBYTE=--enable-multibyte CONF_TERM_LIB=--with-tlib=ncurses
REINPLACE_ARGS=	-i ''
USES=		cpe iconv ncurses pkgconfig shebangfix
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB=	VIM_VER=${VIM_VER}
PORTDATA=	${VIM_VER}
VIM_VER=	${PORTNAME}${PORTVERSION:R:S|.||g}
SLAVEDIRS=	editors/vim-lite

USE_GITHUB=	yes
SHEBANG_FILES=	runtime/tools/efm_perl.pl
CPE_VERSION=	${PORTVERSION:R}
PORTSCOUT=	site:https://github.com/vim/vim/releases

.if defined(LITE)
PKGNAMESUFFIX+=	-lite
CONFLICTS_INSTALL=	vim-[0-9]*
OPTIONS_DEFAULT=DEFAULT_VIMRC
OPTIONS_SLAVE=	CONSOLE
OPTIONS_EXCLUDE:=	${OPTIONS_DEFINE:NDEFAULT_VIMRC} \
			${OPTIONS_SINGLE_UI:NCONSOLE} \
			${OPTIONS_GROUP_LANGBIND}
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

# GENERAL OPTIONS
CSCOPE_MAKE_ARGS=	CONF_OPT_CSCOPE=--enable-cscope
CSCOPE_RUN_DEPENDS=	cscope:devel/cscope

EXUBERANT_CTAGS_RUN_DEPENDS=	exctags:devel/ctags

NLS_MAKE_ARGS=		CONF_OPT_NLS=--enable-nls
NLS_MAKE_ARGS_OFF=	CONF_OPT_NLS=--disable-nls
NLS_USES=		gettext

# UI
ATHENA_MAKE_ARGS=	CONF_OPT_GUI=--enable-gui=athena
ATHENA_PLIST_SUB=	GUI="" DESKTOP="@comment "
ATHENA_USE=		XORG=ice,sm,x11,xaw,xmu,xpm,xt

CONSOLE_MAKE_ARGS=	CONF_OPT_GUI="--enable-gui=no --without-x"
CONSOLE_PLIST_SUB=	GUI="@comment " DESKTOP="@comment "

GNOME_MAKE_ARGS=	CONF_OPT_GUI=--enable-gui=gnome2
GNOME_PLIST_SUB=	GUI="" DESKTOP=""
GNOME_IMPLIES=		NLS
GNOME_USE=		GNOME=gdkpixbuf2,libgnomeui XORG=ice,sm,glproto,x11,xpm,xt
GNOME_USES=		desktop-file-utils

GTK2_MAKE_ARGS=		CONF_OPT_GUI=--enable-gui=gtk2
GTK2_PLIST_SUB=		GUI="" DESKTOP=""
GTK2_USE=		GNOME=gdkpixbuf2,gtk20 XORG=ice,sm,x11,xpm,xt
GTK2_USES=		desktop-file-utils

GTK3_MAKE_ARGS=		CONF_OPT_GUI=--enable-gui=gtk3
GTK3_PLIST_SUB=		GUI="" DESKTOP=""
GTK3_USE=		GNOME=cairo,gdkpixbuf2,gtk30 XORG=ice,sm,x11,xpm,xt
GTK3_USES=		desktop-file-utils

MOTIF_MAKE_ARGS=	CONF_OPT_GUI='--enable-gui=motif --with-motif-lib="${MOTIFLIB}"' MOTIFHOME=${LOCALBASE}
MOTIF_PLIST_SUB=	GUI="" DESKTOP="@comment "
MOTIF_USES=		motif
MOTIF_USE=		XORG=ice,sm,x11,xmu,xt

X11_MAKE_ARGS=		CONF_OPT_GUI="--enable-gui=no --with-x"
X11_PLIST_SUB=		GUI="@comment " DESKTOP="@comment "
X11_USE=		XORG=ice,sm,x11,xt

# LANGUAGE BINDINGS
LUA_MAKE_ARGS=		CONF_OPT_LUA=--enable-luainterp=dynamic CONF_OPT_LUA_PREFIX=--with-lua-prefix=${LOCALBASE}
LUA_USES=		lua

PERL_MAKE_ARGS=		CONF_OPT_PERL=--enable-perlinterp
PERL_USES=		perl5

PYTHON_USES=		python

RUBY_MAKE_ARGS=		CONF_OPT_RUBY=--enable-rubyinterp
RUBY_USE=		RUBY=yes

TCL_MAKE_ARGS=		CONF_OPT_TCL="--enable-tclinterp --with-tclsh=tclsh${TCL_VER}"
TCL_USES=		tcl:85+

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPYTHON}
.if ${PYTHON_REL} < 3000
MAKE_ARGS+=	CONF_OPT_PYTHON="--enable-pythoninterp --disable-python3interp"
.else
MAKE_ARGS+=	CONF_OPT_PYTHON="--enable-python3interp --disable-pythoninterp"
.endif
.endif

post-extract:
	${INSTALL_DATA} ${FILESDIR}/vietnamese_viscii.vim ${WRKSRC}/runtime/keymap

post-patch:
	@${FIND} ${WRKSRC}/ -name 'Makefile' | ${XARGS} ${REINPLACE_CMD} -e 's| $$<| $$>|'
	@${REINPLACE_CMD} -e 's|-liconv|${ICONV_LIB}|g' ${WRKSRC}/src/auto/configure
	@${ECHO_CMD} '#define SYS_VIMRC_FILE "'${ETCDIR}'/vimrc"' >> ${WRKSRC}/src/feature.h
	@${ECHO_CMD} '#define SYS_GVIMRC_FILE "'${ETCDIR}'/gvimrc"' >> ${WRKSRC}/src/feature.h

post-patch-EXUBERANT_CTAGS-off:
	@${FIND} ${WRKSRC}/runtime/ -name 'menu*.vim' -print0 | ${XARGS} -0 ${REINPLACE_CMD} -e 's|ctags -R \.|${FIND} . -type f \\\| ${XARGS} ctags|g'

post-patch-EXUBERANT_CTAGS-on:
	@${FIND} ${WRKSRC}/runtime/ -name 'menu*.vim' -print0 | ${XARGS} -0 ${REINPLACE_CMD} -e 's|ctags -R \.|exctags -R .|g'

pre-configure:
	@${CP} ${WRKSRC}/src/config.mk.dist ${WRKSRC}/src/auto/config.mk
	@${DO_MAKE_BUILD} -C ${WRKSRC}/src distclean
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e 's|\$$gtk_config_prefix/bin/gtk-config|\$${GTK_CONFIG}|g' \
		-e 's|\$$gtk_config_exec_prefix/bin/gtk-config|\$${GTK_CONFIG}|g' \
		-e 's|set dummy lua;|set dummy ${LUA_CMD};|g' ${WRKSRC}/src/auto/configure

pre-configure-XTERM_SAVE-on:
	@${REINPLACE_CMD} -e '/FEAT_XTERM_SAVE/ s|.*|#define FEAT_XTERM_SAVE|' ${WRKSRC}/src/feature.h

post-configure:
	@${DO_MAKE_BUILD} -C ${WRKSRC}/src scratch config
	@${REINPLACE_CMD} -e 's|#define HAVE_SYSINFO 1|/* #undef HAVE_SYSINFO */|' ${WRKSRC}/src/auto/config.h

post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/ex
	@${RM} ${STAGEDIR}${PREFIX}/bin/view
.for F in eview evim gview gvim gvimdiff rgview rgvim rview rvim vimdiff
	${LN} -sf vim ${STAGEDIR}${PREFIX}/bin/$F
.endfor

post-install-DEFAULT_VIMRC-on:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${SED} -e '/set nocompatible/d' ${FILESDIR}/vimrc > ${STAGEDIR}${ETCDIR}/gvimrc.sample
	${INSTALL_DATA} ${FILESDIR}/vimrc ${STAGEDIR}${ETCDIR}/vimrc.sample

post-install-NLS-off:
	@${MKDIR} ${STAGEDIR}${DATADIR}/${VIM_VER}/lang
	@${MKDIR} ${STAGEDIR}${DATADIR}/${VIM_VER}/keymap
	${INSTALL_DATA} ${WRKSRC}/runtime/keymap/* ${STAGEDIR}${DATADIR}/${VIM_VER}/keymap

.include <bsd.port.post.mk>
