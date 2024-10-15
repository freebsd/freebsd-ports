PORTNAME=	ppx_deriving
PORTVERSION=	6.0.2
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Helpers to generate code deriving from types, for OCaml
WWW=		https://github.com/ocaml-ppx/ppx_deriving

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${LOCALBASE}/bin/cppo:devel/ocaml-cppo \
		${SA_DIR}/findlib/META:devel/ocaml-findlib \
		${SA_DIR}/ppx_derivers/META:devel/ocaml-ppx_derivers \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib
RUN_DEPENDS=	${SA_DIR}/findlib/META:devel/ocaml-findlib \
		${SA_DIR}/ppx_derivers/META:devel/ocaml-ppx_derivers \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib

USES=			ocaml:dune
USE_GITHUB=		yes
GH_ACCOUNT=		ocaml-ppx
USE_OCAML=		yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGELOG.md LICENSE.txt README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-install:
	@(cd ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}; \
	${STRIP_CMD} \
		ppx_deriving \
		api/ppx_deriving_api.cmxs create/ppx_deriving_create.cmxs \
		enum/ppx_deriving_enum.cmxs eq/ppx_deriving_eq.cmxs \
		fold/ppx_deriving_fold.cmxs iter/ppx_deriving_iter.cmxs \
		make/ppx_deriving_make.cmxs map/ppx_deriving_map.cmxs \
		ord/ppx_deriving_ord.cmxs runtime/ppx_deriving_runtime.cmxs \
		show/ppx_deriving_show.cmxs std/ppx_deriving_std.cmxs)

.include <bsd.port.mk>
