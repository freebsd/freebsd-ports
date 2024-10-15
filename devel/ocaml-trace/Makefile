PORTNAME=	trace
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Library and PPX rewriter for code instrumentation in Objective Caml
WWW=		https://github.com/c-cube/trace

LICENSE=	MIT

BUILD_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/hmap/META:devel/ocaml-hmap \
		${SA_DIR}/mtime/META:devel/ocaml-mtime \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib
RUN_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/hmap/META:devel/ocaml-hmap \
		${SA_DIR}/mtime/META:devel/ocaml-mtime \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	c-cube
GH_PROJECT=	ocaml-trace

USE_OCAML=		yes
OCAML_PACKAGES=		trace ppx_trace trace-tef
DUNE_INSTALL_TARGETS=	${OCAML_PACKAGES}

DOCSDIR=	${OCAML_DOCSDIR}
PORTDOCS=	${OCAML_PACKAGES:@p@$p/CHANGES.md $p/README.md@}

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ppx_trace/ppx.exe \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ppx_trace/ppx_trace.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/trace/trace.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/trace/core/trace_core.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/trace/private/util/trace_private_util.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/trace-tef/trace_tef.cmxs

.include <bsd.port.mk>
