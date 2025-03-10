PORTNAME=	ounit
DISTVERSION=	2.2.7
CATEGORIES=	devel
MASTER_SITES=	https://github.com/gildor478/${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	OCaml unit test framework
WWW=		https://gildor478.github.io/ounit

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		ocaml:dune tar:tbz
OCAML_PACKAGES=	ounit2
DUNE_INSTALL_TARGETS=	${OCAML_PACKAGES}

DOCSDIR=	${OCAML_DOCSDIR}
PORTDOCS=	${OCAML_PACKAGES:@p@\
		$p/CHANGES.md $p/LICENSE.txt $p/README.md $p/odoc-pages/index.mld@}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "s/^(version v${DISTVERSION})/(version ${DISTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ounit2/advanced/oUnitAdvanced.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ounit2/oUnit.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/ounit2/threads/oUnitThreads.cmxs

do-test:
	@(cd ${TEST_WRKSRC} && \
		${SETENVI} ${WRK_ENV} ${TEST_ENV} ${DUNE_ENV} ${DUNE_CMD} build ${DUNE_ARGS} @runtest)

.include <bsd.port.mk>
