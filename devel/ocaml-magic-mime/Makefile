PORTNAME=	magic-mime
DISTVERSION=	1.3.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/mirage/ocaml-${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Embedded MIME type database for OCaml
WWW=		https://github.com/mirage/ocaml-magic-mime

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		ocaml:dune tar:tbz

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(version v.*)/(version ${DISTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/magic-mime/magic_mime_library.cmxs

.include <bsd.port.mk>
