# Created by: Marcin Cieslak <saper@SYSTEM.PL>
# $FreeBSD$

PORTNAME=	mtasc
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	lang www
MASTER_SITES=	LOCAL/chinsan

MAINTAINER=	saper@saper.info
COMMENT=	Motion-Twin ActionScript 2 Compiler

BUILD_DEPENDS=	${LOCALBASE}/lib/ocaml/site-lib/extlib/IO.cmi:devel/ocaml-extlib

USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAML_CAMLP4=yes
OCAML_PKGDIRS=	# This port uses ocaml-findlib but doesn't install one

OCAMLLEX?=	${LOCALBASE}/bin/ocamllex
OCAMLOPT?=	${LOCALBASE}/bin/ocamlopt

ZLIB_OPTS=	-cclib "${WRKSRC}/extc/extc_stubs.o" -cclib -lz extc.mli extc.ml
SWFLIB_INC=	-I ${WRKSRC}/extc -I ${WRKSRC}/swflib
SWFLIB_FILES=	as3.mli as3code.ml as3parse.ml swf.ml swfZip.ml actionScript.ml \
		swfParser.ml
MTASC_OBJ=	expr.cmx lexer.cmx parser.cmx typer.cmx class.cmx plugin.cmx\
		genSwf.cmx main.cmx

WRKSRC=		${WRKDIR}/ocaml

PORTDATA=	std std8

OPTIONS_DEFINE=	DOCS EXAMPLES

do-build:
	(cd ${WRKSRC}/extc && \
		${OCAMLOPT} ${WRKSRC}/extc/extc_stubs.c  && \
		${OCAMLOPT} -a -o extc.cmxa ${ZLIB_OPTS} )
	(cd ${WRKSRC}/swflib && \
		${OCAMLFIND} ocamlopt -package extlib \
			-a -o swflib.cmxa ${SWFLIB_INC} ${SWFLIB_FILES} )
	(cd ${WRKSRC}/mtasc && \
		${OCAMLLEX} lexer.mll && \
		${OCAMLOPT} -c expr.ml lexer.ml && \
		${OCAMLOPT} -c -pp camlp4o parser.ml && \
		${OCAMLFIND} ocamlopt -package extlib -c ${SWFLIB_INC} \
			      typer.ml class.ml plugin.ml \
			      genSwf.ml main.ml )
	(cd ${WRKSRC}/mtasc && \
		${OCAMLFIND} ocamlopt -package extlib -linkpkg \
			-o ${WRKSRC}/mtasc-bin \
			${WRKSRC}/extc/extc.cmxa \
			${WRKSRC}/swflib/swflib.cmxa \
			${MTASC_OBJ} )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mtasc-bin ${STAGEDIR}${PREFIX}/bin/mtasc
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/mtasc && ${COPYTREE_SHARE} "${PORTDATA}" ${STAGEDIR}${DATADIR})
	${INSTALL_MAN} ${WRKSRC}/mtasc/doc/mtasc.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/mtasc/doc/*.txt ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/mtasc/doc/HelloWorld.as ${STAGEDIR}${EXAMPLESDIR}
# Remove orphan dir created by bsd.ocaml.mk
	-@${RMDIR} -p ${STAGEDIR}${OCAMLFIND_DESTDIR}

.include <bsd.port.mk>
