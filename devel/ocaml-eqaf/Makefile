PORTNAME=	eqaf
DISTVERSION=	0.10
CATEGORIES=	devel
MASTER_SITES=	https://github.com/mirage/${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Constant-time string equality function for OCaml
WWW=		https://github.com/mirage/ocaml-eqaf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/cstruct/META:devel/ocaml-cstruct
RUN_DEPENDS=	${SA_DIR}/cstruct/META:devel/ocaml-cstruct

USES=		ocaml:dune tar:tbz
OCAML_PACKAGES=	eqaf eqaf-cstruct
DUNE_INSTALL_TARGETS=	${OCAML_PACKAGES}

DOCSDIR=	${OCAML_DOCSDIR}
PORTDOCS=	${OCAML_PACKAGES:@p@$p/CHANGES.md $p/LICENSE.md $p/README.md@}

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(version v.*)/(version ${DISTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	(cd ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}; \
	${STRIP_CMD} \
		eqaf/bigstring/eqaf_bigstring.cmxs eqaf/eqaf.cmxs \
		eqaf-cstruct/eqaf_cstruct.cmxs)

.include <bsd.port.mk>
