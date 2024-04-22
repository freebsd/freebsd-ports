PORTNAME=	seq
PORTVERSION=	0.2.2
DISTVERSIONPREFIX=	${PKGNAMEPREFIX}${PORTNAME}-
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Compatibility library for the iterator type of OCaml
WWW=		https://github.com/c-cube/seq

LICENSE=	LGPL21

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	c-cube
GH_TAGNAME=	6934813195285661cba3e017e7d3cd79d362bb2f
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	LICENSE README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/seq.cmxs

.include <bsd.port.mk>
