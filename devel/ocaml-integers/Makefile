PORTNAME=	integers
DISTVERSION=	0.8.0
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Integer types for OCaml
WWW=		https://github.com/yallop/ocaml-integers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

TEST_DEPENDS=	${SA_DIR}/ounit2/META:devel/ocaml-ounit

USES=		ocaml:dune,ldconfig

USE_GITHUB=	yes
GH_ACCOUNT=	yallop
GH_PROJECT=	ocaml-${PORTNAME}

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(lang dune 1.0)/(lang dune 3.0)/" \
		-e "s/(name ${PORTNAME})/&\n(version ${DISTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	cd ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME} && \
		${STRIP_CMD} ${PORTNAME}.cmxs dll${PORTNAME}_stubs.so

do-test:
	cd ${TEST_WRKSRC} && \
		${SETENVI} ${TEST_ENV} ${DUNE_ENV} \
		${DUNE_CMD} build ${DUNE_ARGS} @runtest

.include <bsd.port.mk>
