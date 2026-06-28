PORTNAME=	ppx_optcomp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	OCaml syntax extension for optional compilation
WWW=		https://github.com/janestreet/ppx_optcomp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib \
		${SA_DIR}/stdio/META:devel/ocaml-stdio
RUN_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib \
		${SA_DIR}/stdio/META:devel/ocaml-stdio

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	janestreet

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(version v.*)/(version ${DISTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ppx_optcomp/ppx_optcomp.cmxs

.include <bsd.port.mk>
