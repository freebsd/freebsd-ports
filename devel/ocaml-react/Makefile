# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	react
PORTVERSION=	1.2.0
CATEGORIES=	devel
MASTER_SITES=	http://erratique.ch/software/react/releases/
PKGNAMEPREFIX=	ocaml-
EXTRACT_SUFX=	.tbz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml module for functional reactive programming

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=	X11

USE_OCAML=		yes

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MX11)
OCAMLC_DEPEND=		ocaml-notk>=3.11:${OCAMLC_PORT}
.else
OCAMLC_DEPEND=		ocaml>=3.11:${OCAMLC_PORT}
.endif

USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_LDCONFIG=	yes

do-build:
	cd ${WRKSRC} && ocamlbuild react.cmxs react.cma react.a

do-install:
	${MKDIR} ${STAGEDIR}${OCAMLFIND_DESTDIR}/react
	cd ${WRKSRC} && ocamlfind install -destdir ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib react pkg/META _build/src/react.a _build/src/react.cma _build/src/react.cmi _build/src/react.cmx _build/src/react.cmxa _build/src/react.cmxs _build/src/react.mli
	${INSTALL_LIB} ${WRKSRC}/_build/src/react.cmxs \
		${STAGEDIR}${OCAMLFIND_DESTDIR}/react

.include <bsd.port.mk>
