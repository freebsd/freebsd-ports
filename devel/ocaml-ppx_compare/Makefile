PORTNAME=	ppx_compare
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Deriving PPX plugin to generate comparision functions
WWW=		https://github.com/janestreet/ppx_compare

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib
RUN_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/ppx_deriving/META:devel/ocaml-ppx_deriving \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib

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
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ppx_compare/runtime-lib/ppx_compare_lib.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ppx_compare/expander/ppx_compare_expander.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ppx_compare/ppx_compare.cmxs

.include <bsd.port.mk>
