PORTNAME=	zip
PORTVERSION=	1.11
CATEGORIES=	archivers
PKGNAMEPREFIX=	ocaml-
DISTNAME=	caml${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	OCaml library to manipulate ZIP/GZIP/JAR archives

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	xavierleroy
GH_PROJECT=	camlzip
GH_TAGNAME=	rel${PORTVERSION:S/.//}

USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAML_LDCONFIG=yes
USE_OCAML_WASH=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib/zip/zip.cmxs \
		${STAGEDIR}${PREFIX}/lib/ocaml/site-lib/zip/dllcamlzip.so

.include <bsd.port.mk>
