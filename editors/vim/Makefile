# Created by: David O'Brien <obrien@cs.ucdavis.edu>
# $FreeBSD$

PORTNAME=	vim
PORTVERSION=	8.1.0985
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	adamw@FreeBSD.org
COMMENT?=	Improved version of the vi editor

LICENSE=	VIM
LICENSE_NAME=	VIM License
LICENSE_FILE=	${WRKSRC}/runtime/doc/uganda.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CONFLICTS_INSTALL?=	vim-console vim-tiny

USES=		cpe iconv ncurses pkgconfig shebangfix
USE_GITHUB=	yes

CONFIGURE_ARGS=	--enable-gui=${GUI} \
		--enable-multibyte \
		--with-tlib=ncurses
MAKE_ARGS=	STRIP="${STRIP_CMD}" \
		VIMRCLOC=${ETCDIR} \
		VIMRUNTIMEDIR=${PREFIX}/share/vim/${VIM_VER}

CPE_VERSION=	${PORTVERSION:R}
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
PLIST_SUB=	VIM_VER=${VIM_VER}
PORTDATA?=	${VIM_VER}
PORTSCOUT=	ignore:1
REINPLACE_ARGS=	-i ''
SHEBANG_FILES=	runtime/tools/demoserver.py runtime/tools/efm_perl.pl
VIM_VER=	${PORTNAME}${PORTVERSION:R:S|.||g}

# OPTIONS
# ### Make sure any new options are excluded below in CONSOLE/TINY
OPTIONS_DEFAULT=	CSCOPE DEFAULT_VIMRC CTAGS_EXUBERANT GTK3 PERL PYTHON2 RUBY
OPTIONS_DEFINE=		CSCOPE DEFAULT_VIMRC NLS XTERM_SAVE
OPTIONS_SINGLE=		CTAGS UI
OPTIONS_SINGLE_CTAGS=	CTAGS_BASE CTAGS_EXUBERANT CTAGS_UNIVERSAL
OPTIONS_SINGLE_UI=	ATHENA CONSOLE GNOME GTK2 GTK3 MOTIF X11
OPTIONS_GROUP=		LANGBIND
OPTIONS_GROUP_LANGBIND=	LUA PERL PYTHON2 PYTHON3 RUBY SCHEME TCL
OPTIONS_SUB=		yes

.if defined(CONSOLE)
OPTIONS_DEFAULT=	DEFAULT_VIMRC
OPTIONS_SLAVE=		CONSOLE
# Exclude everything except the two options above
OPTIONS_EXCLUDE:=	${OPTIONS_DEFINE:NDEFAULT_VIMRC} \
			${OPTIONS_SINGLE_UI:NCONSOLE} \
			${OPTIONS_GROUP_LANGBIND} \
			${OPTIONS_SINGLE_CTAGS}
.elif defined(TINY)
OPTIONS_SLAVE=		CONSOLE
OPTIONS_EXCLUDE:=	${OPTIONS_DEFINE} \
			${OPTIONS_SINGLE_UI:NCONSOLE} \
			${OPTIONS_GROUP_LANGBIND} \
			${OPTIONS_SINGLE_CTAGS}
.endif

DEFAULT_VIMRC_DESC=	Install bundled vimrc as default setting
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

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

# UI
ATHENA_PLIST_SUB=	GUI="" DESKTOP="@comment "
ATHENA_USE=		XORG=ice,sm,x11,xaw,xmu,xpm,xt
ATHENA_VARS=		GUI=athena

CONSOLE_CONFIGURE_OFF=	--enable-xim --enable-fontset
CONSOLE_PLIST_SUB=	GUI="@comment " DESKTOP="@comment "
CONSOLE_VARS=		GUI=no

GNOME_PLIST_SUB=	GUI="" DESKTOP=""
GNOME_IMPLIES=		NLS
GNOME_USE=		GNOME=gdkpixbuf2,libgnomeui XORG=ice,sm,xorgproto,x11,xpm,xt
GNOME_USES=		desktop-file-utils gnome
GNOME_VARS=		GUI=gnome2 INSTALLS_ICONS=yes

GTK2_PLIST_SUB=		GUI="" DESKTOP=""
GTK2_USE=		GNOME=gdkpixbuf2,gtk20 XORG=ice,sm,x11,xpm,xt
GTK2_USES=		desktop-file-utils gnome
GTK2_VARS=		GUI=gtk2 INSTALLS_ICONS=yes

GTK3_PLIST_SUB=		GUI="" DESKTOP=""
GTK3_USE=		GNOME=cairo,gdkpixbuf2,gtk30 XORG=ice,sm,x11,xpm,xt
GTK3_USES=		desktop-file-utils gnome
GTK3_VARS=		GUI=gtk3 INSTALLS_ICONS=yes

MOTIF_CONFIGURE_ENV=	MOTIFHOME=${LOCALBASE}
MOTIF_CONFIGURE_WITH=	motif-lib="${MOTIFLIB}"
MOTIF_PLIST_SUB=	GUI="" DESKTOP="@comment "
MOTIF_USE=		XORG=ice,sm,x11,xmu,xt
MOTIF_USES=		motif
MOTIF_VARS=		GUI=motif

X11_CONFIGURE_WITH=	x
X11_PLIST_SUB=		GUI="@comment " DESKTOP="@comment "
X11_USE=		XORG=ice,sm,x11,xt
X11_VARS=		GUI=no

# LANGUAGE BINDINGS
LUA_CONFIGURE_ENABLE=	luainterp
LUA_CONFIGURE_WITH=	lua-prefix=${LOCALBASE}
LUA_USES=		lua

PERL_CONFIGURE_ENABLE=	perlinterp
PERL_USES=		perl5

PYTHON2_CONFIGURE_ENABLE=	pythoninterp
PYTHON2_CONFIGURE_WITH=	python-command=${LOCALBASE}/bin/python${PYTHON2_DEFAULT}
PYTHON2_BUILD_DEPENDS=	python${PYTHON2_DEFAULT}:lang/python${PYTHON2_DEFAULT:S/.//}
PYTHON2_RUN_DEPENDS=	${PYTHON2_BUILD_DEPENDS}

PYTHON3_CONFIGURE_ENABLE=	python3interp
PYTHON3_CONFIGURE_WITH=	python3-command=${PYTHON_CMD}
PYTHON3_USES=		python:3.4+

RUBY_CONFIGURE_ENABLE=	rubyinterp
RUBY_USE=		RUBY=yes

SCHEME_CONFIGURE_ENABLE=mzschemeinterp
SCHEME_BUILD_DEPENDS=	mzscheme:lang/racket
SCHEME_RUN_DEPENDS=	${SCHEME_BUILD_DEPENDS}

TCL_CONFIGURE_ENABLE=	tclinterp
TCL_CONFIGURE_WITH=	tclsh=tclsh${TCL_VER}
TCL_USES=		tcl:85+

post-extract:
	${INSTALL_DATA} ${FILESDIR}/vietnamese_viscii.vim ${WRKSRC}/runtime/keymap

post-patch:
	@${ECHO_CMD} '#define SYS_VIMRC_FILE "'${ETCDIR}'/vimrc"' >> ${WRKSRC}/src/feature.h
	@${ECHO_CMD} '#define SYS_GVIMRC_FILE "'${ETCDIR}'/gvimrc"' >> ${WRKSRC}/src/feature.h
	@${REINPLACE_CMD} -e 's|-liconv|${ICONV_LIB}|g; s|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/src/auto/configure
# Work around qa-check shebang error
	@${REINPLACE_CMD} -e 1d ${WRKSRC}/runtime/tools/demoserver.py

post-configure:
# Needed when devel/libsysinfo is installed:
	@${REINPLACE_CMD} -e '/#define HAVE_SYSINFO 1/ d' ${WRKSRC}/src/auto/config.h

.if !defined(TINY)
post-install:
	@${RM} ${STAGEDIR}${PREFIX}/bin/ex
	@${RM} ${STAGEDIR}${PREFIX}/bin/view
.for F in eview evim gview gvim gvimdiff rgview rgvim rview rvim vimdiff
	${LN} -sf vim ${STAGEDIR}${PREFIX}/bin/$F
.endfor

# OPTIONS
post-patch-CTAGS_BASE-on:
	@${FIND} ${WRKSRC}/runtime/ -name 'menu*.vim' -print0 | ${XARGS} -0 ${REINPLACE_CMD} -Ee 's!ctags -R ?\.!${FIND} . -type f \\| ${XARGS} ctags!g'

post-patch-CTAGS_EXUBERANT-on:
	@${FIND} ${WRKSRC}/runtime/ -name 'menu*.vim' -print0 | ${XARGS} -0 ${REINPLACE_CMD} -e 's|ctags -R|exctags -R|g'

post-patch-CTAGS_UNIVERSAL-on:
	@${FIND} ${WRKSRC}/runtime/ -name 'menu*.vim' -print0 | ${XARGS} -0 ${REINPLACE_CMD} -e 's|ctags -R|uctags -R|g'

post-patch-LUA-on:
	@${REINPLACE_CMD} -e 's|set dummy lua;|set dummy ${LUA_CMD};|g' ${WRKSRC}/src/auto/configure
	@${REINPLACE_CMD} -e '/$$LUA_LIBS/ s|^|LUA_LIBS="-L${LUA_LIBDIR} -llua-${LUA_VER}";|' ${WRKSRC}/src/auto/configure
	@${REINPLACE_CMD} -e '/LUA_CFLAGS=/s|".*"|"-I${LUA_INCDIR}"|' ${WRKSRC}/src/auto/configure

post-patch-XTERM_SAVE-on:
	@${REINPLACE_CMD} -e '/FEAT_XTERM_SAVE/ s|.*|#define FEAT_XTERM_SAVE|' ${WRKSRC}/src/feature.h

post-install-DEFAULT_VIMRC-on:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${SED} -e '/set nocompatible/d' ${FILESDIR}/vimrc > ${STAGEDIR}${ETCDIR}/gvimrc.sample
	${INSTALL_DATA} ${FILESDIR}/vimrc ${STAGEDIR}${ETCDIR}/vimrc.sample

post-install-NLS-off:
	@${MKDIR} ${STAGEDIR}${DATADIR}/${VIM_VER}/lang
	@${MKDIR} ${STAGEDIR}${DATADIR}/${VIM_VER}/keymap
	${INSTALL_DATA} ${WRKSRC}/runtime/keymap/* ${STAGEDIR}${DATADIR}/${VIM_VER}/keymap
.endif	#!defined(TINY)

.include <bsd.port.mk>
