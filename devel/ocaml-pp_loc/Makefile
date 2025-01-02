PORTNAME=	pp_loc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Library for pretty-printing an error in Objective Caml
WWW=		https://armael.github.io/pp_loc/pp_loc/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	Armael

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES LICENSE README.md

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/${PORTNAME}.cmxs

.include <bsd.port.mk>
