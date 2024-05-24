PORTNAME=	ppx_derivers
PORTVERSION=	1.2.1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	PPX compatibility library for OCaml
WWW=		https://github.com/ocaml-ppx/ppx_derivers

LICENSE=	MIT

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml-ppx
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/ppx_derivers
PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(name ${PORTNAME})/&\n (version ${PORTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ppx_derivers/ppx_derivers.cmxs

.include <bsd.port.mk>
