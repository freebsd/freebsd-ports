# New ports collection makefile for:	Objective Caml
# Date created:		24 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	ocaml
PORTVERSION=	3.06
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/distrib/${DISTNAME}/ \
		ftp://ftp.inria.fr/lang/caml-light/${DISTNAME}/ \
		ftp://ftp.kurims.kyoto-u.ac.jp/pub/lang/caml-light/${DISTNAME}/
PKGNAMESUFFIX=	${TKSFX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DOCFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-refman.html${EXTRACT_SUFX}

MAINTAINER=	patrick@watson.org

.if defined(WITHOUT_TK)
PLIST_SUB+=	TK="@comment "
TKSFX=		-notk
.else
PLIST_SUB+=	TK=""
BUILD_DEPENDS+=	${LOCALBASE}/include/tcl8.3:${PORTSDIR}/lang/tcl83
BUILD_DEPENDS+=	${LOCALBASE}/include/tk8.3:${PORTSDIR}/x11-toolkits/tk83
LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83
.endif

USE_XLIB=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=	world.opt

.if ${MACHINE_ARCH} != "i386"
PLIST_SUB+=	PROF="@comment "
.else
PLIST_SUB+=	PROF=""
.endif

MAN1=		ocamlcp.1 ocamldep.1 ocamldebug.1 ocamlopt.1 ocamlrun.1 \
		ocamlyacc.1 ocamlmktop.1 ocaml.1 ocamlc.1 ocamllex.1 \
		ocamlprof.1 camlp4.1
MANN=		Arg.n Array.n ArrayLabels.n Bigarray.Array1.n \
		Bigarray.Array2.n Bigarray.Array3.n Bigarray.Genarray.n \
		Bigarray.n Buffer.n Callback.n CamlinternalOO.n Char.n \
		Complex.n Digest.n Filename.n Format.n Gc.n Genlex.n \
		Hashtbl.HashedType.n Hashtbl.Make.n Hashtbl.S.n Hashtbl.n \
		Int32.n Int64.n Lazy.n Lexing.n List.n ListLabels.n \
		Map.Make.n Map.OrderedType.n Map.S.n Map.n Marshal.n \
		MoreLabels.Hashtbl.HashedType.n MoreLabels.Hashtbl.Make.n \
		MoreLabels.Hashtbl.S.n MoreLabels.Hashtbl.n \
		MoreLabels.Map.Make.n MoreLabels.Map.OrderedType.n \
		MoreLabels.Map.S.n MoreLabels.Map.n MoreLabels.Set.Make.n \
		MoreLabels.Set.OrderedType.n MoreLabels.Set.S.n \
		MoreLabels.Set.n MoreLabels.n Nativeint.n Num.n Obj.n Oo.n \
		Parsing.n Pervasives.LargeFile.n Pervasives.n Printexc.n \
		Printf.n Queue.n Random.n Scanf.Scanning.n Scanf.n Set.Make.n \
		Set.OrderedType.n Set.S.n Set.n Sort.n Stack.n \
		StdLabels.Array.n StdLabels.List.n StdLabels.String.n \
		StdLabels.n Str.n Stream.n String.n StringLabels.n Sys.n \
		Unix.LargeFile.n Unix.n Weak.Make.n Weak.S.n Weak.n
MLINKS=		ocamlc.1 ocamlc.opt.1 ocamlopt.1 ocamlopt.opt.1 \
		camlp4.1 camlp4o.1 camlp4.1 camlp4r.1 camlp4.1 mkcamlp4.1 \
		camlp4.1 camlp4o.opt.1 camlp4.1 camlp4r.opt.1 \
		camlp4.1 ocpp.1

CONFIGURE_ARGS=	-prefix ${PREFIX} \
		-x11include ${X11BASE}/include \
		-x11lib ${X11BASE}/lib \
		-with-pthread

.if defined(WITHOUT_TK)
CONFIGURE_ARGS+=-no-tk
.else
CONFIGURE_ARGS+=-tkdefs "-I${PREFIX}/include/tcl8.3 -I${PREFIX}/include/tk8.3"
.endif

.if !defined(NOPORTDOCS)
DOCFILES=	${DISTNAME}-refman.html.tar.gz ${DISTNAME}-refman.ps.gz \
		${DISTNAME}-refman.pdf
.endif

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	@${MKDIR} ${DOCSDIR}/html/libref
	@cd ${WRKDIR}/htmlman/libref; ${INSTALL_DATA} * ${DOCSDIR}/html/libref
	@cd ${WRKDIR}/htmlman; ${INSTALL_DATA} [a-km-z]* libg* ${DOCSDIR}/html
	@${INSTALL_DATA} ${DISTDIR}/${DISTNAME}-refman.ps.gz ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${DISTNAME}-refman.pdf ${DOCSDIR}
.endif
.if !defined(WITHOUT_TK)
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/labltk
	@${MKDIR} ${EXAMPLESDIR}/camltk
	@${MKDIR} ${EXAMPLESDIR}/camltk/images
	@cd ${WRKSRC}/otherlibs/labltk/examples_labltk; \
		${INSTALL_DATA} * ${EXAMPLESDIR}/labltk
	@cd ${WRKSRC}/otherlibs/labltk/examples_camltk/images; \
		${INSTALL_DATA} * ${EXAMPLESDIR}/camltk/images
	@cd ${WRKSRC}/otherlibs/labltk/examples_camltk; \
		${INSTALL_DATA} [A-Za-hj-z]* ${EXAMPLESDIR}/camltk
.endif
	@strip ${PREFIX}/bin/ocamlrun ${PREFIX}/bin/ocamlyacc

.include <bsd.port.mk>
