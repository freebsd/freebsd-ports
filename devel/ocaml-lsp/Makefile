PORTNAME=	ocaml-lsp
DISTVERSION=	1.19.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Library implementing the LSP and JSONRPC protocols in Objective Caml
WWW=		https://github.com/Gbury/dolmen

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/ppx_yojson_conv/META:devel/ocaml-ppx_yojson_conv \
		${SA_DIR}/uutf/META:devel/ocaml-uutf \
		${SA_DIR}/yojson/META:textproc/ocaml-yojson
RUN_DEPENDS=	${SA_DIR}/ppx_yojson_conv_lib/META:devel/ocaml-ppx_yojson_conv_lib \
		${SA_DIR}/uutf/META:devel/ocaml-uutf \
		${SA_DIR}/yojson/META:textproc/ocaml-yojson

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml

USE_OCAML=		yes
OCAML_PACKAGES=		lsp jsonrpc
DUNE_INSTALL_TARGETS=	${OCAML_PACKAGES}

DOCSDIR=	${OCAML_DOCSDIR}
PORTDOCS=	${OCAML_PACKAGES:@p@$p/CHANGES.md $p/LICENSE.md $p/README.md@}

OPTIONS_DEFINE=		DOCS LSPSERVER
LSPSERVER_DESC=		Include ocaml-lsp-server
LSPSERVER_BROKEN=	needs ocamc-loc
LSPSERVER_VARS=		ocaml_packages+=ocaml-lsp-server

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(name lsp)/&\n(version ${DISTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/jsonrpc/jsonrpc.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lsp/lsp.cmxs

.include <bsd.port.mk>
