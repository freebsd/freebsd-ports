PORTNAME=	ppx_yojson_conv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	PPX plugin to derive (de)serialization functions using Yojson
WWW=		https://github.com/janestreet/ppx_yojson_conv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/ppx_js_style/META:devel/ocaml-ppx_js_style \
		${SA_DIR}/ppx_yojson_conv_lib/META:devel/ocaml-ppx_yojson_conv_lib \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib \
		${SA_DIR}/sexplib0/META:devel/ocaml-sexplib0 \
		${SA_DIR}/yojson/META:textproc/ocaml-yojson
RUN_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/ppx_yojson_conv_lib/META:devel/ocaml-ppx_yojson_conv_lib \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib \
		${SA_DIR}/sexplib0/META:devel/ocaml-sexplib0 \
		${SA_DIR}/yojson/META:textproc/ocaml-yojson

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	janestreet

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	LICENSE.md README.org

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(lang dune 3.11)/(lang dune 3.7)/" \
		${WRKSRC}/dune-project

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ppx_yojson_conv/expander/ppx_yojson_conv_expander.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ppx_yojson_conv/ppx_yojson_conv.cmxs

.include <bsd.port.mk>
