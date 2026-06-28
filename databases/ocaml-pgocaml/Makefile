PORTNAME=	pgocaml
PORTVERSION=	4.4.0+git20250314
CATEGORIES=	databases
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	PostgreSQL client library for OCaml with a type-safe query syntax extension
WWW=		https://github.com/darioteixeira/pgocaml

LICENSE=	LGPL20 # with a special exception to clause 6

BUILD_DEPENDS=	${SA_DIR}/base64/META:converters/ocaml-base64 \
		${SA_DIR}/calendar/META:devel/ocaml-calendar \
		${SA_DIR}/camlp-streams/META:devel/ocaml-camlp-streams \
		${SA_DIR}/csv/META:textproc/ocaml-csv \
		${SA_DIR}/digestif/META:security/ocaml-digestif \
		${SA_DIR}/hex/META:converters/ocaml-hex \
		${SA_DIR}/re/META:devel/ocaml-re \
		${SA_DIR}/parsexp/META:devel/ocaml-parsexp \
		${SA_DIR}/ppx_deriving/META:devel/ocaml-ppx_deriving \
		${SA_DIR}/ppx_optcomp/META:devel/ocaml-ppx_optcomp \
		${SA_DIR}/ppx_sexp_conv/META:devel/ocaml-ppx_sexp_conv \
		${SA_DIR}/rresult/META:devel/ocaml-rresult \
		${SA_DIR}/sexplib/META:devel/ocaml-sexplib
RUN_DEPENDS=	${SA_DIR}/base64/META:converters/ocaml-base64 \
		${SA_DIR}/calendar/META:devel/ocaml-calendar \
		${SA_DIR}/camlp-streams/META:devel/ocaml-camlp-streams \
		${SA_DIR}/csv/META:textproc/ocaml-csv \
		${SA_DIR}/digestif/META:security/ocaml-digestif \
		${SA_DIR}/hex/META:converters/ocaml-hex \
		${SA_DIR}/re/META:devel/ocaml-re \
		${SA_DIR}/parsexp/META:devel/ocaml-parsexp \
		${SA_DIR}/ppx_deriving/META:devel/ocaml-ppx_deriving \
		${SA_DIR}/ppx_sexp_conv/META:devel/ocaml-ppx_sexp_conv \
		${SA_DIR}/rresult/META:devel/ocaml-rresult \
		${SA_DIR}/sexplib/META:devel/ocaml-sexplib

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	darioteixeira
GH_TAGNAME=	572dd886b975872b28f89944246d14e983f7d181
OCAML_PACKAGES=		pgocaml pgocaml_ppx
DUNE_INSTALL_TARGETS=	${OCAML_PACKAGES}

DOCSDIR=	${OCAML_DOCSDIR}
PORTDOCS=	${OCAML_PACKAGES:@p@$p/CHANGELOG.txt $p/LICENSE.txt $p/README.md@}

OPTIONS_DEFINE=		DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-install:
	(cd ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}; ${STRIP_CMD} \
		pgocaml_ppx/pgocaml_ppx.cmxs pgocaml_ppx/ppx.exe \
		pgocaml/PGOCaml.cmxs)

.include <bsd.port.mk>
