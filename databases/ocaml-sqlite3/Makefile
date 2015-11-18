# Created by: "Meikel Brandmeyer" <ocaml-sqlite3-port@kotka.de>
# $FreeBSD$

PORTNAME=	sqlite3
PORTVERSION=	4.0.1
CATEGORIES=	databases
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PORTNAME}-ocaml-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml bindings to sqlite3 library

LICENSE=	OCSQLT3
LICENSE_NAME=	OCaml-SQLite3 unique permissive license
LICENSE_FILE=	${WRKSRC}/COPYING.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=			gmake pkgconfig
USE_SQLITE=		yes
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes
USE_GITHUB=		yes
GH_ACCOUNT=		mmottl
GH_PROJECT=		sqlite3-ocaml
GH_TAGNAME=		8638339
HAS_CONFIGURE=		yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ARGS=		--destdir "${STAGEDIR}" \
			--prefix "${PREFIX}"

post-patch:
	@${REINPLACE_CMD} -e 's,"install" :: findlib_name,"install" :: "-destdir ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /var/null" :: findlib_name,' \
		${WRKSRC}/setup.ml

do-configure:
	(cd ${WRKSRC} && ocaml setup.ml -configure ${CONFIGURE_ARGS})

do-build:
	(cd ${WRKSRC} && ocaml setup.ml -build)

do-install:
	(cd ${WRKSRC} && ocaml setup.ml -install)

.include <bsd.port.mk>
