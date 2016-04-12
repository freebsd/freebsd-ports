# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jsonm
PORTVERSION=	0.9.1
CATEGORIES=	converters
MASTER_SITES=	http://erratique.ch/software/jsonm/releases/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Non-blocking streaming JSON codec for OCaml

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${SA_DIR}/uutf/uutf.a:devel/ocaml-uutf
RUN_DEPENDS=	${SA_DIR}/uutf/uutf.a:devel/ocaml-uutf

USES=	tar:tbz
USE_OCAML=		yes
SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_LDCONFIG=	yes

do-build:
	cd ${WRKSRC} && ocamlbuild src/jsonm.cmxs src/jsonm.cma src/jsonm.a

do-install:
	${MKDIR} ${STAGEDIR}${OCAMLFIND_DESTDIR}/jsonm
	cd ${WRKSRC} && ocamlfind install -destdir ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib jsonm src/META _build/src/jsonm.a _build/src/jsonm.cma _build/src/jsonm.cmi _build/src/jsonm.cmx _build/src/jsonm.cmxa _build/src/jsonm.cmxs _build/src/jsonm.mli
	${INSTALL_LIB} ${WRKSRC}/_build/src/jsonm.cmxs \
		${STAGEDIR}${OCAMLFIND_DESTDIR}/jsonm

.include <bsd.port.mk>
