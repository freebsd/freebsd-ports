PORTNAME=	mew
PORTVERSION=	0.1.0
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Modal editing engine for OCaml
WWW=		https://github.com/kandu/mew

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${SA_DIR}/result/META:devel/ocaml-result \
		${SA_DIR}/trie/META:devel/ocaml-trie
RUN_DEPENDS=	${SA_DIR}/result/META:devel/ocaml-result \
		${SA_DIR}/trie/META:devel/ocaml-trie

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	kandu

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/mew/mew.cmxs

.include <bsd.port.mk>
