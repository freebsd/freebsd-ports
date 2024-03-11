PORTNAME=	rresult
PORTVERSION=	0.7.0
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/rresult/releases/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Result combinator library for Objective Caml
WWW=		https://erratique.ch/software/rresult

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/topkg/META:devel/ocaml-topkg \
		ocamlbuild:devel/ocaml-ocamlbuild \
		opam-installer:devel/ocaml-opam

USES=		tar:tbz
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md odoc-pages

OPTIONS_DEFINE=	DOCS

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
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/rresult.cmxs
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/rresult_top.cmxs

.include <bsd.port.mk>
