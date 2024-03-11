PORTNAME=	astring
PORTVERSION=	0.8.5
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/astring/releases/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	String library for Objective Caml
WWW=		https://erratique.ch/software/astring

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/topkg/META:devel/ocaml-topkg \
		ocamlbuild:devel/ocaml-ocamlbuild \
		opam-installer:devel/ocaml-opam

USES=		tar:tbz
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md
PORTEXAMPLES=	examples examples.ml

OPTIONS_DEFINE=	DOCS EXAMPLES

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

do-build:
	@(cd ${BUILD_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		ocaml pkg/pkg.ml build \
		--tests true --jobs ${MAKE_JOBS_NUMBER})

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		opam-installer -i \
		--prefix=${STAGEDIR}${PREFIX} \
		--docdir=${OCAML_DOCSDIR:S,^${PREFIX}/,,} \
		--libdir=${OCAML_SITELIBDIR} ${PORTNAME}.install)

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/_build/test/examples.native ${STAGEDIR}${EXAMPLESDIR}/examples
	${MV} ${STAGEDIR}${DOCSDIR}/examples.ml ${STAGEDIR}${EXAMPLESDIR}/examples.ml

do-install-EXAMPLES-off:
	${RM} ${STAGEDIR}${DOCSDIR}/examples.ml

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/astring.cmxs
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/astring_top.cmxs

.include <bsd.port.mk>
