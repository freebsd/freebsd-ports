PORTNAME=	bos
PORTVERSION=	0.2.1
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/bos/releases/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Basic OS interaction library for Objective Caml
WWW=		https://erratique.ch/software/bos

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/astring/META:devel/ocaml-astring \
		${SA_DIR}/fmt/META:devel/ocaml-fmt \
		${SA_DIR}/fpath/META:devel/ocaml-fpath \
		${SA_DIR}/logs/META:devel/ocaml-logs \
		${SA_DIR}/mtime/META:devel/ocaml-mtime \
		${SA_DIR}/rresult/META:devel/ocaml-rresult \
		${SA_DIR}/topkg/META:devel/ocaml-topkg \
		ocamlbuild:devel/ocaml-ocamlbuild \
		opam-installer:devel/ocaml-opam
RUN_DEPENDS=	${SA_DIR}/astring/META:devel/ocaml-astring \
		${SA_DIR}/fmt/META:devel/ocaml-fmt \
		${SA_DIR}/fpath/META:devel/ocaml-fpath \
		${SA_DIR}/logs/META:devel/ocaml-logs \
		${SA_DIR}/mtime/META:devel/ocaml-mtime \
		${SA_DIR}/rresult/META:devel/ocaml-rresult

USES=		tar:tbz
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=		DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

do-build:
	@(cd ${BUILD_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		ocaml pkg/pkg.ml build \
		--jobs ${MAKE_JOBS_NUMBER})

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		opam-installer -i \
		--prefix=${STAGEDIR}${PREFIX} \
		--docdir=${OCAML_DOCSDIR:S,^${PREFIX}/,,} \
		--libdir=${OCAML_SITELIBDIR} ${PORTNAME}.install)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/bos.cmxs
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/bos_setup.cmxs
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/bos_top.cmxs

.include <bsd.port.mk>
