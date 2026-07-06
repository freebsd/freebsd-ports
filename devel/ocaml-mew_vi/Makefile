PORTNAME=	mew_vi
PORTVERSION=	0.5.0
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	VI-like modal editing engine for OCaml
WWW=		https://github.com/kandu/mew_vi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${SA_DIR}/mew/META:devel/ocaml-mew \
		${SA_DIR}/react/META:devel/ocaml-react
RUN_DEPENDS=	${SA_DIR}/mew/META:devel/ocaml-mew \
		${SA_DIR}/react/META:devel/ocaml-react

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	kandu

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/mew_vi/mew_vi.cmxs

.include <bsd.port.mk>
