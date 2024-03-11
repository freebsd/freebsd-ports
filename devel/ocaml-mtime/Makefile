PORTNAME=	mtime
PORTVERSION=	2.0.0
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/mtime/releases/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Platform independent wall-clock monotonic time for OCaml
WWW=		https://erratique.ch/software/mtime

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/topkg/META:devel/ocaml-topkg \
		ocamlbuild:devel/ocaml-ocamlbuild \
		opam-installer:devel/ocaml-opam

USES=		tar:tbz
USE_OCAML=	yes
USE_OCAML_LDCONFIG=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md odoc-pages
PORTEXAMPLES=	examples.ml

OPTIONS_DEFINE=	DOCS EXAMPLES

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

do-build:
	@(cd ${BUILD_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		ocaml pkg/pkg.ml build --tests true --jobs ${MAKE_JOBS_NUMBER})

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		opam-installer -i \
		--prefix=${STAGEDIR}${PREFIX} \
		--docdir=${OCAML_DOCSDIR:S,^${PREFIX}/,,} \
		--libdir=${OCAML_SITELIBDIR} ${PORTNAME}.install)

do-install-EXAMPLES-off:
	${RM} ${STAGEDIR}${DOCSDIR}/min_clock.ml

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${MV} ${STAGEDIR}${DOCSDIR}/min_clock.ml ${STAGEDIR}${EXAMPLESDIR}/examples.ml

post-install:
	@${INSTALL_LIB} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/stublibs/dllmtime_clock_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/dllmtime_clock_stubs.so
	@${RM} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/stublibs/dllmtime_clock_stubs.so
	@${RMDIR} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/stublibs
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/mtime.cmxs
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/clock/os/mtime_clock.cmxs
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/top/mtime_top.cmxs

.include <bsd.port.mk>
