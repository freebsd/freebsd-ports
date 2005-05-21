# New ports collection makefile for:	ocaml
# Date created:		24 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	ocaml
PORTVERSION=	3.08.3
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/distrib/${DISTNAME:R}/ \
		ftp://ftp.inria.fr/INRIA/caml-light/${DISTNAME:R}/ \
		ftp://ftp.kurims.kyoto-u.ac.jp/pub/lang/caml-light/${DISTNAME:R}/
PKGNAMESUFFIX=	${SFX}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	The Objective Caml compiler and programming environment

.if defined(WITHOUT_X11)
PLIST_SUB+=	X11="@comment " TK="@comment "
WITHOUT_TK=	yes
SFX=		-nox11
CONFLICTS=	ocaml-[0-9]* ocaml-notk-*
.else
PLIST_SUB+=	X11=""
USE_XLIB=	yes
.if defined(WITHOUT_TK)
PLIST_SUB+=	TK="@comment "
SFX=		-notk
CONFLICTS=	ocaml-[0-9]* ocaml-nox11-*
.else
PLIST_SUB+=	TK=""
CONFLICTS=	ocaml-nox11-* ocaml-notk-*

BUILD_DEPENDS+=	${LOCALBASE}/include/tcl8.4:${PORTSDIR}/lang/tcl84 \
		${LOCALBASE}/include/tk8.4:${PORTSDIR}/x11-toolkits/tk84
LIB_DEPENDS+=	tk84.1:${PORTSDIR}/x11-toolkits/tk84
.endif
.endif

USE_BZIP2=	yes
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=	world.opt
STRIP=

MAN1=		ocamlcp.1 ocamldep.1 ocamldebug.1 ocamldoc.1 ocamlopt.1 \
		ocamlrun.1 ocamlyacc.1 ocamlmktop.1 ocaml.1 ocamlc.1 \
		ocamllex.1 ocamlprof.1 camlp4.1
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
		Printf.n Queue.n Random.n Random.State.n Scanf.Scanning.n \
		Scanf.n Set.Make.n Set.OrderedType.n Set.S.n Set.n Sort.n \
		Stack.n StdLabels.Array.n StdLabels.List.n StdLabels.String.n \
		StdLabels.n Str.n Stream.n String.n StringLabels.n Sys.n \
		Unix.LargeFile.n Unix.n Weak.Make.n Weak.S.n Weak.n
MLINKS=		ocamlc.1 ocamlc.opt.1 ocamlopt.1 ocamlopt.opt.1 \
		camlp4.1 camlp4o.1 camlp4.1 camlp4r.1 camlp4.1 mkcamlp4.1 \
		camlp4.1 camlp4o.opt.1 camlp4.1 camlp4r.opt.1 \
		camlp4.1 ocpp.1

CONFIGURE_ARGS=	-prefix ${PREFIX} -with-pthread

.if !defined(WITHOUT_X11)
CONFIGURE_ARGS+=	-x11include ${X11BASE}/include -x11lib ${X11BASE}/lib
.if defined(WITHOUT_TK)
CONFIGURE_ARGS+=	-no-tk
.else
CONFIGURE_ARGS+=	-tkdefs "-I${LOCALBASE}/include/tcl8.4 -I${LOCALBASE}/include/tk8.4"
.endif
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
PLIST_SUB+=	PROF="@comment "
.else
PLIST_SUB+=	PROF=""
.endif

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

post-configure:
# CFLAGS safeness
	@${REINPLACE_CMD} -E \
		-e 's|(BYTECCCOMPOPTS[[:space:]]*=.*)|\1 ${CFLAGS}|' \
		-e 's|(NATIVECCCOMPOPTS[[:space:]]*=.*)|\1 ${CFLAGS}|' \
		${WRKSRC}/config/Makefile
# INSTALL* safeness (which preserves the correct permissions despite
# user's umask(1)
	@${FIND} ${WRKDIR} -type f -name Makefile -print0 | \
		${XARGS} -0 -n 5 -x \
		${REINPLACE_CMD} -E \
		-e 's,^([[:space:]]*(then)?[[:space:]]*)cp([[:space:]]+.*BINDIR),\1\$${BSD_INSTALL_PROGRAM} \3,' \
		-e 's,^([[:space:]]*(then)?[[:space:]]*)cp([[:space:]]+.*LIBDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,^([[:space:]]*(then)?[[:space:]]*)cp([[:space:]]+.*INSTALLDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,^([[:space:]]*(then)?[[:space:]]*)\$$\(CP\)([[:space:]]+.*BINDIR),\1\$${BSD_INSTALL_PROGRAM} \3,' \
		-e 's,^([[:space:]]*(then)?[[:space:]]*)\$$\(CP\)([[:space:]]+.*LIBDIR),\1\$${BSD_INSTALL_DATA} \3,' \
		-e 's,^([[:space:]]*(then)?[[:space:]]*)(\$$\(CP\)|cp)([[:space:]]+.*(MANDIR|MANODIR|MANEXT)),\1\$${BSD_INSTALL_MAN} \4,' \
		-e 's,([[:space:]]*then[[:space:]]*)cp([[:space:]]+.*LIBDIR),\1\$${BSD_INSTALL_DATA} \2,' \
		-e 's,([[:space:]]*then[[:space:]]*)cp([[:space:]]+.*BINDIR),\1\$${BSD_INSTALL_PROGRAM} \2,' \
		-e 's,([[:space:]]*(do|then)[[:space:]]*)(\$$\(CP\)|cp)([[:space:]]+.*(MANDIR|MANODIR|MANEXT)),\1\$${BSD_INSTALL_MAN} \4,'
	@${FIND} ${WRKDIR} -type f -name Makefile.bak -delete

post-install:
	@${TOUCH} ${PREFIX}/lib/ocaml/ocamldoc/custom/.keep
.if !defined(WITHOUT_TK)
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/labltk
	@${MKDIR} ${EXAMPLESDIR}/camltk
	@${MKDIR} ${EXAMPLESDIR}/camltk/images
	@cd ${WRKSRC}/otherlibs/labltk/examples_labltk; \
		${INSTALL_DATA} * ${EXAMPLESDIR}/labltk
	@${CP} -r ${WRKSRC}/otherlibs/labltk/examples_camltk/* \
		${EXAMPLESDIR}/camltk
.endif
.for prog in camlp4o.opt camlp4r.opt ocamlc.opt ocamldep.opt ocamldoc.opt \
		ocamllex.opt ocamlopt.opt ocamlrun ocamlyacc
	@${STRIP_CMD} ${PREFIX}/bin/${prog}
.endfor
# XXX ugly hack to fix permissions.
	@${FIND} ${EXAMPLESDIR} -type f -print0 | \
		${XARGS} -0 -n 5 -x \
		${CHMOD} ${SHAREMODE}
	@${CHMOD} u+w ${PREFIX}/lib/ocaml/ld.conf
		
.include <bsd.port.post.mk>
