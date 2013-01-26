# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	graphviz
PORTVERSION=	2.28.0
PORTREVISION=	1
CATEGORIES=	graphics tk
MASTER_SITES=	http://www.graphviz.org/pub/graphviz/ARCHIVE/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Graph Visualization Software from AT&T and Bell Labs

LIB_DEPENDS+=	jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		expat:${PORTSDIR}/textproc/expat2 \
		gd:${PORTSDIR}/graphics/gd

USE_BISON=	build
USE_GMAKE=	yes
USE_AUTOTOOLS=	libltdl libtool
WANT_GNOME=	yes
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

MAKE_ENV=	EXPR_COMPAT=yes MISSING=${TRUE}

MAN1=		acyclic.1 bcomps.1 ccomps.1 cluster.1 diffimg.1 dijkstra.1 \
		dot.1 dotty.1 gc.1 gml2gv.1 gv2gxl.1 gvedit.1 gvmap.1 \
		gvmap.sh.1 gvgen.1 mm2gv.1 gvcolor.1 gvpack.1 gvpr.1 \
		lneato.1 nop.1 osage.1 patchwork.1 prune.1 sccmap.1 smyrna.1 \
		tred.1 unflatten.1 vimdot.1
MAN3=		cdt.3 expr.3 cgraph.3 graph.3 gvc.3 pack.3 pathplan.3 xdot.3
MAN7=		graphviz.7
MLINKS=		dot.1 circo.1 \
		dot.1 fdp.1 \
		dot.1 neato.1 \
		dot.1 sfdp.1 \
		dot.1 twopi.1 \
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
			tclpkg/tclpathplan/demo/pathplan.tcl tclpkg/tkspline/demo/spline.tcl
PATCH_TK_SCRIPTS=	${PATCH_TCL_SCRIPTS}

PDOCS_TXT=	doc/Dot.ref doc/latex_suggestions.txt
PDOCS_PDF=	doc/*.pdf */*/*.pdf
PDOCS_HTML=	doc/*.html doc/info/*.gif

USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

OPTIONS_DEFINE=	XPM DIGCOLA IPSEPCOLA ICONV NLS PANGOCAIRO LIBRSVG2 GTK2 GDK_PIXBUF GNOMEUI SMYRNA GVEDIT MING DEVIL GHOSTSCRIPT PERL PHP PYTHON RUBY LUA TCL GUILE TK
OPTIONS_DEFAULT?=	XPM DIGCOLA IPSEPCOLA ICONV NLS PANGOCAIRO
NO_OPTIONS_SORT=yes
DIGCOLA_DESC=	neato layout engine wiwth DIGCOLA features
IPSEPCOLA_DESC=	neato layout engine wiwth IPSEPCOLA features
PANGOCAIRO_DESC=pangocairo support
SMYRNA_DESC=	SMYRNA graph viewer (requires GTK2)
GVEDIT_DESC=	gvedit (requires qt)
GTK2_DESC=	gtk2 plugin (requires PANGOCAIRO)
GDK_PIXBUF_DESC=	gdk pixbuf support
GNOMEUI_DESC=	libgnomeui support
MING_DESC=	ming plugin
DEVIL_DESC=	devil plugin
GHOSTSCRIPT_DESC=	ghostscript plugin
PERL_DESC=	Perl bindings (swig)
PHP_DESC=	PHP bindings (swig) 
PYTHON_DESC=	Python bindings (swig)
RUBY_DESC=	Ruby bindings (swig)
LUA_DESC=	Lua bindings (swig)
TCL_DESC=	TCL bindings (swig)
GUILE_DESC=	Guile bindings (swig)
TK_DESC=	TK toolkit support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGVEDIT}
USE_QT4=		qmake_build moc_build rcc_build uic_build linguist_build corelib gui
.endif

.include <bsd.port.pre.mk>

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
CPPFLAGS+=		-I${TK_INCLUDEDIR}
USE_TK_BUILD=		84+
CONFIGURE_ARGS+=	--with-wish=${WISH}
CONFIGURE_ENV+=		TKCONFIG="${TK_LIBDIR}/tkConfig.sh"
MAN3+=			tkspline.3tk
PLIST_SUB+=		WITH_TK=""
.else
PLIST_SUB+=		WITH_TK="@comment "
.endif
.if ${PORT_OPTIONS:MTCL} || ${PORT_OPTIONS:MTK}
CPPFLAGS+=		-I${TCL_INCLUDEDIR}
USE_TCL_BUILD=		84+
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
CONFIGURE_ARGS+=	--with-tclsh=${TCLSH}
CONFIGURE_ENV+=		TCLCONFIG="${TCL_LIBDIR}/tclConfig.sh"
MAN3+=			gdtclft.3tcl tcldot.3tcl
PLIST_SUB+=		TCL_VER="${TCL_VER}"
.endif

.if ${PORT_OPTIONS:MICONV}
USE_ICONV=		yes
CONFIGURE_ARGS+=	--with-iconvlibdir=${LOCALBASE}/lib
CONFIGURE_ARGS+=	--with-iconvincludedir=${LOCALBASE}/include
.else
CONFIGURE_ARGS+=	--without-libiconv-prefix
.endif

.if ${PORT_OPTIONS:MXPM} || exists(${LOCALBASE}/lib/libXpm.so)
USE_XORG+=		xaw xpm xmu xt sm ice xext x11 xau xdmcp xp
MAN1+=			lefty.1
PLIST_SUB+=		WITH_XPM=""
.else
PLIST_SUB+=		WITH_XPM="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=		yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if ${PORT_OPTIONS:MPANGOCAIRO}
CONFIGURE_ARGS+=	--with-pangocairo
PLIST_SUB+=		WITH_PANGOCAIRO=""
USE_GNOME=		pango
USE_XORG+=		xrender x11 xau xdmcp
.else
CONFIGURE_ARGS+=	--without-pangocairo
PLIST_SUB+=		WITH_PANGOCAIRO="@comment "
.endif

.if ${PORT_OPTIONS:MLIBRVG2}
CONFIGURE_ARGS+=	--with-rsvg=yes
PLIST_SUB+=		WITH_RSVG=""
USE_GNOME+=		librsvg2
USE_GL+=		gl glu
.if empty(PORT_OPTIONS:MPANGOCAIRO)
IGNORE=			option PANGOCAIRO is required for option LIBRVG2
.endif
.else
CONFIGURE_ARGS+=	--without-rsvg
PLIST_SUB+=		WITH_RSVG="@comment "
.endif

.if ${PORT_OPTIONS:MGTK2}
CONFIGURE_ARGS+=	--with-gtk
PLIST_SUB+=		WITH_GTK=""
USE_GNOME+=		gtk20
USE_XORG+=		sm ice xext xinerama xi xrandr xcursor xfixes
.if empty(PORT_OPTIONS:MPANGOCAIRO)
IGNORE=			option PANGOCAIRO is required for option GTK2
.endif
.else
CONFIGURE_ARGS+=	--without-gtk --without-gdk-pixbuf
PLIST_SUB+=		WITH_GTK="@comment "
.endif

.if ${PORT_OPTIONS:MGDK_PIXBUF}
CONFIGURE_ARGS+=	--with-gdk-pixbuf=yes
PLIST_SUB+=		WITH_PIXBUF=""
.if empty(PORT_OPTIONS:MGTK2)
IGNORE=			option GTK2 is required for option GDK_PIXBUF
.endif
.else
CONFIGURE_ARGS+=	--without-gdk-pixbuf
PLIST_SUB+=		WITH_PIXBUF="@comment "
.endif

.if ${PORT_OPTIONS:MGNOMEUI}
CONFIGURE_ARGS+=	--with-gnomeui
USE_GNOME+=		libgnomeui
.if empty(PORT_OPTIONS:MGTK2)
IGNORE=			option GTK2 is required for option GNOMEUI
.endif
.else
CONFIGURE_ARGS+=	--without-gnomeui
.endif

.if ${PORT_OPTIONS:MSMYRNA}
CONFIGURE_ARGS+=	--with-glade=yes
USE_GNOME+=		gnomelibs libglade2
.if empty(PORT_OPTIONS:MGTK2)
IGNORE=			option GTK2 is required for option SMYRNA
.endif
.else
CONFIGURE_ARGS+=	--without-glade
.endif

.if defined(USE_GNOME)
.include "${PORTSDIR}/Mk/bsd.gnome.mk"
.endif
.if defined(USE_XORG)
.include "${PORTSDIR}/Mk/bsd.xorg.mk"
.endif

.if ${PORT_OPTIONS:MSMYRNA}
CONFIGURE_ARGS+=	 --with-gtkgl=yes
LIB_DEPENDS+=		gtkgl-2:${PORTSDIR}/x11-toolkits/gtkglarea2
.else
CONFIGURE_ARGS+=	--without-gtkgl
.endif

.if ${PORT_OPTIONS:MSMYRNA}
CONFIGURE_ARGS+=	 --with-gtkglext=yes
LIB_DEPENDS+=		gtkglext-x11-1:${PORTSDIR}/x11-toolkits/gtkglext
.else
CONFIGURE_ARGS+=	--without-gtkglext
.endif

.if ${PORT_OPTIONS:MSMYRNA}
CONFIGURE_ARGS+=	 --with-gts=yes
LIB_DEPENDS+=		gts:${PORTSDIR}/graphics/gts
.else
CONFIGURE_ARGS+=	--without-gts
.endif

.if ${PORT_OPTIONS:MDIGCOLA}
CONFIGURE_ARGS+=	--with-digcola
.else
CONFIGURE_ARGS+=	--without-digcola
.endif

.if ${PORT_OPTIONS:MIPSEPCOLA}
CONFIGURE_ARGS+=	--with-ipsepcola
.if empty(PORT_OPTIONS:MDIGCOLA)
IGNORE=			option WITH_DIGCOLA is required for option WITH_IPSEPCOLA
.endif
.else
CONFIGURE_ARGS+=	--without-ipsepcola
.endif

.if ${PORT_OPTIONS:MSMYRNA}
CONFIGURE_ARGS+=	--with-smyrna=yes
PLIST_SUB+=		WITH_SMYRNA=""
.else
PLIST_SUB+=		WITH_SMYRNA="@comment "
CONFIGURE_ARGS+=	--without-smyrna
.endif

.if ${PORT_OPTIONS:MGVEDIT}
CONFIGURE_ARGS+=	--with-gvedit=yes
PLIST_SUB+=		WITH_GVEDIT=""
.else
PLIST_SUB+=		WITH_GVEDIT="@comment "
CONFIGURE_ARGS+=	--with-qt=no
.endif

.if ${PORT_OPTIONS:MMING}
CONFIGURE_ARGS+=	--with-ming
PLIST_SUB+=		WITH_MING=""
LIB_DEPENDS+=		ming:${PORTSDIR}/graphics/ming
.else
CONFIGURE_ARGS+=	--without-ming
PLIST_SUB+=		WITH_MING="@comment "
.endif

.if ${PORT_OPTIONS:MDEVIL}
CONFIGURE_ARGS+=	--with-devil
PLIST_SUB+=		WITH_DEVIL=""
LIB_DEPENDS+=		IL:${PORTSDIR}/graphics/devil
.else
CONFIGURE_ARGS+=	--without-devil
PLIST_SUB+=		WITH_DEVIL="@comment "
.endif

.if ${PORT_OPTIONS:MPERL} || ${PORT_OPTIONS:MPHP} || ${PORT_OPTIONS:MPYTHON} || \
    ${PORT_OPTIONS:MRUBY} || ${PORT_OPTIONS:MLUA} || ${PORT_OPTIONS:MTCL} || \
    ${PORT_OPTIONS:MGUILE}
BUILD_DEPENDS+=		swig1.3:${PORTSDIR}/devel/swig13
RUN_DEPENDS+=		swig1.3:${PORTSDIR}/devel/swig13
CONFIGURE_ARGS+=	--enable-swig
CONFIGURE_ENV+=		SWIG="${LOCALBASE}/bin/swig1.3"
.else
CONFIGURE_ARGS+=	--disable-swig
CONFIGURE_ENV+=		SWIG="/nonexistent"
.endif

.if ${PORT_OPTIONS:MPERL}
CONFIGURE_ARGS+=	--enable-perl
PLIST_SUB+=		WITH_PERL=""
USE_PERL5=	yes
MAN3+=			gv.3perl
.else
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=		WITH_PERL="@comment "
.endif

.if ${PORT_OPTIONS:MPHP}
CONFIGURE_ARGS+=	--enable-php
PLIST_SUB+=		WITH_PHP=""
USE_PHP=	yes
USE_PHP_BUILD=	yes
.include "${PORTSDIR}/Mk/bsd.php.mk"
CPPFLAGS+=		-I${LOCALBASE}/include/php/Zend
MAN3+=			gv.3php
.if ${PHP_VER} == 5
BROKEN=			swig is to old to build for php 5.4
.endif
.else
CONFIGURE_ARGS+=	--disable-php
PLIST_SUB+=		WITH_PHP="@comment "
.endif

.if ${PORT_OPTIONS:MPYTHON}
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=		WITH_PYTHON=""
USE_PYTHON_BUILD=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
LDFLAGS+=		"-L${PYTHON_LIBDIR}"
MAN3+=			gv.3python
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=		WITH_PYTHON="@comment "
.endif

.if ${PORT_OPTIONS:MRUBY}
CONFIGURE_ARGS+=	--enable-ruby
CONFIGURE_ENV+=		RUBY="${RUBY}"
PLIST_SUB+=		WITH_RUBY=""
USE_RUBY=		yes
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
MAN3+=			gv.3ruby
.else
CONFIGURE_ARGS+=	--disable-ruby
PLIST_SUB+=		WITH_RUBY="@comment "
.endif

.if ${PORT_OPTIONS:MLUA}
CONFIGURE_ARGS+=	--enable-lua
PLIST_SUB+=		WITH_LUA=""
USE_LUA=		yes
.include "${PORTSDIR}/Mk/bsd.lua.mk"
CFLAGS+=		-I${LUA_INCDIR}
LDFLAGS+=		-L${LUA_LIBDIR} -lm
CONFIGURE_ENV+=		LUA="${LUA_BINDIR}/lua" \
			LUA_INSTALL_DIR=${PREFIX}/lib/lua/${LUA_VER}
MAN3+=			gv.3lua
.else
CONFIGURE_ARGS+=	--disable-lua
PLIST_SUB+=		WITH_LUA="@comment "
.endif

.if ${PORT_OPTIONS:MTCL}
CONFIGURE_ARGS+=	--enable-tcl
PLIST_SUB+=		WITH_TCL=""
MAN3+=			gv.3tcl
.else
CONFIGURE_ARGS+=	--disable-tcl
PLIST_SUB+=		WITH_TCL="@comment "
.endif

.if ${PORT_OPTIONS:MGUILE}
CONFIGURE_ARGS+=	--enable-guile
PLIST_SUB+=		WITH_GUILE=""
LIB_DEPENDS+=		guile:${PORTSDIR}/lang/guile
MAN3+=			gv.3guile
.else
CONFIGURE_ARGS+=	--disable-guile
PLIST_SUB+=		WITH_GUILE="@comment "
.endif

.if ${PORT_OPTIONS:MGHOSTSCRIPT}
USE_GHOSTSCRIPT=	yes
PLIST_SUB+=		WITH_GHOSTSCRIPT=""
.else
CONFIGURE_ARGS+=	--with-ghostscript=no
PLIST_SUB+=		WITH_GHOSTSCRIPT="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | \
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
	@${REINPLACE_CMD} \
		-e 's|^\.SUFFIXES: \(.*\)\.1\(.*\)|.SUFFIXES: \1 \2|' \
		${WRKSRC}/cmd/tools/Makefile.in \
		${WRKSRC}/cmd/gvpr/Makefile.in
	@${FIND} ${WRKSRC}/lib -name 'Makefile.in' | \
		${XARGS} ${REINPLACE_CMD} \
		-e 's|pkglibdir = $$(libdir)/@PACKAGE@|pkglibdir = $$(libdir)|g' \
		-e 's|libdir = @libdir@|libdir = @libdir@/@PACKAGE@|g';
	@${FIND} ${WRKSRC}/lib -name '*.pc.in' | \
		${XARGS} ${REINPLACE_CMD} \
		-e 's|libdir=@libdir@|libdir=@libdir@/@PACKAGE@|';
	@${REINPLACE_CMD} -e "s|/usr/include/php|${LOCALBASE}/include/php|g" \
		-e "s|vendorarch|installsitearch|g" \
		-e "s|-lruby|-lruby${RUBY_SUFFIX}|g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|#include "gui.h"|#include "gui/gui.h"|' \
		${WRKSRC}/cmd/smyrna/tvnodes.h
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's| install-txtDATA$$||' \
		${WRKSRC}/Makefile.in
.endif

post-install: install-ldconfig-file
	cd ${WRKSRC}/lib/expr && \
		${MAKE} ${INSTALL_TARGET}
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${FIX_INCLUDE} ${PREFIX}/include/graphviz/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
	@${MKDIR} ${DOCSDIR}/pdf
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${PDOCS_TXT} ${DOCSDIR}/ && \
		${INSTALL_DATA} ${PDOCS_PDF} ${DOCSDIR}/pdf/ && \
		${INSTALL_DATA} ${PDOCS_HTML} ${DOCSDIR}/html/
.endif
.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} "Installing demo data..."
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} \
		${WRKSRC}/tclpkg/gdtclft/demo/entities.tcl \
		${WRKSRC}/tclpkg/tcldot/demo/doted.tcl \
		${WRKSRC}/tclpkg/tcldot/demo/gcat.tcl \
		${WRKSRC}/tclpkg/tclpathplan/demo/pathplan.tcl \
		${WRKSRC}/tclpkg/tkspline/demo/spline.tcl \
		${EXAMPLESDIR}/
	${INSTALL_DATA} \
		${WRKSRC}/tclpkg/gdtclft/demo/entities.tcl.README \
		${WRKSRC}/tclpkg/tcldot/demo/doted.tcl.README \
		${WRKSRC}/tclpkg/tcldot/demo/gcat.tcl.README \
		${WRKSRC}/tclpkg/tclpathplan/demo/pathplan.tcl.README \
		${WRKSRC}/tclpkg/tkspline/demo/spline.tcl.README \
		${EXAMPLESDIR}/
	@${MKDIR} ${EXAMPLESDIR}/pathplan_data
	${INSTALL_DATA} \
		${WRKSRC}/tclpkg/tclpathplan/demo/pathplan_data/*.dat \
		${EXAMPLESDIR}/pathplan_data/
.endif

.include <bsd.port.post.mk>
