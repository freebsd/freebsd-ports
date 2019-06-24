# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	uutf
PORTVERSION=	0.9.4
CATEGORIES=	devel
MASTER_SITES=	http://erratique.ch/software/uutf/releases/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Non-blocking streaming Unicode codec for OCaml

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild

USES=	tar:tbz
USE_OCAML=		yes

USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_LDCONFIG=	yes

do-build:
	cd ${WRKSRC} && ocamlbuild uutf.cmxs uutf.cma uutf.a

do-install:
	${MKDIR} ${STAGEDIR}${OCAMLFIND_DESTDIR}/uutf
	cd ${WRKSRC} && ocamlfind install -destdir ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib uutf pkg/META _build/src/uutf.a _build/src/uutf.cma _build/src/uutf.cmi _build/src/uutf.cmx _build/src/uutf.cmxa _build/src/uutf.cmxs _build/src/uutf.mli
	${INSTALL_LIB} ${WRKSRC}/_build/src/uutf.cmxs \
		${STAGEDIR}${OCAMLFIND_DESTDIR}/uutf

.include <bsd.port.mk>
