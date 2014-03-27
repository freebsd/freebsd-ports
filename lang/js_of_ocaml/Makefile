# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	js_of_ocaml
PORTVERSION=	1.3.2
CATEGORIES=	lang
MASTER_SITES=	http://ocsigen.org/download/

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	OCaml to JavaScript compiler

BUILD_DEPENDS=	ocaml-lwt>=2.3.0:${PORTSDIR}/devel/ocaml-lwt \
		${SA_DIR}/deriving-ocsigen/deriving.a:${PORTSDIR}/devel/ocaml-deriving-ocsigen
RUN_DEPENDS=	ocaml-lwt>=2.3.0:${PORTSDIR}/devel/ocaml-lwt \
		${SA_DIR}/deriving-ocsigen/deriving.a:${PORTSDIR}/devel/ocaml-deriving-ocsigen

SA_DIR=		${PREFIX}/${OCAML_SITELIBDIR}

USES=			gmake
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAMLFIND_PLIST=	yes

PLIST_FILES+=		bin/js_of_ocaml

MAKE_ENV+=		BINDIR=${STAGEDIR}${PREFIX}/bin \
			DESTDIR=${STAGEDIR} \
			OCAML_SITELIBDIR=${PREFIX}/lib/ocaml/site-lib

.include <bsd.port.mk>
