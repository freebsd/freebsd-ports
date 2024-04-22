PORTNAME=	camlp-streams
PORTVERSION=	5.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Stream and Genlex libraries for OCaml
WWW=		https://github.com/ocaml/camlp-streams

LICENSE=	LGPL21

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} \
		-e "s/(name ${PORTNAME})/&\n (version ${PORTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/camlp_streams.cmxs

.include <bsd.port.mk>
