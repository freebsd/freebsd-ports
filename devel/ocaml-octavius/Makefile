PORTNAME=	octavius
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.2
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Library to parse ocamldoc comment for OCaml
WWW=		https://ocaml-doc.github.io/octavius/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml-doc

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(lang dune 1.11)/(lang dune 2.5)/" \
		-e "/(lang dune/,/(package/s/(name ${PORTNAME})/&\n(version ${DISTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/bin/octavius \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/${PORTNAME}.cmxs

.include <bsd.port.mk>
