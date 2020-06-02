# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	graphviz
PORTVERSION=	2.44.0
PORTREVISION=	4
CATEGORIES=	graphics tk
MASTER_SITES=	https://www2.graphviz.org/Packages/stable/portable_source/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Graph Visualization Software from AT&T and Bell Labs

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	tclsh${TCL_VER}:lang/tcl${_TCLTK_WANTED_VERSION}
LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libpng.so:graphics/png \
		libwebp.so:graphics/webp \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig \
		libexpat.so:textproc/expat2 \
		libgd.so:${GD_PORT}

USES=		cpe pathfix shebangfix gmake bison pkgconfig \
		libtool:keepla autoreconf localbase:ldflags jpeg \
		tcl:build

GNU_CONFIGURE=	yes
# sincos is broken on armv6, see ports/220591
CFLAGS_armv6=	-fno-builtin-sincos -fno-builtin-sin -fno-builtin-cos \
		-fno-builtin-sincosf -fno-builtin-sinf -fno-builtin-cosf \
		-fno-builtin-sincosl -fno-builtin-sinl -fno-builtin-cosl
CFLAGS_armv7=	-fno-builtin-sincos -fno-builtin-sin -fno-builtin-cos \
		-fno-builtin-sincosf -fno-builtin-sinf -fno-builtin-cosf \
		-fno-builtin-sincosl -fno-builtin-sinl -fno-builtin-cosl
MAKE_ENV=	EXPR_COMPAT=yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

FIX_INCLUDE=	lib/cdt/dthdr.h lib/pathplan/tri.h \
		lib/pathplan/pathutil.h lib/pathplan/solvers.h \
		lib/pathplan/vis.h lib/pathplan/vispath.h \
		lib/common/logic.h lib/common/globals.h \
		lib/gvc/gvcint.h
FIX_TCL_SCRIPT=	tclpkg/gdtclft/demo/entities.tcl \
		tclpkg/tcldot/demo/gcat.tcl
FIX_TK_SCRIPT=	tclpkg/tcldot/demo/doted.tcl \
		tclpkg/tclpathplan/demo/pathplan.tcl

OPTIONS_DEFINE=	XPM DIGCOLA IPSEPCOLA ICONV NLS PANGOCAIRO POPPLER \
		ANN GTS GTK2 GDK GDK_PIXBUF GNOMEUI SMYRNA DEVIL \
		GHOSTSCRIPT PERL PHP PYTHON RUBY LUA TCL TK GUILE GO \
		NVTHREADS DOCS EXAMPLES
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
DEVIL_DESC=	devil plugin
GHOSTSCRIPT_DESC=ghostscript plugin (requires PANGOCAIRO)
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
GTK2_USES=	gnome xorg
GTK2_USE=	XORG=sm,ice,xext,xinerama,xi,xrandr,xcursor,xfixes GNOME=gtk20
GNOMEUI_USE=	GNOME=libgnomeui
SMYRNA_USES=	gnome gl
SMYRNA_USE=	GNOME=libglade2,pangox-compat,gdkpixbuf2 GL=glut,glu,gl
GHOSTSCRIPT_USES=ghostscript
PERL_USES=	perl5
PHP_USE=	GNOME=libxml2
PHP_USES=	php:build
PYTHON_USES=	python:build
RUBY_USE=	RUBY=yes
LUA_USES=	lua
TK_USES=	tk:build
GO_USES=	go:no_targets
DOCS_USES=	ghostscript:build groff

POPPLER_LIB_DEPENDS=	libpoppler-glib.so:graphics/poppler-glib
ANN_LIB_DEPENDS=	libann.so:math/ann
GTS_LIB_DEPENDS=	libgts.so:graphics/gts
SMYRNA_LIB_DEPENDS=	libgtkgl-2.0.so:x11-toolkits/gtkglarea2 \
			libgtkglext-x11-1.0.so:x11-toolkits/gtkglext
DEVIL_LIB_DEPENDS=	libIL.so:graphics/devil
GUILE_LIB_DEPENDS=	libguile-2.2.so:lang/guile2 \
			libgc-threaded.so:devel/boehm-gc-threaded
PHP_LIB_DEPENDS=	libpcre.so:devel/pcre \
			libargon2.so:security/libargon2
GHOSTSCRIPT_LIB_DEPENDS=	libgs.so:print/${_GS_PORT}

XPM_CONFIGURE_WITH=		x
XPM_CONFIGURE_ENV=		ac_cv_header_sys_inotify_h=no
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
SMYRNA_CONFIGURE_OFF=		--with-glut=no
SMYRNA_CONFIGURE_WITH=		smyrna glade gtkgl gtkglext
SMYRNA_IMPLIES=			GTK2 GTS
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
PYTHON_CONFIGURE_ENV=	PYTHON_INCLUDEDIR="${PYTHON_INCLUDEDIR}"
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
TCL_CPPFLAGS=		-I${TCL_INCLUDEDIR}
TCL_CONFIGURE_ENV=	TCLCONFIG="${TCL_LIBDIR}/tclConfig.sh"
TCL_VARS=		SHEBANG_FILES+=tclpkg/gv/demo/modgraph.tcl \
			PLIST_SUB+=TCL_VER="${TCL_VER}"
TK_CPPFLAGS=		-I${TK_INCLUDEDIR}
TK_CONFIGURE_ON=	--with-wish=${WISH}
TK_CONFIGURE_ENV=	TKCONFIG="${TK_LIBDIR}/tkConfig.sh"
TK_IMPLIES=	TCL
GUILE_CONFIGURE_ENABLE=		guile
GO_CONFIGURE_ENABLE=		go
NVTHREADS_LDFLAGS=	-lpthread

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lang
.endif

# allow the use localized gd ports in Makefile.local or slave ports.
GD_PORT?=	graphics/gd

CONFIGURE_ARGS+=	--program-transform-name="s/x/x/" \
		--enable-dependency-tracking \
		--enable-r=no \
		--with-freetype2=yes \
		--with-libgd \
		--with-webp \
		--with-fontconfigincludedir=${LOCALBASE}/include \
		--with-fontconfiglibdir=${LOCALBASE}/lib \
		--with-tclsh=${TCLSH} \
		--without-rsvg \
		--with-qt=no \
		--disable-io --disable-ocaml --disable-java \
		--disable-python2 --disable-python3 \
		--disable-sharp

.if ${PORT_OPTIONS:MICONV}
CONFIGURE_ARGS+=	--with-iconvlibdir=${ICONV_PREFIX}/lib
CONFIGURE_ARGS+=	--with-iconvincludedir=${ICONV_PREFIX}/include
.else
CONFIGURE_ARGS+=	--without-libiconv-prefix
.endif

.if ${PORT_OPTIONS:MPERL} || ${PORT_OPTIONS:MPHP} || ${PORT_OPTIONS:MPYTHON} || \
    ${PORT_OPTIONS:MRUBY} || ${PORT_OPTIONS:MLUA} || ${PORT_OPTIONS:MTCL} || \
    ${PORT_OPTIONS:MGUILE} || ${PORT_OPTIONS:MGO}
BUILD_DEPENDS+=		swig3.0:devel/swig30
RUN_DEPENDS+=		swig3.0:devel/swig30
CONFIGURE_ARGS+=	--enable-swig
CONFIGURE_ENV+=		SWIG="${LOCALBASE}/bin/swig3.0"
.else
CONFIGURE_ARGS+=	--disable-swig
CONFIGURE_ENV+=		SWIG="/nonexistent"
.endif

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} \
		-e 's|PHP_INSTALL_DATADIR=.*|PHP_INSTALL_DATADIR="${PREFIX}/share/php"|' \
		-e 's|LUA_INSTALL_DIR=.*|LUA_INSTALL_DIR="${LUA_MODLIBDIR}"|' \
		${WRKSRC}/configure.ac
	${REINPLACE_CMD} -e 's|#include "gui.h"|#include "gui/gui.h"|' \
		${WRKSRC}/cmd/smyrna/tvnodes.h
	${REINPLACE_CMD} -e 's|SF_FLAGS|SFIO_FLAGS|g' \
		${WRKSRC}/lib/sfio/*.[ch]
	${FIND} ${WRKSRC} -name Makefile.am | \
		${XARGS} ${REINPLACE_CMD} \
		-e 's| $$(pkgdatadir)/doc/pdf| ${DOCSDIR}/pdf|' \
		-e 's| $$(pkgdatadir)/doc/html/schema| ${DOCSDIR}/html/schema|' \
		-e 's| $$(pkgdatadir)/doc/html/info| ${DOCSDIR}/html/info|' \
		-e 's| $$(pkgdatadir)/doc/html| ${DOCSDIR}/html|' \
		-e 's| $$(pkgdatadir)/doc| ${DOCSDIR}|' \
		-e 's| $$(pkgdatadir)/demo| ${EXAMPLESDIR}|' \
		-e 's| $$(datadir)/@PACKAGE@/demo| ${EXAMPLESDIR}|';
	${CP} ${FILESDIR}/version.m4 ${WRKSRC}/version.m4
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
