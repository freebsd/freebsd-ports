PORTNAME=	ott
PORTVERSION=	0.28
CATEGORIES=	lang

MAINTAINER=	domagoj.stolfa@cl.cam.ac.uk
COMMENT=	Tool for writing definitions of programming languages and calculi

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=	gmake

ALL_TARGET=	world

USE_GITHUB=	yes
GH_ACCOUNT=	ott-lang

USE_OCAML=	yes

PLIST_FILES=	bin/ott

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ott ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
