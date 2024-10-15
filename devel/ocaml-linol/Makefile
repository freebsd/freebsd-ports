PORTNAME=	linol
PORTVERSION=	0.6
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Wrapper for ocaml-lsp and JSON-RPC implementation for Objective Caml
WWW=		https://github.com/c-cube/linol

LICENSE=	MIT

BUILD_DEPENDS=	${SA_DIR}/logs/META:devel/ocaml-logs \
		${SA_DIR}/lsp/META:devel/ocaml-lsp \
		${SA_DIR}/lwt/META:devel/ocaml-lwt \
		${SA_DIR}/ppx_yojson_conv/META:devel/ocaml-ppx_yojson_conv \
		${SA_DIR}/trace/META:devel/ocaml-trace \
		${SA_DIR}/yojson/META:textproc/ocaml-yojson
RUN_DEPENDS=	${SA_DIR}/logs/META:devel/ocaml-logs \
		${SA_DIR}/lsp/META:devel/ocaml-lsp \
		${SA_DIR}/lwt/META:devel/ocaml-lwt \
		${SA_DIR}/ppx_yojson_conv_lib/META:devel/ocaml-ppx_yojson_conv_lib \
		${SA_DIR}/trace/META:devel/ocaml-trace \
		${SA_DIR}/yojson/META:textproc/ocaml-yojson

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	c-cube
USE_OCAML=	yes
OCAML_PACKAGES=	${PORTNAME} ${PORTNAME}-lwt
DUNE_INSTALL_TARGETS=	${OCAML_PACKAGES}

DOCSDIR=	${OCAML_DOCSDIR}
PORTDOCS=	${OCAML_PACKAGES:@p@$p/CHANGES.md $p/README.md@}

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/${PORTNAME}.cmxs

.include <bsd.port.mk>
