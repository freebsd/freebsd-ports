PORTNAME=	js_of_ocaml-ocamlbuild
DISTVERSION=	5.0
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ocsigen/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Ocamlbuild plugin for Js_of_ocaml
WWW=		https://ocsigen.org/js_of_ocaml

LICENSE=	LGPL21+

BUILD_DEPENDS=	${LOCALBASE}/bin/ocamlbuild:devel/ocaml-ocamlbuild
RUN_DEPENDS=	${LOCALBASE}/bin/ocamlbuild:devel/ocaml-ocamlbuild

USES=		ocaml:dune tar:tbz

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/ocamlbuild_js_of_ocaml.cmxs

.include <bsd.port.mk>
