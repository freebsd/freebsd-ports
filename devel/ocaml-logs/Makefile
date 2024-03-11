PORTNAME=	logs
PORTVERSION=	0.7.0
CATEGORIES=	devel
MASTER_SITES=	https://erratique.ch/software/logs/releases/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Logging library for Objective Caml
WWW=		https://erratique.ch/software/logs

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/cmdliner/META:devel/ocaml-cmdliner \
		${SA_DIR}/fmt/META:devel/ocaml-fmt \
		${SA_DIR}/lwt/META:devel/ocaml-lwt \
		${SA_DIR}/mtime/META:devel/ocaml-mtime \
		${SA_DIR}/topkg/META:devel/ocaml-topkg \
		ocamlbuild:devel/ocaml-ocamlbuild \
		opam-installer:devel/ocaml-opam
RUN_DEPENDS=	${SA_DIR}/cmdliner/META:devel/ocaml-cmdliner \
		${SA_DIR}/fmt/META:devel/ocaml-fmt \
		${SA_DIR}/lwt/META:devel/ocaml-lwt

USES=		tar:tbz
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md tags.ml tool.ml

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

do-build:
	cd ${BUILD_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		ocaml pkg/pkg.ml build \
		--jobs ${MAKE_JOBS_NUMBER} --with-js_of_ocaml 'false'

do-install:
	cd ${INSTALL_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		opam-installer -i \
		--prefix=${STAGEDIR}${PREFIX} \
		--docdir=${OCAML_DOCSDIR:S,^${PREFIX}/,,} \
		--libdir=${OCAML_SITELIBDIR} ${PORTNAME}.install

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/logs.cmxs
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/logs_cli.cmxs
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/logs_fmt.cmxs
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/logs_lwt.cmxs
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/logs_top.cmxs
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/logs_threaded.cmxs

.include <bsd.port.mk>
