PORTNAME=	csexp
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Canonical S-expressions for OCaml
WWW=		https://github.com/ocaml-dune/csexp

LICENSE=	MIT

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml-dune
GH_PROJECT=	csexp
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=		DOCS

post-patch:
	${REINPLACE_CMD} \
		-e "s/(name ${PORTNAME})/&\n (version ${PORTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/csexp.cmxs

.include <bsd.port.mk>
