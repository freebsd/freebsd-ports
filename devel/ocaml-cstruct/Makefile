PORTNAME=	cstruct
DISTVERSIONPREFIX=	v
DISTVERSION=	6.2.0
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	OCaml library and syntax extension to access C-like structures
WWW=		https://github.com/mirage/ocaml-cstruct

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/fmt/META:devel/ocaml-fmt \
		${SA_DIR}/lwt/META:devel/ocaml-lwt \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib \
		${SA_DIR}/sexplib/META:devel/ocaml-sexplib
RUN_DEPENDS=	${SA_DIR}/fmt/META:devel/ocaml-fmt \
		${SA_DIR}/lwt/META:devel/ocaml-lwt \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib \
		${SA_DIR}/sexplib/META:devel/ocaml-sexplib

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	mirage
GH_PROJECT=	ocaml-${PORTNAME}
USE_OCAML=	yes
USE_OCAML_LDCONFIG=	yes
# missing ${PORTNAME}-async
OCAML_PACKAGES=		${PORTNAME} ${PORTNAME}-lwt ${PORTNAME}-sexp \
			${PORTNAME}-unix ppx_${PORTNAME}
DUNE_INSTALL_TARGETS=	${OCAML_PACKAGES}

DOCSDIR=	${OCAML_DOCSDIR}
PORTDOCS=	${OCAML_PACKAGES:@p@$p/CHANGES.md $p/LICENSE.md $p/README.md@}

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(name ${PORTNAME})/&\n (version ${PORTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	@(cd ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}; \
	${STRIP_CMD} \
		cstruct/dllcstruct_stubs.so \
		ppx_cstruct/ppx.exe \
		${OCAML_PACKAGES:@p@$p/${p:S/-/_/g}.cmxs@})

.include <bsd.port.mk>
