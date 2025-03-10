PORTNAME=	ppxlib
DISTVERSION=	0.33.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Library to write PPX syntax extension for OCaml
WWW=		https://github.com/ocaml-ppx/ppxlib/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/ocaml-compiler-libs/META:devel/ocaml-compiler-libs \
		${SA_DIR}/ppx_derivers/META:devel/ocaml-ppx_derivers \
		${SA_DIR}/sexplib0/META:devel/ocaml-sexplib0
RUN_DEPENDS=	${SA_DIR}/ocaml-compiler-libs/META:devel/ocaml-compiler-libs \
		${SA_DIR}/ppx_derivers/META:devel/ocaml-ppx_derivers \
		${SA_DIR}/sexplib0/META:devel/ocaml-sexplib0

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml-ppx

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md HISTORY.md LICENSE.md README.md odoc-pages

OPTIONS_DEFINE=	DOCS

DUNE_INSTALL_TARGETS=	${PORTNAME}
SA_DIR=			${LOCALBASE}/${OCAML_SITELIBDIR}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-patch:
	@(cd ${WRKSRC}; \
	${REINPLACE_CMD} -e s/stdlib-shims//g \
		ast/dune dune-project metaquot_lifters/dune src/dune src/gen/dune \
		stdppx/dune traverse/dune; \
	${REINPLACE_CMD} -e "s/(name ${PORTNAME})/&\n (version ${PORTVERSION})/" \
		dune-project)

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/ast/ppxlib_ast.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/astlib/astlib.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/runner/ppxlib_runner.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/metaquot/ppxlib_metaquot.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/metaquot/ppx.exe \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/metaquot_lifters/ppxlib_metaquot_lifters.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/runner_as_ppx/ppxlib_runner_as_ppx.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/print_diff/ppxlib_print_diff.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/stdppx/stdppx.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/traverse/ppxlib_traverse.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/traverse_builtins/ppxlib_traverse_builtins.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/ppxlib.cmxs

.include <bsd.port.mk>
