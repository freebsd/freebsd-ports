PORTNAME=	ppx-tools
PORTVERSION=	6.6
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	michipili@gmail.com
COMMENT=	Tools for authors of ppx rewriters
WWW=		https://github.com/ocaml-ppx/ppx_tools

LICENSE=	MIT

BUILD_DEPENDS=	dune:devel/ocaml-dune \
		cppo:devel/ocaml-cppo

USES=		gmake
ALL_TARGET=	release
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml-ppx
GH_PROJECT=	${PORTNAME:C/-/_/}
DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME:C/-/_/}

PORTDOCS=	CHANGES LICENSE README.md

OPTIONS_DEFINE= DOCS

.include <bsd.port.mk>
