# Created by: b.f. <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	frama-c
DISTVERSIONPREFIX=	Sodium-
DISTVERSION=	20150201
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://frama-c.com/download/
DIST_SUBDIR=	framac-01

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible platform for source-code analysis of C

LICENSE=	LGPL21

EXTRACT_DEPENDS=	gtar:archivers/gtar
BUILD_DEPENDS=	${LOCALBASE}/lib/ocaml/ocamlgraph/graph.a:math/ocaml-ocamlgraph
RUN_DEPENDS=	${LOCALBASE}/lib/ocaml/ocamlgraph/graph.a:math/ocaml-ocamlgraph

USES=		gmake
USE_OCAML=	yes
GNU_CONFIGURE=	yes
EXTRACT_CMD=	gtar
EXTRACT_BEFORE_ARGS=	-xf
CONFIGURE_ARGS+=--with-cpp="${FRAMAC_DEFAULT_CPP}"
MAKE_ENV+=	FRAMAC_LIBDIR="${PREFIX}/lib/frama-c"

FRAMAC_DEFAULT_CPP?=	${CPP} -C -I${DATADIR}/libc -I.

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

post-install:
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/frama-c/plugins/*.cmxs
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/frama-c/plugins/gui/*.cmxs

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV:NCPP=*} \
	CPP="${CPP} -C -I${WRKSRC}/share/libc -I." \
	${MAKE_CMD} ${MAKE_ARGS} oracles fulltests

.include <bsd.port.mk>
