PORTNAME=	hex
DISTVERSION=	1.5.0
CATEGORIES=	converters
MASTER_SITES=	https://github.com/mirage/ocaml-${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Hexadecimal encoding library for OCaml
WWW=		https://github.com/mirage/ocaml-hex

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/cstruct/META:devel/ocaml-cstruct
RUN_DEPENDS=	${SA_DIR}/cstruct/META:devel/ocaml-cstruct

USES=		ocaml:dune tar:tbz

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
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/hex/hex.cmxs

.include <bsd.port.mk>
