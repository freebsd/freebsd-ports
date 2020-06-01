# Created by: David O'Brien <obrien@cs.ucdavis.edu>
# $FreeBSD$

PORTNAME=	vim
PORTVERSION=	8.2.0869
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	adamw@FreeBSD.org
COMMENT?=	Improved version of the vi editor

LICENSE=	VIM
LICENSE_NAME=	VIM License
LICENSE_FILE=	${WRKSRC}/runtime/doc/uganda.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe iconv ncurses pkgconfig shebangfix
USE_GITHUB=	yes

CONFLICTS_INSTALL?=	vim-console vim-tiny

CONFIGURE_ARGS=	--enable-gui=${GUI} \
		--enable-multibyte \
		--with-tlib=ncurses
MAKE_ARGS=	STRIP="${STRIP_CMD}" \
		VIMRCLOC=${ETCDIR} \
		VIMRUNTIMEDIR=${PREFIX}/share/vim/${VIM_VER}

CPE_VERSION=	${PORTVERSION:R}
GNU_CONFIGURE=	yes
PLIST_SUB=	VIM_VER=${VIM_VER}
PORTDATA?=	${VIM_VER}
PORTSCOUT=	ignore:1
SHEBANG_FILES=	runtime/tools/demoserver.py runtime/tools/efm_perl.pl
VIM_VER=	${PORTNAME}${PORTVERSION:R:S|.||g}

# OPTIONS
# ### Make sure any new options are excluded below in CONSOLE/TINY
OPTIONS_DEFAULT=	CSCOPE DEFAULT_VIMRC CTAGS_EXUBERANT GTK3 PERL PYTHON RUBY
OPTIONS_DEFINE=		CSCOPE DEFAULT_VIMRC MAKE_JOBS NLS XTERM_SAVE
OPTIONS_SINGLE=		CTAGS UI
OPTIONS_SINGLE_CTAGS=	CTAGS_BASE CTAGS_EXUBERANT CTAGS_UNIVERSAL
OPTIONS_SINGLE_UI=	ATHENA CONSOLE GNOME GTK2 GTK3 MOTIF X11
OPTIONS_GROUP=		LANGBIND
OPTIONS_GROUP_LANGBIND=	LUA PERL PYTHON RUBY SCHEME TCL
OPTIONS_SUB=		yes

.if defined(CONSOLE) || defined(TINY)
OPTIONS_SLAVE=		CONSOLE
# Exclude everything except CONSOLE, DEFAULT_VIMRC, MAKE_JOBS
OPTIONS_EXCLUDE:=	${OPTIONS_DEFINE:NDEFAULT_VIMRC:NMAKE_JOBS} \
			${OPTIONS_SINGLE_UI:NCONSOLE} \
			${OPTIONS_GROUP_LANGBIND} \
			${OPTIONS_SINGLE_CTAGS}
.endif

DEFAULT_VIMRC_DESC=	Install bundled vimrc as default setting
MAKE_JOBS_DESC=		Enable parallel build
XTERM_SAVE_DESC=	Restore xterm screen after exit

CTAGS_BASE_DESC=	Use system ctags
CTAGS_EXUBERANT_DESC=	Use exctags instead of ctags
CTAGS_UNIVERSAL_DESC=	Use uctags instead of ctags

UI_DESC=		User interface
ATHENA_DESC=		Athena GUI toolkit
CSCOPE_DESC=		cscope support
CONSOLE_DESC=		Console/terminal mode

LANGBIND_DESC=		Optional language bindings
SCHEME_DESC=		MzScheme (Racket) bindings

# BROKEN: ruby.h: error: wrong number of arguments specified for 'deprecated' attribute
OPTIONS_EXCLUDE_powerpc64=	RUBY

# GENERAL OPTIONS
CSCOPE_CONFIGURE_ENABLE=cscope
CSCOPE_RUN_DEPENDS=	cscope:devel/cscope

CTAGS_EXUBERANT_RUN_DEPENDS=	exctags:devel/ctags
CTAGS_UNIVERSAL_RUN_DEPENDS=	uctags:devel/universal-ctags

MAKE_JOBS_VARS_OFF=	MAKE_JOBS_UNSAFE=yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

# UI
ATHENA_PLIST_SUB=	GUI="" DESKTOP="@comment "
ATHENA_USES=		xorg
ATHENA_USE=		XORG=ice,sm,x11,xaw,xmu,xpm,xt
ATHENA_VARS=		GUI=athena

CONSOLE_CONFIGURE_OFF=	--enable-xim --enable-fontset
CONSOLE_PLIST_SUB=	GUI="@comment " DESKTOP="@comment "
CONSOLE_VARS=		GUI=no

GNOME_CONFIGURE_ENABLE=	canberra
GNOME_LIB_DEPENDS=	libcanberra.so:audio/libcanberra
GNOME_PLIST_SUB=	GUI="" DESKTOP=""
GNOME_IMPLIES=		NLS
GNOME_USE=		GNOME=gdkpixbuf2,libgnomeui XORG=ice,sm,xorgproto,x11,xpm,xt
GNOME_USES=		desktop-file-utils gnome xorg
GNOME_VARS=		GUI=gnome2 INSTALLS_ICONS=yes

GTK2_PLIST_SUB=		GUI="" DESKTOP=""
GTK2_USE=		GNOME=gdkpixbuf2,gtk20 XORG=ice,sm,x11,xpm,xt
GTK2_USES=		desktop-file-utils gnome xorg
GTK2_VARS=		GUI=gtk2 INSTALLS_ICONS=yes

GTK3_PLIST_SUB=		GUI="" DESKTOP=""
GTK3_USE=		GNOME=cairo,gdkpixbuf2,gtk30 XORG=ice,sm,x11,xpm,xt
GTK3_USES=		desktop-file-utils gnome xorg
GTK3_VARS=		GUI=gtk3 INSTALLS_ICONS=yes

MOTIF_CONFIGURE_ENV=	MOTIFHOME=${LOCALBASE}
MOTIF_CONFIGURE_WITH=	motif-lib="${MOTIFLIB}"
MOTIF_PLIST_SUB=	GUI="" DESKTOP="@comment "
MOTIF_USE=		XORG=ice,sm,x11,xmu,xt
MOTIF_USES=		motif xorg
MOTIF_VARS=		GUI=motif

X11_CONFIGURE_WITH=	x
X11_PLIST_SUB=		GUI="@comment " DESKTOP="@comment "
X11_USE=		XORG=ice,sm,x11,xt
X11_USES=		xorg
X11_VARS=		GUI=no

# LANGUAGE BINDINGS
LUA_CONFIGURE_ENABLE=	luainterp
LUA_CONFIGURE_WITH=	lua-prefix=${LOCALBASE}
LUA_USES=		lua

PERL_CONFIGURE_ENABLE=	perlinterp
PERL_USES=		perl5

PYTHON_USES=		python
PYTHON_USES_OFF=	python:env

RUBY_CONFIGURE_ENABLE=	rubyinterp
RUBY_USE=		RUBY=yes

SCHEME_CONFIGURE_ENABLE=mzschemeinterp
SCHEME_BUILD_DEPENDS=	mzscheme:lang/racket
SCHEME_RUN_DEPENDS=	${SCHEME_BUILD_DEPENDS}

TCL_CONFIGURE_ENABLE=	tclinterp
TCL_CONFIGURE_WITH=	tclsh=tclsh${TCL_VER}
TCL_USES=		tcl

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPYTHON}
.  if !empty(WITH_DEBUG)
CFLAGS+=		-DPy_DEBUG -DPy_DEBUG_NO_PYMALLOC
.  endif
.  if ${PYTHON_MAJOR_VER} == 3
CONFIGURE_ARGS+=	--enable-python3interp --with-python3-command=${PYTHON_CMD}
.  else
CONFIGURE_ARGS+=	--enable-pythoninterp  --with-python-command=${PYTHON_CMD}
.  endif
.endif

post-extract:
	${INSTALL_DATA} ${FILESDIR}/vietnamese_viscii.vim ${WRKSRC}/runtime/keymap

post-patch:
	${ECHO_CMD} '#define SYS_VIMRC_FILE "'${ETCDIR}'/vimrc"' >> ${WRKSRC}/src/feature.h
	${ECHO_CMD} '#define SYS_GVIMRC_FILE "'${ETCDIR}'/gvimrc"' >> ${WRKSRC}/src/feature.h
	${REINPLACE_CMD} -e 's|-liconv|${ICONV_LIB}|g; s|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/src/auto/configure

post-configure:
# Needed when devel/libsysinfo is installed:
	${REINPLACE_CMD} -e '/#define HAVE_SYSINFO 1/ d' ${WRKSRC}/src/auto/config.h

post-install-DEFAULT_VIMRC-on:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${FILESDIR}/vimrc ${STAGEDIR}${ETCDIR}/vimrc.sample

.if !defined(TINY)
post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/ex
	${RM} ${STAGEDIR}${PREFIX}/bin/view
.for F in eview evim gview gvim gvimdiff rgview rgvim rview rvim vimdiff
	${LN} -sf vim ${STAGEDIR}${PREFIX}/bin/$F
.endfor

# OPTIONS
post-patch-CTAGS_BASE-on:
	${FIND} ${WRKSRC}/runtime -name 'menu*.vim' | ${XARGS} ${GREP} -l 'ctags -R' | \
		${XARGS} ${REINPLACE_CMD} -Ee 's!ctags -R ?\.!${FIND} . -type f \\| ${XARGS} ctags!g'

post-patch-CTAGS_EXUBERANT-on:
	${FIND} ${WRKSRC}/runtime -name 'menu*.vim' | ${XARGS} ${GREP} -l 'ctags -R' | \
		${XARGS} ${REINPLACE_CMD} -e 's|ctags -R|exctags -R|g'

post-patch-CTAGS_UNIVERSAL-on:
	${FIND} ${WRKSRC}/runtime -name 'menu*.vim' | ${XARGS} ${GREP} -l 'ctags -R' | \
		${XARGS} ${REINPLACE_CMD} -e 's|ctags -R|uctags -R|g'

post-patch-LUA-on:
	${REINPLACE_CMD} -e 's|set dummy lua;|set dummy ${LUA_CMD};|g' ${WRKSRC}/src/auto/configure
	${REINPLACE_CMD} -e '/$$LUA_LIBS/ s|^|LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}";|' ${WRKSRC}/src/auto/configure
	${REINPLACE_CMD} -e '/LUA_CFLAGS=/s|".*"|"-I${LUA_INCDIR}"|' ${WRKSRC}/src/auto/configure

post-patch-XTERM_SAVE-on:
	${REINPLACE_CMD} -e '/FEAT_XTERM_SAVE/ s|.*|#define FEAT_XTERM_SAVE|' ${WRKSRC}/src/feature.h

post-install-NLS-off:
	${MKDIR} ${STAGEDIR}${DATADIR}/${VIM_VER}/lang
	${MKDIR} ${STAGEDIR}${DATADIR}/${VIM_VER}/keymap
	${INSTALL_DATA} ${WRKSRC}/runtime/keymap/* ${STAGEDIR}${DATADIR}/${VIM_VER}/keymap
.endif	#!defined(TINY)

.include <bsd.port.post.mk>
