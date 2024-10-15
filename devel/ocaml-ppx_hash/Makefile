PORTNAME=	ppx_hash
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Deriving PPX plugin to generate hash functions
WWW=		https://github.com/janestreet/ppx_hash

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/ppx_compare/META:devel/ocaml-ppx_compare \
		${SA_DIR}/ppx_sexp_conv/META:devel/ocaml-ppx_sexp_conv \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib
RUN_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/ppx_compare/META:devel/ocaml-ppx_compare \
		${SA_DIR}/ppx_sexp_conv/META:devel/ocaml-ppx_sexp_conv \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib \
		${SA_DIR}/sexplib0/META:devel/ocaml-sexplib0

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	janestreet
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ppx_hash/expander/ppx_hash_expander.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ppx_hash/ppx_hash.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ppx_hash/runtime-lib/ppx_hash_lib.cmxs

.include <bsd.port.mk>
