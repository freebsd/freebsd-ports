# New ports collection makefile for:	graphviz
# Date created:		03 Feb 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	graphviz
PORTVERSION=	2.12
PORTREVISION=	1
CATEGORIES=	graphics tk84
MASTER_SITES=	http://www.graphviz.org/pub/graphviz/ARCHIVE/ \
		http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Graph Visualization Software from AT&T and Bell Labs

LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		expat.6:${PORTSDIR}/textproc/expat2 \
		gd.4:${PORTSDIR}/graphics/gd

USE_BISON=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libltdl:15 libtool:15
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib
CPPFLAGS+=	-I${X11BASE}/include -I${LOCALBASE}/include -I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR}

MAKE_ENV=	EXPR_COMPAT=yes MISSING=${TRUE}

MAN1=		acyclic.1 bcomps.1 ccomps.1 dijkstra.1 dot.1 \
		dotty.1 gc.1 gvcolor.1 gvpack.1 gvpr.1 gxl2dot.1 \
		lneato.1 nop.1 prune.1 sccmap.1 tred.1 unflatten.1
MAN3=		agraph.3 cdt.3 expr.3 graph.3 gvc.3 pathplan.3
MLINKS=		dot.1 circo.1 \
		gxl2dot.1 dot2gxl.1 \
		dot.1 fdp.1 \
		dot.1 neato.1 \
		dot.1 twopi.1

PATCH_TCL_SCRIPTS=	tclpkg/gv/Makefile.in tclpkg/tcldot/demo/doted \
			tclpkg/tclpathplan/demo/pathplan tclpkg/tkspline/demo/spline
PATCH_TK_SCRIPTS=	${PATCH_TCL_SCRIPTS}

PDOCS_TXT=	AUTHORS NEWS ChangeLog cpl1.0.txt doc/Dot.ref doc/latex_suggestions.txt
PDOCS_PDF=	doc/*.pdf */*/*.pdf
PDOCS_HTML=	doc/*.html doc/info/*.html doc/info/*.gif

USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

OPTIONS=	TK "Build with TK support" on \
		XPM "Build with XPM support" on \
		ICONV "Build with ICONV support" on \
		NLS "Build with gettext support" on \
		PANGOCAIRO "build with pangocairo support (gtk)" off \
		PERL "Perl bindings (swig)" off \
		PHP "PHP bindings (swig)" off \
		PYTHON "Python bindings (swig)" off \
		RUBY "Ruby bindings (swig)" off \
		LUA "Lua bindings (swig)" off \
		TCL "TCL bindings (swig)" off \
		GUILE "Guile bindings (swig)" off

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--program-transform-name="s/x/x/" \
		--enable-dependency-tracking \
		--with-libgd \
		--with-fontconfigincludedir=${X11BASE}/include \
		--with-fontconfiglibdir=${X11BASE}/lib \
		--disable-io --disable-ocaml --disable-java \
		--disable-sharp

CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		MISSING=${TRUE}

.if !defined(WITHOUT_TK)
USE_TK_BUILD=	84
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
CONFIGURE_ARGS+=	--with-tclsh=${TCLSH} \
		--with-wish=${WISH}
CONFIGURE_ENV+=	TCLCONFIG="${TCL_LIBDIR}/tclConfig.sh" \
		TKCONFIG="${TK_LIBDIR}/tkConfig.sh"
MANN=		gdtclft.n tcldot.n tkspline.n
.else
.if defined(WITH_TCL)
USE_TCL_BUILD=	84
.include "${PORTSDIR}/Mk/bsd.tcl.mk"
CONFIGURE_ARGS+=	--with-tclsh=${TCLSH}
CONFIGURE_ENV+=	TCLCONFIG="${TCL_LIBDIR}/tclConfig.sh"
.endif
.endif

.if !defined(WITHOUT_ICONV)
USE_ICONV=	yes
CONFIGURE_ARGS+=	--with-iconvlibdir=${LOCALBASE}/lib
.endif

.if !defined(WITHOUT_XPM)
USE_XPM=	yes
MAN1+=		lefty.1
PLIST_SUB+=	WITH_XPM=""
.else
PLIST_SUB+=	WITH_XPM="@comment "
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.if defined(WITH_PANGOCAIRO)
CONFIGURE_ARGS+=	--with-gtk --with-pangocairo
PLIST_SUB+=		WITH_PANGOCAIRO=""
USE_GNOME=	gtk20 pango
.include "${PORTSDIR}/Mk/bsd.gnome.mk"
.else
CONFIGURE_ARGS+=	--with-pangocairo=no
PLIST_SUB+=		WITH_PANGOCAIRO="@comment "
.endif

.if defined(WITH_PERL) || defined(WITH_PHP) || defined(WITH_PYTHON) || \
    defined(WITH_RUBY) || defined(WITH_LUA) || defined(WITH_TCL) || defined(WITH_GUILE)
BUILD_DEPENDS+=		swig1.3:${PORTSDIR}/devel/swig13
RUN_DEPENDS+=		swig1.3:${PORTSDIR}/devel/swig13
CONFIGURE_ARGS+=	--enable-swig
CONFIGURE_ENV+=		SWIG="${LOCALBASE}/bin/swig1.3"
.else
CONFIGURE_ARGS+=	--disable-swig
CONFIGURE_ENV+=		SWIG="/nonexistent"
.endif

. if !defined(WITH_PERL)
CONFIGURE_ARGS+=	--disable-perl
PLIST_SUB+=		WITH_PERL="@comment "
. else
CONFIGURE_ARGS+=	--enable-perl
PLIST_SUB+=		WITH_PERL=""
USE_PERL5=	yes
. endif

. if !defined(WITH_PHP)
CONFIGURE_ARGS+=	--disable-php
PLIST_SUB+=		WITH_PHP="@comment "
. else
CONFIGURE_ARGS+=	--enable-php
PLIST_SUB+=		WITH_PHP=""
USE_PHP=	yes
USE_PHP_BUILD=	yes
CPPFLAGS+=		-I${LOCALBASE}/include/php/Zend
. endif

. if !defined(WITH_PYTHON)
CONFIGURE_ARGS+=	--disable-python
PLIST_SUB+=		WITH_PYTHON="@comment "
. else
CONFIGURE_ARGS+=	--enable-python
PLIST_SUB+=		WITH_PYTHON=""
USE_PYTHON_BUILD=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
LDFLAGS+=		"-L${PYTHON_LIBDIR}"
. endif

. if !defined(WITH_RUBY)
CONFIGURE_ARGS+=	--disable-ruby
PLIST_SUB+=		WITH_RUBY="@comment "
. else
CONFIGURE_ARGS+=	--enable-ruby
PLIST_SUB+=		WITH_RUBY=""
USE_RUBY=	yes
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
. endif

. if !defined(WITH_LUA)
CONFIGURE_ARGS+=	--disable-lua
PLIST_SUB+=		WITH_LUA="@comment "
. else
CONFIGURE_ARGS+=	--enable-lua
PLIST_SUB+=		WITH_LUA=""
USE_LUA=		yes
.include "${PORTSDIR}/Mk/bsd.lua.mk"
CPPFLAGS+=		-I${LUA_INCDIR}
LDFLAGS+=		-L${LUA_LIBDIR}
CONFIGURE_ENV+=		LUA="${LUA_BINDIR}/lua"
. endif

. if !defined(WITH_TCL)
CONFIGURE_ARGS+=	--disable-tcl
PLIST_SUB+=		WITH_TCL="@comment "
. else
CONFIGURE_ARGS+=	--enable-tcl
PLIST_SUB+=		WITH_TCL=""
. endif

. if !defined(WITH_GUILE)
CONFIGURE_ARGS+=	--disable-guile
PLIST_SUB+=		WITH_GUILE="@comment "
. else
CONFIGURE_ARGS+=	--enable-guile
PLIST_SUB+=		WITH_GUILE=""
LIB_DEPENDS+=		guile.15:${PORTSDIR}/lang/guile
. endif

pre-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | \
		${XARGS} ${REINPLACE_CMD} \
		-e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		-e "s|\([^:]*:.*\) install-pdfDATA\(.*\)|\1\2|g" \
		-e "s|\([^:]*:.*\) install-htmlDATA\(.*\)|\1\2|g" \
		-e "s|\([^:]*:.*\) install-txtDATA\(.*\)|\1\2|g" \
		-e "s|\([^:]*:.*\) install-demoDATA\(.*\)|\1\2|g" \
		-e "s|\([^:]*:.*\) install-demoSCRIPTS\(.*\)|\1\2|g" \
		-e "s|\([^:]*:.*\) install-pathplanexampleDATA\(.*\)|\1\2|g" \
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
		-e "s|-lruby|-lruby${RUBY_SUFFIX}|g" ${WRKSRC}/configure

.if !defined(WITHOUT_TK)
post-install-script:
	${INSTALL_MAN} \
		${WRKSRC}/tclpkg/gdtclft/gdtclft.n \
		${WRKSRC}/tclpkg/tcldot/tcldot.n \
		${WRKSRC}/tclpkg/tkspline/tkspline.n \
		${MANNPREFIX}/man/mann/
.endif

post-install: install-ldconfig-file
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	@${MKDIR} ${DOCSDIR}/pdf
	cd ${WRKSRC} && \
		${INSTALL_DATA} ${PDOCS_TXT} ${DOCSDIR}/ && \
		${INSTALL_DATA} ${PDOCS_PDF} ${DOCSDIR}/pdf/ && \
		${INSTALL_DATA} ${PDOCS_HTML} ${DOCSDIR}/html/
.	for i in neato.pdf twopi.pdf fdp.pdf circo.pdf
		cd ${DOCSDIR}/pdf && ${LN} -fs dot.pdf ${i}
.	endfor
	cd ${DOCSDIR}/pdf && ${LN} -fs gxl2dot.pdf dot2gxl.pdf
.endif
	@${ECHO_MSG} "Installing demo data..."
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} \
		${WRKSRC}/tclpkg/gdtclft/demo/entities \
		${WRKSRC}/tclpkg/tcldot/demo/doted \
		${WRKSRC}/tclpkg/tcldot/demo/gcat \
		${WRKSRC}/tclpkg/tclpathplan/demo/pathplan \
		${WRKSRC}/tclpkg/tkspline/demo/spline \
		${EXAMPLESDIR}/
	${INSTALL_DATA} \
		${WRKSRC}/tclpkg/gdtclft/demo/entities.README \
		${WRKSRC}/tclpkg/tcldot/demo/doted.README \
		${WRKSRC}/tclpkg/tcldot/demo/gcat.README \
		${WRKSRC}/tclpkg/tclpathplan/demo/pathplan.README \
		${WRKSRC}/tclpkg/tkspline/demo/spline.README \
		${EXAMPLESDIR}/
	@${MKDIR} ${EXAMPLESDIR}/pathplan_data
	${INSTALL_DATA} \
		${WRKSRC}/tclpkg/tclpathplan/demo/pathplan_data/*.dat \
		${EXAMPLESDIR}/pathplan_data/

.include <bsd.port.post.mk>
