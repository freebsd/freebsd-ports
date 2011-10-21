# New ports collection makefile for:    frama-c
# Date created:         25 May 2011
# Whom:                 b.f. <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		frama-c
DISTVERSIONPREFIX=	Carbon-
DISTVERSION=		20110201
CATEGORIES=		devel
MASTER_SITES=		http://frama-c.com/download/ LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Extensible platform for source-code analysis of C

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/lib/ocaml/ocamlgraph/graph.a:${PORTSDIR}/math/ocaml-ocamlgraph
RUN_DEPENDS=	${LOCALBASE}/lib/ocaml/ocamlgraph/graph.a:${PORTSDIR}/math/ocaml-ocamlgraph

GNU_CONFIGURE=	yes
MAKE_ENV+=	FRAMAC_LIBDIR="${PREFIX}/lib/frama-c"
MAN1=		frama-c.1 frama-c-gui.1
OPTIONS=	GUI	"Build GUI" on \
		PLUGINS "Build bundled plugins" on
USE_GMAKE=	yes
USE_OCAML=	yes

.include <bsd.port.options.mk>

.if defined(WITH_GUI)
.if !defined(WITH_PLUGINS)
IGNORE =	requires WITH_PLUGINS for WITH_GUI
.endif
BUILD_DEPENDS +=	lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
CONFIGURE_ARGS+=	--enable-gui
PLIST_SUB+=		GUI=""
.else
CONFIGURE_ARGS+=	--disable-gui
PLIST_SUB+=		GUI="@comment "
.endif

.if defined(WITH_PLUGINS)
BUILD_DEPENDS +=	dot:${PORTSDIR}/graphics/graphviz \
		ltl2ba:${PORTSDIR}/math/ltl2ba
RUN_DEPENDS+=		dot:${PORTSDIR}/graphics/graphviz \
		ltl2ba:${PORTSDIR}/math/ltl2ba
PLIST_SUB+=		PLUGINS=""
.else
CONFIGURE_ARGS+=	--with-no-plugin
PLIST_SUB+=		PLUGINS="@comment "
.endif

post-patch:
	@${MKDIR} ${WRKSRC}/tests/occurrence
	@${REINPLACE_CMD} -e 's|@make |@${GMAKE} |' \
			${WRKSRC}/src/aorai/Makefile.in
	@${GREP} -le 'make ' -r ${WRKSRC}/tests | ${XARGS} ${REINPLACE_CMD} \
		-e 's|make |${GMAKE} |'
	@${REINPLACE_CMD} \
		-e 's|$$(CP)|${INSTALL_DATA}|' \
		-e 's|add_prefix|addprefix|' \
			${WRKSRC}/share/Makefile.plugin
	@${REINPLACE_CMD} \
		-e '\|$$(CP) $$(TARGETS|s|$$(CP)|${INSTALL_DATA}|' \
		-e '\|$$(CP) frama-c|s|$$(CP)|${INSTALL_SCRIPT}|' \
			${WRKSRC}/share/Makefile.dynamic
	@${REINPLACE_CMD} -e '\|^# Installation|,\|^# File headers|{ \
		\|$$(CP).*bin|s|$$(CP)|${INSTALL_SCRIPT}|; \
		\|$$(CP) -R doc/manuals $$(FRAMAC_DATADIR)| \
		s||${MKDIR} $$(FRAMAC_DATADIR)/manuals ; \
		${INSTALL_DATA} doc/manuals/* $$(FRAMAC_DATADIR)/manuals|; \
		\|$$(CP).*man|s|$$(CP)\( -R\)*|${INSTALL_MAN}|; \
		\|$$(CP).*share|s|$$(CP)\( -R\)*|${INSTALL_DATA}|; \
		s|$$(CP)|${INSTALL_DATA}|; }' \
			${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '\|case $$OCAMLGRAPH_VERSION in| \
		{N; s|1\.7|1.[78]*|;}' \
			${WRKSRC}/configure

.if defined(WITH_GUI)
pre-configure:
	@(if [ ! -e ${LOCALBASE}/lib/ocaml/lablgtk2/gtkSourceView2.cmi -o \
	! -e ${LOCALBASE}/lib/ocaml/lablgtk2/gnomeCanvas.cmi ] ; then \
	${ECHO_MSG} "==> The WITH_GUI option for ${PKGNAME} requires" ; \
	${ECHO_MSG} "==> x11-toolkits/ocaml-lablgtk2 to be built" ; \
	${ECHO_MSG} "==> WITH_GNOMECANVAS and WITH_GTKSOURCEVIEW2" ; \
	exit 1; fi)
	@(if [ ! -e ${LOCALBASE}/lib/ocaml/ocamlgraph/dgraph.cmi ] ; then \
	${ECHO_MSG} "==> The WITH_GUI option for ${PKGNAME} requires" ; \
	${ECHO_MSG} "==> math/ocaml-ocamlgraph to be built WITH_GUI" ; \
	exit 1; fi)

.endif

post-install:
		@${TOUCH} ${PREFIX}/lib/frama-c/plugins/.keep_me \
		${PREFIX}/lib/frama-c/plugins/gui/.keep_me

.if defined(MAINTAINER_MODE)
check regression-test test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} \
	FRAMAC_LIB=${WRKSRC}/lib/fc \
	FRAMAC_PLUGIN=${WRKSRC}/lib/plugins \
	FRAMAC_SHARE=${WRKSRC}/share \
	${GMAKE} ${_MAKE_JOBS} ${MAKE_ARGS} tests)

.endif

.include <bsd.port.mk>
