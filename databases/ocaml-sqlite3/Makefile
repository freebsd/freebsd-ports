PORTNAME=	sqlite3
DISTVERSION=	5.1.0
CATEGORIES=	databases
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	OCaml bindings to sqlite3 library
WWW=		https://mmottl.github.io/sqlite3-ocaml/

LICENSE=	OCSQLT3
LICENSE_NAME=	OCaml-SQLite3 unique permissive license
LICENSE_FILE=	${WRKSRC}/LICENSE.md
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild

USES=		ocaml:dune pkgconfig sqlite
USE_GITHUB=	yes
GH_ACCOUNT=	mmottl
GH_PROJECT=	${PORTNAME}-ocaml

USE_OCAML=	yes
USE_OCAML_LDCONFIG=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/dllsqlite3_stubs.so \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/sqlite3.cmxs

.include <bsd.port.mk>
