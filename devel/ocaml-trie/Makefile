PORTNAME=	trie
PORTVERSION=	1.0.0
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Strict impure trie tree library for OCaml
WWW=		https://github.com/kandu/trie

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	kandu

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	LICENSE

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(lang dune 1.0)/(lang dune 2.5)/" \
		-e "s/(name ${PORTNAME})/&\n (version ${PORTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/trie/trie.cmxs

.include <bsd.port.mk>
