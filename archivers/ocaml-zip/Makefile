PORTNAME=	zip
PORTVERSION=	1.11
PORTREVISION=	3
CATEGORIES=	archivers
PKGNAMEPREFIX=	ocaml-
DISTNAME=	caml${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	OCaml library to manipulate ZIP/GZIP/JAR archives
WWW=		https://github.com/xavierleroy/camlzip

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake ocaml:findlib,ldconfig,wash
USE_GITHUB=	yes
GH_ACCOUNT=	xavierleroy
GH_PROJECT=	camlzip
GH_TAGNAME=	rel${PORTVERSION:S/.//}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib/zip/zip.cmxs \
		${STAGEDIR}${PREFIX}/lib/ocaml/site-lib/zip/dllcamlzip.so

.include <bsd.port.mk>
