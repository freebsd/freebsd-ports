# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	js_of_ocaml
PORTVERSION=	2.5
CATEGORIES=	lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml to JavaScript compiler

BUILD_DEPENDS=	ocaml-lwt>=2.3.0:devel/ocaml-lwt \
		menhir:devel/menhir \
		${SA_DIR}/deriving-ocsigen/deriving.a:devel/ocaml-deriving-ocsigen \
		${SA_DIR}/cmdliner/cmdliner.a:devel/ocaml-cmdliner
RUN_DEPENDS=	ocaml-lwt>=2.3.0:devel/ocaml-lwt \
		${SA_DIR}/deriving-ocsigen/deriving.a:devel/ocaml-deriving-ocsigen \
		${SA_DIR}/cmdliner/cmdliner.a:devel/ocaml-cmdliner

SA_DIR=		${PREFIX}/${OCAML_SITELIBDIR}

USES=			gmake
USE_OCAML=		yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAMLFIND_PLIST=	yes

USE_GITHUB=		yes
GH_ACCOUNT=		ocsigen

PLIST_FILES+=		bin/js_of_ocaml bin/jsoo_minify bin/jsoo_mkcmis \
			bin/jsoo_mktop

MAKE_JOBS_UNSAFE=	yes
MAKE_ENV+=		BINDIR=${STAGEDIR}${PREFIX}/bin \
			DESTDIR=${STAGEDIR} \
			OCAML_SITELIBDIR=${PREFIX}/lib/ocaml/site-lib

post-patch:
	@${REINPLACE_CMD} -e '/^BINDIR/d' ${WRKSRC}/Makefile.conf

.include <bsd.port.mk>
