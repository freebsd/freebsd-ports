PORTNAME=	ott
PORTVERSION=	0.28
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	domagoj.stolfa@cl.cam.ac.uk
COMMENT=	Tool for writing definitions of programming languages and calculi
WWW=		https://github.com/ott-lang/ott

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
