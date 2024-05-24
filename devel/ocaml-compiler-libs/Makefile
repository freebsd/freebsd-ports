PORTNAME=	ocaml-compiler-libs
PORTVERSION=	0.12.4
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Wrapper library for OCaml internals
WWW=		https://github.com/janestreet/ocaml-compiler-libs

LICENSE=	MIT

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	janestreet
GH_PROJECT=	ocaml-compiler-libs
USE_OCAML=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.org

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(name ${PORTNAME})/&\n (version ${PORTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/bytecomp/ocaml_bytecomp.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/common/ocaml_common.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/optcomp/ocaml_optcomp.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/shadow/ocaml_shadow.cmxs \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/toplevel/ocaml_toplevel.cmxs

.include <bsd.port.mk>
