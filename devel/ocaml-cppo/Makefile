PORTNAME=	cppo
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.9
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	C-style preprocessor for OCaml

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	dune:devel/ocaml-dune \
		ocamlbuild:devel/ocaml-ocamlbuild

USE_GITHUB=	yes
GH_ACCOUNT=	ocaml-community
USE_OCAML=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cppo
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib:${PREFIX}/lib/ocaml/cppo_ocamlbuild/cppo_ocamlbuild.cmxs

.include <bsd.port.mk>
