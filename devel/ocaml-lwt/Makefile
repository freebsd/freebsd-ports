PORTNAME=	lwt
PORTVERSION=	5.7.0
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Cooperative threading library for OCaml

LICENSE=	LGPL21

BUILD_DEPENDS=	${SA_DIR}/ocplib-endian/META:devel/ocaml-ocplib-endian \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib \
		${SA_DIR}/react/react.a:devel/ocaml-react
BUILD_DEPENDS+=	cppo:devel/ocaml-cppo
RUN_DEPENDS=	${SA_DIR}/ocplib-endian/META:devel/ocaml-ocplib-endian \
		${SA_DIR}/ppxlib/META:devel/ocaml-ppxlib \
		${SA_DIR}/react/react.a:devel/ocaml-react
LIB_DEPENDS=	libev.so:devel/libev

USE_GITHUB=	yes
GH_ACCOUNT=	ocsigen

USES=			ocaml:dune
USE_OCAML=		yes
OCAML_PACKAGES=		lwt lwt_ppx lwt_ppx_let lwt_react
USE_OCAML_LDCONFIG=	yes

DOCSDIR=	${OCAML_DOCSDIR}
PORTDOCS=	lwt/CHANGES lwt/LICENSE.md lwt/README.md lwt/odoc-pages \
		lwt_ppx/CHANGES lwt_ppx/LICENSE.md lwt_ppx/README.md \
		lwt_ppx_let/CHANGES lwt_ppx_let/LICENSE.md lwt_ppx_let/README.md \
		lwt_react/CHANGES lwt_react/LICENSE.md lwt_react/README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

do-configure:
	@(cd ${WRKSRC}; \
	${SETENVI} ${WRK_ENV} ${SCRIPT_ENV} ${DUNE_CMD} exec \
		--display=short --always-show-command-line \
		--no-config -j ${MAKE_JOBS_NUMBER} --profile release \
		--root=${DUNE_ROOT} --build-dir=${DUNE_BUILD_DIR} \
		--promote-install-files --ignore-promoted-rules \
		--default-target @install --require-dune-project-file \
		--only-packages=lwt \
		src/unix/config/discover.exe -- --save --use-libev true --libev-default true)

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lwt/dlllwt_unix_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lwt/lwt.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lwt/unix/lwt_unix.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lwt_ppx/ppx.exe \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lwt_ppx/ppx_lwt.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/lwt_react/lwt_react.cmxs

.include <bsd.port.mk>
