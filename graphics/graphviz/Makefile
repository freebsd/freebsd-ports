# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	graphviz
PORTVERSION=	2.40.1
PORTREVISION=	7
CATEGORIES=	graphics tk
MASTER_SITES=	https://graphviz.gitlab.io/pub/graphviz/stable/SOURCES/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Graph Visualization Software from AT&T and Bell Labs

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libexpat.so:textproc/expat2 \
		libgd.so:${GD_PORT}

USES=		cpe pathfix shebangfix gmake bison groff pkgconfig \
		libtool:keepla localbase:ldflags jpeg compiler:c++11-lang
GNU_CONFIGURE=	yes
# sincos is broken on armv6, see ports/220591
CFLAGS_armv6=	-fno-builtin-sincos -fno-builtin-sin -fno-builtin-cos \
		-fno-builtin-sincosf -fno-builtin-sinf -fno-builtin-cosf \
		-fno-builtin-sincosl -fno-builtin-sinl -fno-builtin-cosl
CFLAGS_armv7=	-fno-builtin-sincos -fno-builtin-sin -fno-builtin-cos \
		-fno-builtin-sincosf -fno-builtin-sinf -fno-builtin-cosf \
		-fno-builtin-sincosl -fno-builtin-sinl -fno-builtin-cosl
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

MAKE_ENV=	EXPR_COMPAT=yes

FIX_INCLUDE=	\
		lib/cdt/dthdr.h \
		lib/pathplan/tri.h lib/pathplan/pathplan.h \
		lib/pathplan/pathutil.h lib/pathplan/solvers.h \
		lib/pathplan/vis.h lib/pathplan/vispath.h \
		lib/common/arith.h lib/common/logic.h \
		lib/common/globals.h \
		lib/gvc/gvcint.h

PATCH_TCL_SCRIPTS=	tclpkg/gv/Makefile.in tclpkg/tcldot/demo/doted.tcl \
			tclpkg/tclpathplan/demo/pathplan.tcl
PATCH_TK_SCRIPTS=	${PATCH_TCL_SCRIPTS}

PDOCS_TXT=	doc/Dot.ref doc/latex_suggestions.txt
PDOCS_PDF=	doc/*.pdf */*/*.pdf
PDOCS_HTML=	doc/*.html doc/info/*.gif

USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

OPTIONS_DEFINE=	XPM DIGCOLA IPSEPCOLA ICONV NLS PANGOCAIRO POPPLER \
		ANN GTS GTK2 GDK GDK_PIXBUF GNOMEUI SMYRNA GVEDIT MING DEVIL \
		GHOSTSCRIPT PERL PHP PYTHON RUBY LUA TCL TK GUILE NVTHREADS \
		DOCS EXAMPLES
OPTIONS_DEFAULT=	XPM DIGCOLA IPSEPCOLA ICONV PANGOCAIRO NVTHREADS
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
DIGCOLA_DESC=	neato layout engine with DIGCOLA features
IPSEPCOLA_DESC=	neato layout engine with IPSEPCOLA features
PANGOCAIRO_DESC=pangocairo support
ANN_DESC=	ANN edge bundling support
GTS_DESC=	GNU Triangulated Surface Library support
GTK2_DESC=	gtk2 plugin (requires PANGOCAIRO)
GDK_DESC=	gdk library support (requires GTK2)
GDK_PIXBUF_DESC=gdk pixbuf support (requires GDK)
GNOMEUI_DESC=	libgnomeui support
SMYRNA_DESC=	SMYRNA graph viewer (requires GTK2)
GVEDIT_DESC=	gvedit (requires qt)
MING_DESC=	ming plugin
DEVIL_DESC=	devil plugin
GHOSTSCRIPT_DESC=ghostscript plugin (requires PANGOCAIRO)
PERL_DESC=	Perl bindings (swig)
PHP_DESC=	PHP bindings (swig)
PYTHON_DESC=	Python bindings (swig)
RUBY_DESC=	Ruby bindings (swig)
LUA_DESC=	Lua bindings (swig)
TCL_DESC=	TCL bindings (swig)
GUILE_DESC=	Guile bindings (swig)
TK_DESC=	TK toolkit support
NVTHREADS_DESC=	Link with threads (needed for nvidia)

XPM_USE=	XORG=xaw,xpm,xmu,xt,sm,ice,xext,x11,xau,xdmcp,xp
ICONV_USES=	iconv
NLS_USES=	gettext
PANGOCAIRO_USE=	GNOME=pango,cairo XORG=xrender,x11,xau,xdmcp
GTK2_USE=	XORG=sm,ice,xext,xinerama,xi,xrandr,xcursor,xfixes GNOME=gtk20
GNOMEUI_USE=	GNOME=libgnomeui
SMYRNA_USE=	GNOME=libglade2,pangox-compat GL=glut
GVEDIT_USES=	qt:4
GVEDIT_USE=	qt=qmake_build,moc_build,rcc_build,uic_build \
		qt=linguist_build,corelib,gui
GHOSTSCRIPT_USES=ghostscript
PERL_USES=	perl5
PHP_USES=	php:build
PYTHON_USES=	python:2.7,build
RUBY_USE=	RUBY=yes
LUA_USES=	lua
TCL_USES=	tcl:build
TK_USES=	tk:build
TK_IMPLIES=	TCL
POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
ANN_LIB_DEPENDS=	libann.so:math/ann
GTS_LIB_DEPENDS=	libgts.so:graphics/gts
SMYRNA_LIB_DEPENDS=	libgtkgl-2.0.so:x11-toolkits/gtkglarea2 \
			libgtkglext-x11-1.0.so:x11-toolkits/gtkglext
MING_LIB_DEPENDS=	libming.so:graphics/ming
DEVIL_LIB_DEPENDS=	libIL.so:graphics/devil
GUILE_LIB_DEPENDS=	libguile-2.0.so:lang/guile2 \
			libgc-threaded.so:devel/boehm-gc-threaded

XPM_CONFIGURE_WITH=		x
DIGCOLA_CONFIGURE_WITH=		digcola
IPSEPCOLA_CONFIGURE_WITH=	ipsepcola
IPSEPCOLA_IMPLIES=		DIGCOLA
NLS_CONFIGURE_ENABLE=		nls
PANGOCAIRO_CONFIGURE_WITH=	pangocairo
POPPLER_CONFIGURE_WITH=		poppler
ANN_CONFIGURE_WITH=		ann
ANN_CONFIGURE_ENV=	ANN_CFLAGS=-I${LOCALBASE}/include ANN_LIBS=-lann
GTS_CONFIGURE_WITH=		gts
GTK2_CONFIGURE_WITH=		gtk
GTK2_IMPLIES=			PANGOCAIRO
GDK_CONFIGURE_WITH=		gdk
GDK_PIXBUF_CONFIGURE_WITH=	gdk-pixbuf
GDK_PIXBUF_IMPLIES=		GTK2 GDK
GNOMEUI_CONFIGURE_WITH=		gnomeui
GNOMEUI_IMPLIES=		GTK2
SMYRNA_CONFIGURE_WITH=		smyrna glade gtkgl gtkglext
SMYRNA_IMPLIES=			GTK2 GTS
GVEDIT_CONFIGURE_ON=		--with-gvedit=yes
GVEDIT_CONFIGURE_OFF=		--with-qt=no
MING_CONFIGURE_WITH=		ming
DEVIL_CONFIGURE_WITH=		devil
GHOSTSCRIPT_CONFIGURE_OFF=	--with-ghostscript=no
GHOSTSCRIPT_IMPLIES=		PANGOCAIRO
PERL_CONFIGURE_ENABLE=		perl
PERL_VARS=		SHEBANG_FILES+=tclpkg/gv/demo/modgraph.pl
PHP_CONFIGURE_ENABLE=		php
PHP_CPPFLAGS=		-I${LOCALBASE}/include/php/Zend
PHP_VARS=		SHEBANG_FILES+=tclpkg/gv/demo/modgraph.php
PYTHON_CONFIGURE_ENABLE=	python
PYTHON_LDFLAGS=		"-L${PYTHONBASE}/lib"
PYTHON_VARS=		SHEBANG_FILES+=tclpkg/gv/demo/modgraph.py
RUBY_CONFIGURE_ENABLE=		ruby
RUBY_CONFIGURE_ENV=	RUBY="${RUBY}"
RUBY_VARS=		SHEBANG_FILES+=tclpkg/gv/demo/modgraph.rb
LUA_CONFIGURE_ENABLE=		lua
LUA_CFLAGS=		-I${LUA_INCDIR}
LUA_LDFLAGS=		-L${LUA_LIBDIR} -lm
LUA_CONFIGURE_ENV=	LUA="${LUA_BINDIR}/lua" \
			LUA_INSTALL_DIR=${PREFIX}/lib/lua/${LUA_VER}
LUA_VARS=		SHEBANG_FILES+=tclpkg/gv/demo/modgraph.lua
TCL_CONFIGURE_ENABLE=		tcl
TCL_CPPFLAGS=		-I${TK_INCLUDEDIR}
TCL_CONFIGURE_ON=	--with-tclsh=${TCLSH} --enable-tcl=yes
TCL_CONFIGURE_ENV=	TCLCONFIG="${TCL_LIBDIR}/tclConfig.sh"
TCL_VARS=		SHEBANG_FILES+=tclpkg/gv/demo/modgraph.tcl \
			PLIST_SUB+=TCL_VER="${TCL_VER}"
TK_CPPFLAGS=		-I${TK_INCLUDEDIR}
TK_CONFIGURE_ON=	--with-wish=${WISH}
TK_CONFIGURE_ENV=	TKCONFIG="${TK_LIBDIR}/tkConfig.sh"
GUILE_CONFIGURE_ENABLE=		guile
NVTHREADS_LDFLAGS=	-lpthread

.include <bsd.port.options.mk>

# allow the use localized gd ports in Makefile.local or slave ports.
GD_PORT?=	graphics/gd

CONFIGURE_ARGS+=	--program-transform-name="s/x/x/" \
		--enable-dependency-tracking \
		--enable-r=no \
		--with-freetype2=yes \
		--with-libgd \
		--with-fontconfigincludedir=${LOCALBASE}/include \
		--with-fontconfiglibdir=${LOCALBASE}/lib \
		--without-rsvg \
		--disable-io --disable-ocaml --disable-java \
		--disable-sharp

.if ${PORT_OPTIONS:MMING}
BROKEN=	Ming incomplete, uses removed libgraph
.endif

.if ${PORT_OPTIONS:MTK}
# USES=tk:build is BROKEN: Does not allow to set both tcl and tk depedencies
BUILD_DEPENDS+=	tclsh${TCL_VER}:lang/tcl${_TCLTK_WANTED_VERSION}
.endif

.if ${PORT_OPTIONS:MICONV}
CONFIGURE_ARGS+=	--with-iconvlibdir=${ICONV_PREFIX}/lib
CONFIGURE_ARGS+=	--with-iconvincludedir=${ICONV_PREFIX}/include
.else
CONFIGURE_ARGS+=	--without-libiconv-prefix
.endif

.if ${PORT_OPTIONS:MPERL} || ${PORT_OPTIONS:MPHP} || ${PORT_OPTIONS:MPYTHON} || \
    ${PORT_OPTIONS:MRUBY} || ${PORT_OPTIONS:MLUA} || ${PORT_OPTIONS:MTCL} || \
    ${PORT_OPTIONS:MGUILE}
BUILD_DEPENDS+=		swig3.0:devel/swig30
RUN_DEPENDS+=		swig3.0:devel/swig30
CONFIGURE_ARGS+=	--enable-swig
CONFIGURE_ENV+=		SWIG="${LOCALBASE}/bin/swig3.0"
.else
CONFIGURE_ARGS+=	--disable-swig
CONFIGURE_ENV+=		SWIG="/nonexistent"
.endif

.if ${PORT_OPTIONS:MGVEDIT}
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MPHP}
.if ${PHP_VER} < 70
# force old PHP API
MAKE_ARGS+=	SWIG_PHP_OPT=-php5
.endif
.endif

post-patch:
	${FIND} ${WRKSRC} -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} \
		-e "s|\([^:]*:.*\) install-pdfDATA\(.*\)|\1\2|g" \
		-e "s|\([^:]*:.*\) install-htmlDATA\(.*\)|\1\2|g" \
		-e "s|\([^:]*:.*\) install-txtDATA\(.*\)|\1\2|g" \
		-e "s|\([^:]*:.*\) install-demoDATA\(.*\)|\1\2|g" \
		-e "s|\([^:]*:.*\) install-demoSCRIPTS\(.*\)|\1\2|g" \
		-e "s|\([^:]*:.*\) install-pathplanexampleDATA\(.*\)|\1\2|g" \
		-e 's|txtdir = $$(pkgdatadir)/doc|txtdir = ${DOCSDIR}|' \
		-e 's|demodir = $$(pkgdatadir)/demo|demodir = ${EXAMPLESDIR}|';
	${REINPLACE_CMD} \
		-e 's|^\.SUFFIXES: \(.*\)\.1\(.*\)|.SUFFIXES: \1 \2|' \
		${WRKSRC}/cmd/tools/Makefile.in \
		${WRKSRC}/cmd/gvpr/Makefile.in
	${FIND} ${WRKSRC}/lib -name 'Makefile.in' | \
		${XARGS} ${REINPLACE_CMD} \
		-e 's|pkglibdir = $$(libdir)/@PACKAGE@|pkglibdir = $$(libdir)|g' \
		-e 's|libdir = @libdir@|libdir = @libdir@/@PACKAGE@|g';
	${FIND} ${WRKSRC}/lib -name '*.pc.in' | \
		${XARGS} ${REINPLACE_CMD} \
		-e 's|libdir=@libdir@|libdir=@libdir@/@PACKAGE@|';
	${REINPLACE_CMD} -e "s|/usr/include/php|${LOCALBASE}/include/php|g" \
		-e "s|vendorarchdir|sitearchdir|g" \
		-e "s|-lruby|-lruby${RUBY_SUFFIX}|g" \
		-e "s|ruby-1[.]9|ruby-${RUBY_VER}|g" \
		-e 's|PHP_INSTALL_DIR=.*|PHP_INSTALL_DIR="${PREFIX}/lib/php/${PHP_EXT_DIR}"|' \
		-e 's|PHP_INSTALL_DATADIR=.*|PHP_INSTALL_DATADIR="${PREFIX}/share/php"|' \
		-e '/if test/ s| == | = |g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|#include "gui.h"|#include "gui/gui.h"|' \
		${WRKSRC}/cmd/smyrna/tvnodes.h
	${REINPLACE_CMD} -e 's|GTS_LIBS)|GTS_LIBS) $$(MATH_LIBS)|' \
		${WRKSRC}/cmd/smyrna/Makefile.in
	${CP} ${WRKSRC}/lib/cgraph/cgraph.h ${WRKSRC}/plugin/ming/
	${REINPLACE_CMD} -e 's|SF_FLAGS|SFIO_FLAGS|g' \
		${WRKSRC}/lib/sfio/*.[ch]

post-patch-DOCS-off:
	${REINPLACE_CMD} -e 's| install-txtDATA$$||' \
		${WRKSRC}/Makefile.in

pre-install-PHP-on:
	${MKDIR} "${STAGEDIR}/${PREFIX}/share/php"

post-install: install-ldconfig-file
	cd ${WRKSRC}/lib/expr && \
		${MAKE_ENV} ${MAKE} ${MAKE_ARGS} ${INSTALL_TARGET}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${FIX_INCLUDE} ${STAGEDIR}${PREFIX}/include/graphviz/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${MKDIR} ${STAGEDIR}${DOCSDIR}/pdf
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${PDOCS_TXT} ${STAGEDIR}${DOCSDIR}/ && \
		${INSTALL_DATA} ${PDOCS_PDF} ${STAGEDIR}${DOCSDIR}/pdf/ && \
		${INSTALL_DATA} ${PDOCS_HTML} ${STAGEDIR}${DOCSDIR}/html/

post-install-EXAMPLES-on:
	@${ECHO_MSG} "Installing demo data..."
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} \
		${WRKSRC}/tclpkg/gdtclft/demo/entities.tcl \
		${WRKSRC}/tclpkg/tcldot/demo/doted.tcl \
		${WRKSRC}/tclpkg/tcldot/demo/gcat.tcl \
		${WRKSRC}/tclpkg/tclpathplan/demo/pathplan.tcl \
		${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} \
		${WRKSRC}/tclpkg/gdtclft/demo/entities.tcl.README \
		${WRKSRC}/tclpkg/tcldot/demo/doted.tcl.README \
		${WRKSRC}/tclpkg/tcldot/demo/gcat.tcl.README \
		${WRKSRC}/tclpkg/tclpathplan/demo/pathplan.tcl.README \
		${STAGEDIR}${EXAMPLESDIR}/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/pathplan_data
	${INSTALL_DATA} \
		${WRKSRC}/tclpkg/tclpathplan/demo/pathplan_data/*.dat \
		${STAGEDIR}${EXAMPLESDIR}/pathplan_data/

.include <bsd.port.post.mk>
