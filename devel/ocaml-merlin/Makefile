PORTNAME=	merlin
DISTVERSION=	4.19-414
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ocaml/${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Context sensitive completion for OCaml
WWW=		https://ocaml.github.io/merlin/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${SA_DIR}/csexp/META:devel/ocaml-csexp \
		${SA_DIR}/findlib/META:devel/ocaml-findlib \
		${SA_DIR}/yojson/META:textproc/ocaml-yojson
TEST_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash \
		${LOCALBASE}/bin/jq:textproc/jq \
		${LOCALBASE}/${OCAML_SITELIBDIR}/alcotest/META:devel/ocaml-alcotest

USES=		emacs ocaml:dune,ldconfig tar:tbz
OCAML_PACKAGES=		dot-merlin-reader merlin merlin-lib # ocaml-index
DUNE_INSTALL_TARGETS=	${OCAML_PACKAGES}

DOCSDIR=	${OCAML_DOCSDIR}
PORTDOCS=	${OCAML_PACKAGES:@p@$p/CHANGES.md $p/LICENSE $p/README.md@}

OPTIONS_DEFINE=	DOCS EMACS VIM
OPTIONS_DEFAULT=EMACS VIM
OPTIONS_SUB=	yes

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e 's@emacs/site-lisp@${EMACS_SITE_LISPDIR:S/^share\///}/${PORTNAME}@' \
		${WRKSRC}/emacs/dune

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/dot-merlin-reader \
		${STAGEDIR}${PREFIX}/bin/ocamlmerlin \
		${STAGEDIR}${PREFIX}/bin/ocamlmerlin-server
	cd ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR} && ${STRIP_CMD} \
		merlin/dllmerlin_utils_stubs.so \
		merlin/dllos_ipc_stubs.so \
		merlin-lib/analysis/merlin_analysis.cmxs \
		merlin-lib/commands/merlin_commands.cmxs \
		merlin-lib/config/merlin_config.cmxs \
		merlin-lib/dot_protocol/merlin_dot_protocol.cmxs \
		merlin-lib/extend/merlin_extend.cmxs \
		merlin-lib/kernel/merlin_kernel.cmxs \
		merlin-lib/ocaml_merlin_specific/merlin_specific.cmxs \
		merlin-lib/ocaml_parsing/ocaml_parsing.cmxs \
		merlin-lib/ocaml_preprocess/ocaml_preprocess.cmxs \
		merlin-lib/ocaml_typing/ocaml_typing.cmxs \
		merlin-lib/ocaml_utils/ocaml_utils.cmxs \
		merlin-lib/os_ipc/os_ipc.cmxs \
		merlin-lib/query_commands/query_commands.cmxs \
		merlin-lib/query_protocol/query_protocol.cmxs \
		merlin-lib/sherlodoc/merlin_sherlodoc.cmxs \
		merlin-lib/utils/merlin_utils.cmxs

post-install-EMACS-off:
	${RM} -r ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}

post-install-VIM-off:
	${RM} -r ${STAGEDIR}${PREFIX}/${DATADIR}/vim

do-test:
	cd ${TEST_WRKSRC} && ${SETENVI} ${TEST_ENV} ${DUNE_ENV} \
		${DUNE_CMD} build ${DUNE_ARGS} @runtest

.include <bsd.port.mk>
