PORTNAME=	gen
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Iterators library for OCaml
WWW=		https://github.com/c-cube/gen

LICENSE=	BSD2CLAUSE

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	c-cube

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGELOG.md LICENSE README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(libraries seq)//" \
		${WRKSRC}/src/dune

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/gen/gen.cmxs

.include <bsd.port.mk>
