PORTNAME=	ppx-tools
PORTVERSION=	5.1
DISTVERSIONSUFFIX=+4.06.0
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	michipili@gmail.com
COMMENT=	Tools for authors of ppx rewriters

LICENSE=	MIT

USES=		gmake
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
MAKE_JOBS_UNSAFE=yes
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml-ppx
GH_PROJECT=	${PORTNAME:C/-/_/}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib/ppx_tools/ppx_tools.cmxs

.include <bsd.port.mk>
