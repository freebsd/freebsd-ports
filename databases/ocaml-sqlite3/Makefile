# Created by: "Meikel Brandmeyer" <ocaml-sqlite3-port@kotka.de>
# $FreeBSD$

PORTNAME=	sqlite3
PORTVERSION=	4.0.5
DISTVERSIONPREFIX=	v
CATEGORIES=	databases
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml bindings to sqlite3 library

LICENSE=	OCSQLT3
LICENSE_NAME=	OCaml-SQLite3 unique permissive license
LICENSE_FILE=	${WRKSRC}/COPYING.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild

USES=			compiler:features gmake pkgconfig sqlite
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes
HAS_CONFIGURE=		yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ARGS=		--destdir "${STAGEDIR}" \
			--prefix "${PREFIX}"

GH_ACCOUNT=	mmottl
GH_PROJECT=	${PORTNAME}-ocaml
USE_GITHUB=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,"install" :: findlib_name,"install" :: "-destdir ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /var/null" :: findlib_name,' \
		${WRKSRC}/setup.ml
.if ${COMPILER_TYPE} == gcc & ${COMPILER_VERSION} <= 42
	@${REINPLACE_CMD} -e 's|-Wno-keyword-macro||' ${WRKSRC}/_oasis \
		${WRKSRC}/myocamlbuild.ml ${WRKSRC}/setup.ml
.endif

do-configure:
	(cd ${WRKSRC} && ocaml setup.ml -configure ${CONFIGURE_ARGS})

do-build:
	(cd ${WRKSRC} && ocaml setup.ml -build)

do-install:
	(cd ${WRKSRC} && ocaml setup.ml -install)

.include <bsd.port.post.mk>
