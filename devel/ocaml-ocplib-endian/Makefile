PORTNAME=	ocplib-endian
PORTVERSION=	1.2
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Optimized manipulation of integers over the standard byte-array types of OCaml
WWW=		https://github.com/janestreet/base

LICENSE=	LGPL21+ # with a special exception to clause 6

BUILD_DEPENDS=	cppo:devel/ocaml-cppo

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	OCamlPro
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(name ${PORTNAME})/&\n (version ${PORTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/bigstring/ocplib_endian_bigstring.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/ocplib_endian.cmxs

.include <bsd.port.mk>
