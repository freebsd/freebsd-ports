PORTNAME=	cmdliner
PORTVERSION=	0.9.8
CATEGORIES=	devel
MASTER_SITES=	http://erratique.ch/software/cmdliner/releases/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml module for handling of command line interfaces

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild

USES=			tar:tbz
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_LDCONFIG=	yes

do-build:
	cd ${WRKSRC} && ocamlbuild cmdliner.cmxs cmdliner.cma cmdliner.a

do-install:
	${MKDIR} ${STAGEDIR}${OCAMLFIND_DESTDIR}/cmdliner
	cd ${WRKSRC} && ocamlfind install -destdir ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib cmdliner pkg/META _build/src/cmdliner.a _build/src/cmdliner.cma _build/src/cmdliner.cmi _build/src/cmdliner.cmx _build/src/cmdliner.cmxa _build/src/cmdliner.cmxs _build/src/cmdliner.mli
	${INSTALL_LIB} ${WRKSRC}/_build/src/cmdliner.cmxs \
		${STAGEDIR}${OCAMLFIND_DESTDIR}/cmdliner

.include <bsd.port.mk>
