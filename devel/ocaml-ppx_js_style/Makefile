PORTNAME=	ppx_js_style
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	PPX plugin to enforce Jane Street Capital coding style
WWW=		https://github.com/janestreet/ppx_js_style

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/octavius/META:devel/ocaml-octavius \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib
RUN_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/octavius/META:devel/ocaml-octavius \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	janestreet

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/${PORTNAME}.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/ppx.exe

.include <bsd.port.mk>
