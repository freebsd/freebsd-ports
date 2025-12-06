PORTNAME=	graphviz
PORTVERSION=	14.0.5
PORTREVISION=	1
CATEGORIES=	graphics tk
MASTER_SITES=	https://gitlab.com/api/v4/projects/4207231/packages/generic/graphviz-releases/${PORTVERSION}/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Graph Visualization Software from AT&T and Bell Labs
WWW=		https://www.graphviz.org/

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	tclsh${TCL_VER}:lang/tcl${_TCLTK_WANTED_VERSION}
LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libpng.so:graphics/png \
		libwebp.so:graphics/webp \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libexpat.so:textproc/expat2 \
		libharfbuzz.so:print/harfbuzz \
		libgd.so:${GD_PORT}

USES=		compiler:c++11-lang cpe pathfix shebangfix gmake bison \
		pkgconfig libtool:keepla autoreconf localbase:ldflags jpeg \
		tcl:build

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
# sincos is broken on armv6, see ports/220591
CFLAGS_armv6=	-fno-builtin-sincos -fno-builtin-sin -fno-builtin-cos \
		-fno-builtin-sincosf -fno-builtin-sinf -fno-builtin-cosf \
		-fno-builtin-sincosl -fno-builtin-sinl -fno-builtin-cosl
CFLAGS_armv7=	-fno-builtin-sincos -fno-builtin-sin -fno-builtin-cos \
		-fno-builtin-sincosf -fno-builtin-sinf -fno-builtin-cosf \
		-fno-builtin-sincosl -fno-builtin-sinl -fno-builtin-cosl
MAKE_ENV=	EXPR_COMPAT=yes

CONFLICTS_INSTALL=	ghmm

INSTALL_TARGET=	install-strip
PLIST_SUB=	PORTVERSION="${PORTVERSION}"
SHEBANG_FILES=	cmd/dot/dot_sandbox

FIX_INCLUDE=	lib/cdt/dthdr.h lib/pathplan/tri.h \
		lib/pathplan/pathutil.h lib/pathplan/solvers.h \
		lib/pathplan/vis.h lib/pathplan/vispath.h \
		lib/common/globals.h lib/gvc/gvcint.h
FIX_TCL_SCRIPT=	tclpkg/gdtclft/demo/entities.tcl \
		tclpkg/tcldot/demo/gcat.tcl
FIX_TK_SCRIPT=	tclpkg/tcldot/demo/doted.tcl \
		tclpkg/tclpathplan/demo/pathplan.tcl
PLIST_SUB=	SH_VERSION_SHORT="8" SH_VERSION_FULL="8.0.4"

OPTIONS_DEFINE=	XPM DIGCOLA IPSEPCOLA ICONV NLS ANN GTS \
		PANGOCAIRO POPPLER GDK GHOSTSCRIPT DEVIL \
		SMYRNA GVEDIT \
		PERL PHP PYTHON RUBY LUA TCL TK GUILE GO \
		NVTHREADS DOCS EXAMPLES
OPTIONS_DEFAULT=XPM DIGCOLA IPSEPCOLA ICONV PANGOCAIRO NVTHREADS
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
DIGCOLA_DESC=	neato layout engine with DIGCOLA features
IPSEPCOLA_DESC=	neato layout engine with IPSEPCOLA features
ANN_DESC=	ANN edge bundling support
GTS_DESC=	GNU Triangulated Surface Library support
PANGOCAIRO_DESC=pangocairo support
POPPLER_DESC=	PDF and PS file support via poppler (requires PANGOCAIRO)
GDK_DESC=	gdk plugin support (requires PANGOCAIRO)
GHOSTSCRIPT_DESC=ghostscript plugin (requires PANGOCAIRO)
DEVIL_DESC=	devil plugin
SMYRNA_DESC=	SMYRNA graph viewer (GTK2)
GVEDIT_DESC=	GVEDIT graph viewer (QT6)
PERL_DESC=	Perl bindings (swig)
PHP_DESC=	PHP bindings (swig)
PYTHON_DESC=	Python bindings (swig)
RUBY_DESC=	Ruby bindings (swig)
LUA_DESC=	Lua bindings (swig)
TCL_DESC=	TCL bindings (swig)
GUILE_DESC=	Guile bindings (swig)
GO_DESC=	Go bindings (swig)
TK_DESC=	TK toolkit support
NVTHREADS_DESC=	Link with threads (needed for nvidia)

XPM_USES=	xorg
XPM_USE=	XORG=xaw,xpm,xmu,xt,sm,ice,xext,x11,xau,xdmcp
ICONV_USES=	iconv
NLS_USES=	gettext
PANGOCAIRO_USES=gnome xorg
PANGOCAIRO_USE=	GNOME=pango,cairo XORG=xrender,x11,xau,xdmcp
GDK_USES=	gnome xorg
GDK_USE=	GNOME=gtk30
SMYRNA_USES=	gnome gl xorg
SMYRNA_USE=	GNOME=libglade2,pangox-compat,gdkpixbuf,gtk20 \
		GL=glut,glu,gl
GVEDIT_USES=	qt:6
GVEDIT_USE=	QT=tools:build,base
PERL_USES=	perl5
PHP_USES=	php:build gnome ssl
PHP_USE=	GNOME=libxml2
PYTHON_USES=	python:build
RUBY_USES=	ruby
LUA_USES=	lua
TCL_USES=	python:build
TK_USES=	tk:build
GUILE_USES=	guile:3.0
GO_USES=	go:no_targets
DOCS_USES=	groff

ANN_LIB_DEPENDS=	libann.so:math/ann
GTS_LIB_DEPENDS=	libgts.so:graphics/gts
POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
DEVIL_LIB_DEPENDS=	libIL.so:graphics/devil
SMYRNA_LIB_DEPENDS=	libgtkgl-2.0.so:x11-toolkits/gtkglarea2 \
			libgtkglext-x11-1.0.so:x11-toolkits/gtkglext \
			libgts.so:graphics/gts
PHP_LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
			libargon2.so:security/libargon2

XPM_CONFIGURE_WITH=		x
XPM_CONFIGURE_ENV=		ac_cv_header_sys_inotify_h=no
DIGCOLA_CONFIGURE_WITH=		digcola
IPSEPCOLA_CONFIGURE_WITH=	ipsepcola
IPSEPCOLA_IMPLIES=		DIGCOLA
NLS_CONFIGURE_ENABLE=		nls
ANN_CONFIGURE_WITH=		ann
ANN_CONFIGURE_ENV=	ANN_CFLAGS=-I${LOCALBASE}/include ANN_LIBS=-lann
GTS_CONFIGURE_WITH=		gts
PANGOCAIRO_CONFIGURE_WITH=	pangocairo
POPPLER_CONFIGURE_WITH=		poppler
POPPLER_IMPLIES=		PANGOCAIRO
GTK3_CONFIGURE_WITH=		gtk
GDK_CONFIGURE_WITH=		gdk gdk-pixbuf 
GDK_IMPLIES=			PANGOCAIRO
GHOSTSCRIPT_CONFIGURE_OFF=	--with-ghostscript=no
GHOSTSCRIPT_IMPLIES=		PANGOCAIRO
DEVIL_CONFIGURE_WITH=		devil
GVEDIT_CONFIGURE_WITH=		qt
SMYRNA_CONFIGURE_OFF=		--with-glut=no
SMYRNA_CONFIGURE_WITH=		smyrna glade gtkgl gtkglext gtk
SMYRNA_IMPLIES=			GTS
PERL_CONFIGURE_ENABLE=		perl
PERL_VARS=		SHEBANG_FILES+=tclpkg/gv/demo/modgraph.pl
PHP_CONFIGURE_ENABLE=		php
PHP_CPPFLAGS=		-I${LOCALBASE}/include/php/Zend
PHP_VARS=		SHEBANG_FILES+=tclpkg/gv/demo/modgraph.php
PYTHON_CONFIGURE_ENABLE=	python3
PYTHON_LDFLAGS=		"-L${PYTHONBASE}/lib"
PYTHON_VARS=		SHEBANG_FILES+=tclpkg/gv/demo/modgraph.py
PYTHON_CONFIGURE_ENV=	PYTHON_INCLUDEDIR="${PYTHON_INCLUDEDIR}"
RUBY_CONFIGURE_ENABLE=		ruby
RUBY_CONFIGURE_ENV=	RUBY="${RUBY}" RUBY_VER="${RUBY_VER}" \
			RUBY_CFLAGS="${RUBY_CFLAGS}" \
			RUBY_LDFLAGS="${RUBY_LDFLAGS}" \
			RUBY_INSTALL_DIR="${RUBY_SITEARCHLIBDIR}"
RUBY_VARS=		SHEBANG_FILES+=tclpkg/gv/demo/modgraph.rb
LUA_CONFIGURE_ENABLE=		lua
LUA_CFLAGS=		-I${LUA_INCDIR}
LUA_LDFLAGS=		-L${LUA_LIBDIR} -lm
LUA_CONFIGURE_ENV=	LUA="${LUA_BINDIR}/lua" \
			LUA_INSTALL_DIR=${PREFIX}/lib/lua/${LUA_VER}
LUA_VARS=		SHEBANG_FILES+=tclpkg/gv/demo/modgraph.lua
TCL_CONFIGURE_ENABLE=		tcl
TCL_CPPFLAGS=		-I${TCL_INCLUDEDIR}
TCL_CONFIGURE_ENV=	TCLCONFIG="${TCL_LIBDIR}/tclConfig.sh"
TCL_VARS=		SHEBANG_FILES+=tclpkg/gv/demo/modgraph.tcl \
			SHEBANG_FILES+=tclpkg/gv/demo/modgraph.py \
			PLIST_SUB+=TCL_VER="${TCL_VER}"
TK_CPPFLAGS=		-I${TK_INCLUDEDIR}
TK_CONFIGURE_ON=	--with-wish=${WISH}
TK_CONFIGURE_ENV=	TKCONFIG="${TK_LIBDIR}/tkConfig.sh"
TK_IMPLIES=	TCL
GUILE_CONFIGURE_ENABLE=		guile
GO_CONFIGURE_ENABLE=		go
NVTHREADS_LDFLAGS=	-lpthread

.include <bsd.port.options.mk>

# allow the use localized gd ports in Makefile.local or slave ports.
GD_PORT?=	graphics/gd

CONFIGURE_ARGS+=	--program-transform-name="s/x/x/" \
		--enable-dependency-tracking \
		--enable-r=no \
		--with-demos="${EXAMPLESDIR}" \
		--with-freetype2=yes \
		--with-libgd \
		--with-webp \
		--with-fontconfigincludedir=${LOCALBASE}/include \
		--with-fontconfiglibdir=${LOCALBASE}/lib \
		--with-tclsh=${TCLSH} \
		--without-rsvg \
		--disable-io --disable-ocaml --disable-java \
		--disable-python2 \
		--disable-sharp

.if ${PORT_OPTIONS:MPYTHON} || ${PORT_OPTIONS:MTCL}
BINARY_ALIAS+=	python3=${PYTHON_CMD}
.else
USES+=	python:env
.endif

.if ${PORT_OPTIONS:MRUBY}
RUBY_CFLAGS+=	-I "${LOCALBASE}/include/ruby-${RUBY_VER}/" \
		-I "${LOCALBASE}/include/ruby-${RUBY_VER}/${RUBY_ARCH}"
.if exists(${LOCALBASE}/bin/ruby${RUBY_SHLIBVER})
RUBY_LIBS!=	${LOCALBASE}/bin/ruby${RUBY_SHLIBVER} \
		-r rbconfig -e "print RbConfig::CONFIG[ 'LIBS' ]"
RUBY_LDFLAGS+=	${RUBY_LIBS}
.endif
.endif

.if ${PORT_OPTIONS:MICONV}
CONFIGURE_ARGS+=	--with-iconvlibdir=${ICONV_PREFIX}/lib
CONFIGURE_ARGS+=	--with-iconvincludedir=${ICONV_PREFIX}/include
.else
CONFIGURE_ARGS+=	--without-libiconv-prefix
.endif

.if ${PORT_OPTIONS:MPERL} || ${PORT_OPTIONS:MPHP} || ${PORT_OPTIONS:MPYTHON} || \
    ${PORT_OPTIONS:MRUBY} || ${PORT_OPTIONS:MLUA} || ${PORT_OPTIONS:MTCL} || \
    ${PORT_OPTIONS:MGUILE} || ${PORT_OPTIONS:MGO}
BUILD_DEPENDS+=		swig:devel/swig
RUN_DEPENDS+=		swig:devel/swig
CONFIGURE_ARGS+=	--enable-swig
CONFIGURE_ENV+=		SWIG="${LOCALBASE}/bin/swig"
.else
CONFIGURE_ARGS+=	--disable-swig
CONFIGURE_ENV+=		SWIG="/nonexistent"
.endif

.if ${PORT_OPTIONS:MGHOSTSCRIPT}
USES_GHOSTSCRIPT_ARGS+=	lib
.endif

.if ${PORT_OPTIONS:MDOCS}
USES_GHOSTSCRIPT_ARGS+=	build
.endif

.if defined(USES_GHOSTSCRIPT_ARGS)
USES+=	ghostscript:${USES_GHOSTSCRIPT_ARGS:ts,}
.endif

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} \
		-e 's|PHP_INSTALL_DATADIR=.*|PHP_INSTALL_DATADIR="${PREFIX}/share/php"|' \
		-e 's|LUA_INSTALL_DIR=.*|LUA_INSTALL_DIR="${LUA_MODLIBDIR}"|' \
		-e 's| vendorarchdir| sitearchdir|' \
		${WRKSRC}/configure.ac
	${REINPLACE_CMD} -e 's|#include "gui.h"|#include "gui/gui.h"|' \
		${WRKSRC}/cmd/smyrna/tvnodes.h
	cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e 's|exec tclsh |exec tclsh${TCL_VER} |' ${FIX_TCL_SCRIPT}
	cd ${WRKSRC} && ${REINPLACE_CMD} \
		-e 's|exec wish |exec wish${TCL_VER} |' ${FIX_TK_SCRIPT}

pre-configure-DOCS-off:
	${REINPLACE_CMD} -e 's| doc | |' ${WRKSRC}/Makefile.am
	${FIND} ${WRKSRC} -name Makefile.am | \
		${XARGS} ${REINPLACE_CMD} \
		-e 's|^pdf_DATA|#pdf_DATA|';

pre-install-PHP-on:
	${MKDIR} "${STAGEDIR}/${PREFIX}/share/php"

post-install: install-ldconfig-file
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${FIX_INCLUDE} ${STAGEDIR}${PREFIX}/include/graphviz/

.include <bsd.port.post.mk>
