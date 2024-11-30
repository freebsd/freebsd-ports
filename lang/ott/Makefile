PORTNAME=	ott
DISTVERSION=	0.33
CATEGORIES=	lang

MAINTAINER=	domagoj.stolfa@cl.cam.ac.uk
COMMENT=	Tool for writing definitions of programming languages and calculi
WWW=		https://github.com/ott-lang/ott

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

BUILD_DEPENDS=	${OCAMLFIND_DEPEND} \
		ocaml-ocamlgraph>=0:math/ocaml-ocamlgraph

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	ott-lang

USE_OCAML=	yes

ALL_TARGET=	world

PLIST_FILES=	bin/ott

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ott ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
