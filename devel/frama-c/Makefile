# Created by: b.f. <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	frama-c
DISTVERSIONPREFIX=	Phosphorus-
DISTVERSION=	20170501
CATEGORIES=	devel lang
MASTER_SITES=	http://frama-c.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible platform for source-code analysis of C

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/lib/ocaml/ocamlgraph/graph.a:math/ocaml-ocamlgraph \
	    ${LOCALBASE}/lib/ocaml/site-lib/zarith/zarith.a:math/ocaml-zarith
RUN_DEPENDS=	${LOCALBASE}/lib/ocaml/ocamlgraph/graph.a:math/ocaml-ocamlgraph \
	    ${LOCALBASE}/lib/ocaml/site-lib/zarith/zarith.a:math/ocaml-zarith
LIB_DEPENDS=	libgmp.so:math/gmp \
	    libfreetype.so:print/freetype2 \
	    libfontconfig.so:x11-fonts/fontconfig

USES=		gettext-runtime gmake gnome localbase pathfix pkgconfig
USE_OCAML=	yes
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 gtksourceview2 \
	    libartlgpl2 libgnomecanvas pango

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cpp="${FRAMAC_DEFAULT_CPP}" --disable-e_acsl
MAKE_ENV+=	FRAMAC_LIBDIR="${FRAMAC_LIBDIR}" \
	    FRAMAC_DATADIR="${FRAMAC_DATADIR}" \
	    STAGEDIR="${STAGEDIR}"

FRAMAC_DEFAULT_CPP?=	${CPP} -C -I${DATADIR}/libc -I.
FRAMAC_LIBDIR=		${PREFIX}/lib/${PORTNAME}
FRAMAC_DATADIR=		${DATADIR}

post-patch:
	@cd ${WRKSRC}/tests; ${MKDIR} aorai report wp wp_acsl wp_bts \
	wp_engine wp_hoare wp_plugin wp_runtime wp_store wp_typed
	@${REINPLACE_CMD} -e 's|@make |@${MAKE_CMD} |' \
			${WRKSRC}/src/plugins/*/Makefile.in
	@${REINPLACE_CMD} \
		-e 's|$$(CP)|${INSTALL_DATA}|' \
		-e 's|add_prefix|addprefix|' \
			${WRKSRC}/share/Makefile.plugin.template
	@${REINPLACE_CMD} \
		-e 's|$$(CP)|${INSTALL_DATA}|' \
		-e 's|add_prefix|addprefix|' \
			${WRKSRC}/share/Makefile.common
	@${REINPLACE_CMD} \
		-e '\|$$(CP) $$(TARGETS|s|$$(CP)|${INSTALL_DATA}|' \
		-e '\|$$(CP) frama-c|s|$$(CP)|${INSTALL_SCRIPT}|' \
			${WRKSRC}/share/Makefile.dynamic
	@${REINPLACE_CMD} \
		-e '\|$$(CP) $$(TARGETS|s|$$(CP)|${INSTALL_DATA}|' \
		-e '\|$$(CP) frama-c|s|$$(CP)|${INSTALL_SCRIPT}|' \
			${WRKSRC}/share/Makefile.common
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
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugins/gui/*.cmxs
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}/plugins/top/*.cmxs

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV:NCPP=*} \
	CPP="${CPP} -C -I${WRKSRC}/share/libc -I." \
	${MAKE_CMD} ${MAKE_ARGS} oracles fulltests

.include <bsd.port.mk>
