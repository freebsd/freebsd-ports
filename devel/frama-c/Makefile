# Created by: b.f. <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=		frama-c
DISTVERSIONPREFIX=	Neon-
DISTVERSION=		20140301
PORTREVISION=	2
CATEGORIES=		devel
MASTER_SITES=		http://frama-c.com/download/ LOCAL/bf

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Extensible platform for source-code analysis of C

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/lib/ocaml/ocamlgraph/graph.a:${PORTSDIR}/math/ocaml-ocamlgraph
RUN_DEPENDS=	${LOCALBASE}/lib/ocaml/ocamlgraph/graph.a:${PORTSDIR}/math/ocaml-ocamlgraph

USES=		gmake
USE_OCAML=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-cpp="${FRAMAC_DEFAULT_CPP}"
MAKE_ENV+=	FRAMAC_LIBDIR="${PREFIX}/lib/frama-c"

OPTIONS_DEFINE=	ALTERGO COQ GUI PLUGINS
OPTIONS_DEFAULT=ALTERGO GUI PLUGINS
OPTIONS_SUB=	yes
ALTERGO_DESC=	Alt-Ergo plugin (requires PLUGINS)
COQ_DESC=	Coq plugin (requires PLUGINS)
GUI_DESC=	Graphical User Interface (requires PLUGINS)

.include <bsd.port.options.mk>

FRAMAC_DEFAULT_CPP?=	${CPP} -C -I${DATADIR}/libc -I.

.if ${PORT_OPTIONS:MALTERGO}
.if !${PORT_OPTIONS:MPLUGINS}
IGNORE=	the Alt-Ergo plugin requires the PLUGINS option to be enabled
.endif
BUILD_DEPENDS+=		alt-ergo:${PORTSDIR}/math/alt-ergo
RUN_DEPENDS+=		alt-ergo:${PORTSDIR}/math/alt-ergo
.else
CONFIGURE_ENV+=		HAS_ALTERGO=no
.endif

.if ${PORT_OPTIONS:MCOQ}
.if !${PORT_OPTIONS:MPLUGINS}
IGNORE=	the Coq plugin requires the PLUGINS option to be enabled
.endif
BUILD_DEPENDS+=		coqc:${PORTSDIR}/math/coq
RUN_DEPENDS+=		coqc:${PORTSDIR}/math/coq
.else
CONFIGURE_ENV+=		HAS_COQ=no
.endif

.if ${PORT_OPTIONS:MGUI}
.if !${PORT_OPTIONS:MPLUGINS}
IGNORE=	the GUI requires the PLUGINS option to be enabled
.endif
BUILD_DEPENDS+=		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
RUN_DEPENDS+=		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2
CONFIGURE_ARGS+=	--enable-gui
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

.if ${PORT_OPTIONS:MPLUGINS}
BUILD_DEPENDS+=		dot:${PORTSDIR}/graphics/graphviz \
			ltl2ba:${PORTSDIR}/math/ltl2ba
RUN_DEPENDS+=	 	dot:${PORTSDIR}/graphics/graphviz \
			ltl2ba:${PORTSDIR}/math/ltl2ba
.else
CONFIGURE_ARGS+=	--with-no-plugin
.endif

post-patch:
	@cd ${WRKSRC}/tests; ${MKDIR} aorai report wp wp_acsl wp_bts \
	wp_engine wp_hoare wp_plugin wp_runtime wp_store wp_typed
	@${REINPLACE_CMD} -e 's|@make |@${MAKE_CMD} |' \
			${WRKSRC}/src/aorai/Makefile.in
	@${REINPLACE_CMD} \
		-e 's|$$(CP)|${INSTALL_DATA}|' \
		-e 's|add_prefix|addprefix|' \
			${WRKSRC}/share/Makefile.plugin
	@${REINPLACE_CMD} \
		-e '\|$$(CP) $$(TARGETS|s|$$(CP)|${INSTALL_DATA}|' \
		-e '\|$$(CP) frama-c|s|$$(CP)|${INSTALL_SCRIPT}|' \
			${WRKSRC}/share/Makefile.dynamic
	@${REINPLACE_CMD} -e '\|^# Installation|,\|^# File headers|{ \
		\|_LIBDIR|s|(FRAMAC_LIBDIR)|(DESTDIR)$$(FRAMAC_LIBDIR)|; \
		\|_PLUGINDIR|s|(FRAMAC_PLUGINDIR)|(DESTDIR)$$(FRAMAC_PLUGINDIR)|; \
		\|$$(CP).*bin|s|$$(CP)|${INSTALL_SCRIPT}|; \
		\|$$(CP).*man/|s|$$(CP)|${INSTALL_MAN}|; \
		s|$$(CP)|${INSTALL_DATA}|; }' \
			${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|HAS_ALTERGO=$$||' \
		-e '\|case $$ALTERGO_VERSION in|{N; s|0\.92\.2|0.94*|;}' \
		-e 's|HAS_COQ=$$||' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -Ee 's@(\+|/)(lablgtk2)@\1site-lib/\2@' \
		${WRKSRC}/src/kernel/dynamic.ml

.if ${PORT_OPTIONS:MGUI}
pre-configure:
	@(if [ ! -e ${LOCALBASE}/${OCAML_SITELIBDIR}/lablgtk2/gtkSourceView2.cmi -o \
	! -e ${LOCALBASE}/${OCAML_SITELIBDIR}/lablgtk2/gnomeCanvas.cmi ] ; then \
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
	@${TOUCH} ${STAGEDIR}${PREFIX}/lib/frama-c/plugins/.keep_me \
		${STAGEDIR}${PREFIX}/lib/frama-c/plugins/gui/.keep_me

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV:NCPP=*} \
	CPP="${CPP} -C -I${WRKSRC}/share/libc -I." \
	${MAKE_CMD} ${MAKE_ARGS} oracles fulltests

.include <bsd.port.mk>
