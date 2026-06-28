PORTNAME=	gmap
DISTVERSION=	0.3.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/hannesm/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Hashmap with heterogeneous values using OCaml GADT
WWW=		https://github.com/hannesm/gmap

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md


USES=		ocaml:dune tar:tbz

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(name ${PORTNAME})/&\n(version ${DISTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/gmap/gmap.cmxs

.include <bsd.port.mk>
