PORTNAME=	duration
DISTVERSION=	0.2.1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/hannesm/${PORTNAME}/releases/download/v${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	OCaml library for converting time units
WWW=		https://github.com/hannesm/duration

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		ocaml:dune tar:tbz

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(version v.*)/(version ${DISTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/duration/duration.cmxs

.include <bsd.port.mk>
