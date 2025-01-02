PORTNAME=	cppo
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.9
PORTREVISION=	3
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	C-style preprocessor for OCaml
WWW=		https://github.com/ocaml-community/cppo

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	dune:devel/ocaml-dune \
		ocamlbuild:devel/ocaml-ocamlbuild

USES=		ocaml
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml-community

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cppo
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocaml/cppo_ocamlbuild/cppo_ocamlbuild.cmxs

.include <bsd.port.mk>
