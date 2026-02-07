PORTNAME=	react
PORTVERSION=	1.2.2
CATEGORIES=	devel
MASTER_SITES=	http://erratique.ch/software/react/releases/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml module for functional reactive programming
WWW=		https://erratique.ch/software/react

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild
RUN_DEPENDS=	cppo:devel/ocaml-cppo

USES=		ocaml:findplist,ldconfig tar:tbz

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

do-build:
	cd ${WRKSRC} && ocamlbuild react.cmxs react.cma react.a

do-install:
	${MKDIR} ${STAGEDIR}${OCAMLFIND_DESTDIR}/react
	cd ${WRKSRC} && ocamlfind install -destdir ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib react pkg/META _build/src/react.a _build/src/react.cma _build/src/react.cmi _build/src/react.cmx _build/src/react.cmxa _build/src/react.cmxs _build/src/react.mli
	${INSTALL_LIB} ${WRKSRC}/_build/src/react.cmxs \
		${STAGEDIR}${OCAMLFIND_DESTDIR}/react

.include <bsd.port.mk>
