# New ports collection makefile for:	mtasc
# Date created:		2008-09-06
# Whom:			Marcin Cieslak <saper@SYSTEM.PL>
#
# $FreeBSD$
#

PORTNAME=	mtasc
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	lang www
MASTER_SITES=	http://saper.info/distfiles/ LOCAL/chinsan

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Motion-Twin ActionScript 2 Compiler

BUILD_DEPENDS=	${LOCALBASE}/lib/ocaml/site-lib/extlib/IO.cmi:${PORTSDIR}/devel/ocaml-extlib

USE_OCAML=	yes
USE_OCAML_FINDLIB=yes

OCAMLLEX?=	${LOCALBASE}/bin/ocamllex
OCAMLOPT?=	${LOCALBASE}/bin/ocamlopt

ZLIB_OPTS=	-cclib "${WRKSRC}/extc/extc_stubs.o" -cclib -lz extc.mli extc.ml
SWFLIB_INC=	-I ${WRKSRC}/extc -I ${WRKSRC}/swflib
SWFLIB_FILES=	as3.mli as3code.ml as3parse.ml swf.ml swfZip.ml actionScript.ml \
		swfParser.ml
MTASC_OBJ=	expr.cmx lexer.cmx parser.cmx typer.cmx class.cmx plugin.cmx\
		genSwf.cmx main.cmx

MAN1=		mtasc.1

WRKSRC=		${WRKDIR}/ocaml

.if !defined(NOPORTDATA)
PORTDATA=	std std8
.endif

.include <bsd.port.pre.mk>

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
	${INSTALL_PROGRAM} ${WRKSRC}/mtasc-bin	${PREFIX}/bin/mtasc
.if !defined(NOPORTDATA)
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC}/mtasc && ${FIND} ${PORTDATA} -type f | ${CPIO} -pdmu ${DATADIR})
	@${FIND} ${DATADIR} -type d -exec ${CHMOD} 555 {} \;
	@${FIND} ${DATADIR} -type f -exec ${CHMOD} 444 {} \;
.endif
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/mtasc/doc/mtasc.1 ${PREFIX}/man/man1
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA}	${WRKSRC}/mtasc/doc/*.txt ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA}	${WRKSRC}/mtasc/doc/HelloWorld.as ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
