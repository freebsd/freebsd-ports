PORTNAME=	ppx_sexp_conv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Deriving PPX plugin to generate S-expression converters
WWW=		https://github.com/janestreet/ppx_sexp_conv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/sexplib0/META:devel/ocaml-sexplib0 \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib
RUN_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/sexplib0/META:devel/ocaml-sexplib0 \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	janestreet
USE_OCAML=	yes

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.org

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ppx_sexp_conv/expander/ppx_sexp_conv_expander.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ppx_sexp_conv/ppx_sexp_conv.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ppx_sexp_conv/runtime-lib/ppx_sexp_conv_lib.cmxs

.include <bsd.port.mk>
