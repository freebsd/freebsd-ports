PORTNAME=	dune
PORTVERSION=	3.7.1
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Composable build system for OCaml (formerly jbuilder)
WWW=		https://dune.build/

LICENSE=	MIT

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml
USE_OCAML=	yes
USE_OCAML_LDCONFIG=	yes
SUB_FILES=	setup.ml
SUB_LIST=	OCAML_SITELIBDIR="${PREFIX}/${OCAML_SITELIBDIR}" \
		OCAML_LIBDIR="${PREFIX}/${OCAML_LIBDIR}" \
		OCAML_DOCSDIR="${OCAML_DOCSDIR}"

CONFLICTS_INSTALL=	wdune

ALL_TARGET=	release
MAKE_ENV=	LIBDIR="${PREFIX}/${OCAML_SITELIBDIR}" \
		DUNE_FREEBSD_STUBLIBS_RELATIVE_TO_LIBDIR=${PORTNAME}
DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
# FreeBSD-specific hack, do not nag upstream (for now)
	@${REINPLACE_CMD} -e '/doc_root = Path.relative/ \
		s:"doc:"${OCAML_DOCSDIR:S,^${PREFIX}/,,}:' \
		${WRKSRC}/src/dune_rules/install.ml
	@${REINPLACE_CMD} -e 's|\"man\"|\"share/man\"|g' \
		${WRKSRC}/src/dune_rules/install.ml
	@${REINPLACE_CMD} -e 's|\"stublibs\"|(try (ignore(Sys.getenv \"DUNE_FREEBSD_STUBLIBS_IN_PACKAGE\"); package) with Not_found -> (try Sys.getenv \"DUNE_FREEBSD_STUBLIBS_RELATIVE_TO_LIBDIR\" with Not_found -> \"stublibs\"))|g' \
		${WRKSRC}/src/dune_rules/install.ml

pre-configure:
	@${MV} ${WRKDIR}/setup.ml ${WRKSRC}/src/dune_rules/setup.ml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dune
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/dllxdg_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/dlldune_filesystem_stubs_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/dllstdune_stubs.so
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dune-action-plugin/dune_action_plugin.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dune-build-info/build_info.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dune-configurator/configurator.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dune-glob/dune_glob.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dune-private-libs/dune-section/dune_section.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dune-private-libs/dune_re/dune_re.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dune-private-libs/meta_parser/dune_meta_parser.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dune-private-libs/ocaml-config/ocaml_config.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dune-rpc/dune_rpc.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dune-rpc/private/dune_rpc_private.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dune-site/dune_site.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dune-site/plugins/dune_site_plugins.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dune-site/private/dune_site_private.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dyn/dyn.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dyn/pp/pp.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ordering/ordering.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/stdune/csexp/csexp.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/stdune/filesystem_stubs/dune_filesystem_stubs.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/stdune/stdune.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/xdg/xdg.cmxs

.include <bsd.port.mk>
