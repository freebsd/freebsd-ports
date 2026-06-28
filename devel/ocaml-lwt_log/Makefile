PORTNAME=	lwt_log
DISTVERSION=	1.1.2
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Asynchronous logging library for OCaml
WWW=		https://github.com/ocsigen/lwt_log

LICENSE=	LGPL21+ # with a special exception to clause 6
# TODO BSD3CLAUSE

BUILD_DEPENDS=	${SA_DIR}/lwt/META:devel/ocaml-lwt
RUN_DEPENDS=	${SA_DIR}/lwt/META:devel/ocaml-lwt

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	ocsigen

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(name ${PORTNAME})/&\n(version ${PORTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/core/lwt_log_core.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/lwt_log.cmxs

.include <bsd.port.mk>
