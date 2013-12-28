# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	graphviz
PORTVERSION=	2.34.0
PORTREVISION=	1
CATEGORIES=	graphics tk
MASTER_SITES=	http://www.graphviz.org/pub/graphviz/ARCHIVE/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Graph Visualization Software from AT&T and Bell Labs

LIB_DEPENDS+=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libgd.so:${PORTSDIR}/${GD_PORT}

USES=		bison gmake pkgconfig
USE_AUTOTOOLS=	libltdl libtool
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

MAKE_ENV=	EXPR_COMPAT=yes MISSING=${TRUE}

MLINKS=		dot.1 circo.1 \
		dot.1 fdp.1 \
		dot.1 neato.1 \
		dot.1 sfdp.1 \
		dot.1 twopi.1 \
		gml2gv.1 gv2gml.1 \
		gv2gxl.1 gxl2gv.1

FIX_INCLUDE=	ast_common.h \
		lib/cdt/dthdr.h \
		lib/graph/libgraph.h lib/graph/triefa.h \
		lib/graph/parser.h lib/graph/agxbuf.h \
		lib/pathplan/tri.h lib/pathplan/pathplan.h \
		lib/pathplan/pathutil.h lib/pathplan/solvers.h \
		lib/pathplan/vis.h lib/pathplan/vispath.h \
		lib/common/arith.h lib/common/logic.h \
		lib/common/globals.h \
		lib/gvc/gvcint.h

PATCH_TCL_SCRIPTS=	tclpkg/gv/Makefile.in tclpkg/tcldot/demo/doted.tcl \
			tclpkg/tclpathplan/demo/pathplan.tcl \
			tclpkg/tkspline/demo/spline.tcl
PATCH_TK_SCRIPTS=	${PATCH_TCL_SCRIPTS}

PDOCS_TXT=	doc/Dot.ref doc/latex_suggestions.txt
PDOCS_PDF=	doc/*.pdf */*/*.pdf
PDOCS_HTML=	doc/*.html doc/info/*.gif

USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

OPTIONS_DEFINE=	XPM DIGCOLA IPSEPCOLA ICONV NLS PANGOCAIRO LIBRSVG2 POPPLER \
		ANN GTS GTK2 GDK_PIXBUF GNOMEUI SMYRNA GVEDIT MING DEVIL \
		GHOSTSCRIPT PERL PHP PYTHON RUBY LUA TCL TK GUILE NVTHREADS
OPTIONS_DEFAULT?=	XPM DIGCOLA IPSEPCOLA ICONV NLS PANGOCAIRO
NO_OPTIONS_SORT=yes
OPTIONS_SUB=	yes
DIGCOLA_DESC=	neato layout engine wiwth DIGCOLA features
IPSEPCOLA_DESC=	neato layout engine wiwth IPSEPCOLA features
PANGOCAIRO_DESC=pangocairo support
ANN_DESC=	ANN edge bundling support
GTS_DESC=	GNU Triangulated Surface Library support
GTK2_DESC=	gtk2 plugin (requires PANGOCAIRO)
GDK_PIXBUF_DESC=gdk pixbuf support
GNOMEUI_DESC=	libgnomeui support
SMYRNA_DESC=	SMYRNA graph viewer (requires GTK2)
GVEDIT_DESC=	gvedit (requires qt)
MING_DESC=	ming plugin
DEVIL_DESC=	devil plugin
GHOSTSCRIPT_DESC=ghostscript plugin
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
PANGOCAIRO_USE=	GNOME=pango XORG=xrender,x11,xau,xdmcp
LIBRSVG2_USE=	GNOME=librsvg2 GL=gl,glu,glut
GTK2_USE=	XORG=sm,ice,xext,xinerama,xi,xrandr,xcursor,xfixes GNOME=gtk20
GNOMEUI_USE=	GNOME=libgnomeui
SMYRNA_USE=	GNOME=libglade2
GVEDIT_USE=	qt4=qmake_build,moc_build,rcc_build,uic_build \
		qt4=linguist_build,corelib,gui
GHOSTSCRIPT_USE=GHOSTSCRIPT=yes
PERL_USES=	perl5
PHP_USE=	PHP=yes PHP_BUILD=yes
PYTHON_USE=	PYTHON_BUILD=yes
RUBY_USE=	RUBY=yes
LUA_USE=	LUA=yes
# broken: Do not set both tcl and tk in USES
#TCL_USES=	tcl:84+,build
#TK_USES= 	tk:84+,build
TCL_USE=	TCL_BUILD=84+
TK_USE=		TK_BUILD=84+

POPPLER_LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib
ANN_LIB_DEPENDS=	libann.so:${PORTSDIR}/math/ann
GTS_LIB_DEPENDS=	libgts.so:${PORTSDIR}/graphics/gts
SMYRNA_LIB_DEPENDS=	libgtkgl-2.0.so:${PORTSDIR}/x11-toolkits/gtkglarea2 \
			libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext
MING_LIB_DEPENDS=	libming.so:${PORTSDIR}/graphics/ming
DEVIL_LIB_DEPENDS=	libIL.so:${PORTSDIR}/graphics/devil
GUILE_LIB_DEPENDS=	libguile.so:${PORTSDIR}/lang/guile

XPM_CONFIGURE_WITH=		x
DIGCOLA_CONFIGURE_WITH=		digcola
IPSEPCOLA_CONFIGURE_WITH=	ipsepcola
NLS_CONFIGURE_ENABLE=		nls
PANGOCAIRO_CONFIGURE_WITH=	pangocairo
LIBRSVG2_CONFIGURE_WITH=	rsvg
POPPLER_CONFIGURE_WITH=		poppler
ANN_CONFIGURE_WITH=		ann
ANN_CONFIGURE_ENV=	ANN_CFLAGS=-I${LOCALBASE}/include ANN_LIBS=-lann
GTS_CONFIGURE_WITH=		gts
GTK2_CONFIGURE_WITH=		gtk
GDK_PIXBUF_CONFIGURE_WITH=	gdk-pixbuf
GNOMEUI_CONFIGURE_WITH=		gnomeui
SMYRNA_CONFIGURE_WITH=		smyrna glade gtkgl gtkglext
GVEDIT_CONFIGURE_ON=		--with-gvedit=yes
GVEDIT_CONFIGURE_OFF=		--with-qt=no
MING_CONFIGURE_WITH=		ming
DEVIL_CONFIGURE_WITH=		devil
GHOSTSCRIPT_CONFIGURE_OFF=	--with-ghostscript=no
PERL_CONFIGURE_ENABLE=		perl
PHP_CONFIGURE_ENABLE=		php
PHP_CPPFLAGS=		-I${LOCALBASE}/include/php/Zend
PYTHON_CONFIGURE_ENABLE=	python
PYTHON_LDFLAGS=		"-L${PYTHON_LIBDIR}"
RUBY_CONFIGURE_ENABLE=		ruby
RUBY_CONFIGURE_ENV=	RUBY="${RUBY}"
LUA_CONFIGURE_ENABLE=		lua
LUA_CFLAGS=		-I${LUA_INCDIR}
LUA_LDFLAGS=		-L${LUA_LIBDIR} -lm
LUA_CONFIGURE_ENV=	LUA="${LUA_BINDIR}/lua" \
			LUA_INSTALL_DIR=${PREFIX}/lib/lua/${LUA_VER}
TCL_CONFIGURE_ENABLE=		tcl
TCL_CPPFLAGS=		-I${TK_INCLUDEDIR}
TCL_CONFIGURE_ON=	--with-tclsh=${TCLSH} --enable-tcl=yes
TCL_CONFIGURE_ENV=	TCLCONFIG="${TCL_LIBDIR}/tclConfig.sh"
TK_CPPFLAGS=		-I${TK_INCLUDEDIR}
TK_CONFIGURE_ON=	--with-wish=${WISH}
TK_CONFIGURE_ENV=	TKCONFIG="${TK_LIBDIR}/tkConfig.sh"
GUILE_CONFIGURE_ENABLE=		guile
NVTHREADS_CFLAGS+=	${PTHREAD_CFLAGS}
NVTHREADS_LDFLAGS+=	${PTHREAD_LIBS}


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
		--disable-io --disable-ocaml --disable-java \
		--disable-sharp

CONFIGURE_ENV+=	MISSING=${TRUE}

.if ${PORT_OPTIONS:MTK}
.if empty(PORT_OPTIONS:MTCL)
IGNORE=	option TCL is required for option TK
.endif
.endif

.if ${PORT_OPTIONS:MTCL}
PLIST_SUB+=	TCL_VER="${TCL_VER}"
.endif

.if ${PORT_OPTIONS:MICONV}
CONFIGURE_ARGS+=	--with-iconvlibdir=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-iconvincludedir=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=	--without-libiconv-prefix
.endif

.if ${PORT_OPTIONS:MLIBRSVG2}
.if empty(PORT_OPTIONS:MPANGOCAIRO)
IGNORE=	option PANGOCAIRO is required for option LIBRVG2
.endif
.endif

.if ${PORT_OPTIONS:MGTK2}
.if empty(PORT_OPTIONS:MPANGOCAIRO)
IGNORE=	option PANGOCAIRO is required for option GTK2
.endif
.else
.if ${PORT_OPTIONS:MGDK_PIXBUF}
IGNORE=	option GTK2 is required for option GDK_PIXBUF
.endif
.if ${PORT_OPTIONS:MGNOMEUI}
IGNORE=	option GTK2 is required for option GNOMEUI
.endif
.endif

.if ${PORT_OPTIONS:MSMYRNA}
.if empty(PORT_OPTIONS:MGTK2)
IGNORE=	option GTK2 is required for option SMYRNA
.endif
.if empty(PORT_OPTIONS:MGTS)
IGNORE=	option GTS is required for option SMYRNA
.endif
.endif

.if ${PORT_OPTIONS:MIPSEPCOLA}
.if empty(PORT_OPTIONS:MDIGCOLA)
IGNORE=		option WITH_DIGCOLA is required for option WITH_IPSEPCOLA
.endif
.endif

.if ${PORT_OPTIONS:MPERL} || ${PORT_OPTIONS:MPHP} || ${PORT_OPTIONS:MPYTHON} || \
    ${PORT_OPTIONS:MRUBY} || ${PORT_OPTIONS:MLUA} || ${PORT_OPTIONS:MTCL} || \
    ${PORT_OPTIONS:MGUILE}
BUILD_DEPENDS+=		swig2.0:${PORTSDIR}/devel/swig20
RUN_DEPENDS+=		swig2.0:${PORTSDIR}/devel/swig20
CONFIGURE_ARGS+=	--enable-swig
CONFIGURE_ENV+=		SWIG="${LOCALBASE}/bin/swig2.0"
.else
CONFIGURE_ARGS+=	--disable-swig
CONFIGURE_ENV+=		SWIG="/nonexistent"
.endif

post-patch:
	${FIND} ${WRKSRC} -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} \
		-e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
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
		-e "s|Config::|RbConfig::|" \
		-e '/if test/ s| == | = |g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|#include "gui.h"|#include "gui/gui.h"|' \
		${WRKSRC}/cmd/smyrna/tvnodes.h
	${CP} ${WRKSRC}/lib/cgraph/cgraph.h ${WRKSRC}/plugin/ming/
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's| install-txtDATA$$||' \
		${WRKSRC}/Makefile.in
.endif

post-install: install-ldconfig-file
	cd ${WRKSRC}/lib/expr && \
		${MAKE_ENV} ${MAKE} ${MAKE_ARGS} ${INSTALL_TARGET}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${FIX_INCLUDE} ${STAGEDIR}${PREFIX}/include/graphviz/
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${MKDIR} ${STAGEDIR}${DOCSDIR}/pdf
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${PDOCS_TXT} ${STAGEDIR}${DOCSDIR}/ && \
		${INSTALL_DATA} ${PDOCS_PDF} ${STAGEDIR}${DOCSDIR}/pdf/ && \
		${INSTALL_DATA} ${PDOCS_HTML} ${STAGEDIR}${DOCSDIR}/html/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${ECHO_MSG} "Installing demo data..."
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} \
		${WRKSRC}/tclpkg/gdtclft/demo/entities.tcl \
		${WRKSRC}/tclpkg/tcldot/demo/doted.tcl \
		${WRKSRC}/tclpkg/tcldot/demo/gcat.tcl \
		${WRKSRC}/tclpkg/tclpathplan/demo/pathplan.tcl \
		${WRKSRC}/tclpkg/tkspline/demo/spline.tcl \
		${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} \
		${WRKSRC}/tclpkg/gdtclft/demo/entities.tcl.README \
		${WRKSRC}/tclpkg/tcldot/demo/doted.tcl.README \
		${WRKSRC}/tclpkg/tcldot/demo/gcat.tcl.README \
		${WRKSRC}/tclpkg/tclpathplan/demo/pathplan.tcl.README \
		${WRKSRC}/tclpkg/tkspline/demo/spline.tcl.README \
		${STAGEDIR}${EXAMPLESDIR}/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/pathplan_data
	${INSTALL_DATA} \
		${WRKSRC}/tclpkg/tclpathplan/demo/pathplan_data/*.dat \
		${STAGEDIR}${EXAMPLESDIR}/pathplan_data/
.endif

.include <bsd.port.mk>
