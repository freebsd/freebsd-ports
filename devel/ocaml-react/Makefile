# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	react
PORTVERSION=	0.9.4
CATEGORIES=	devel
MASTER_SITES=	http://erratique.ch/software/react/releases/
PKGNAMEPREFIX=	ocaml-
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	OCaml module for functional reactive programming

LICENSE=	BSD3CLAUSE

USE_OCAML=		yes
.if defined (WITHOUT_X11)
OCAMLC_DEPEND=		ocaml-notk>=3.11:${OCAMLC_PORT}
.else
OCAMLC_DEPEND=		ocaml>=3.11:${OCAMLC_PORT}
.endif

USE_OCAML_FINDLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,"install" :: findlib_name,"install" :: "-destdir ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,' \
		${WRKSRC}/setup.ml

do-configure:
	@cd ${WRKSRC} && ocaml setup.ml -configure ${CONFIGURE_ARGS}

do-build:
	(cd ${WRKSRC} && ocaml setup.ml -build)
	(cd ${WRKSRC} && ocamlbuild src/react.cmxs)

do-install:
	${MKDIR} ${STAGEDIR}${OCAMLFIND_DESTDIR}
	(cd ${WRKSRC} && ocaml setup.ml -install)
	${INSTALL_LIB} ${WRKSRC}/_build/src/react.cmxs \
		${STAGEDIR}${OCAMLFIND_DESTDIR}/react

.include <bsd.port.mk>
