# New ports collection makefile for:	Objective Caml
# Date created:		24 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	ocaml
PORTVERSION=	3.04
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/distrib/ \
		ftp://ftp.inria.fr/lang/caml-light/ \
		ftp://ftp.kurims.kyoto-u.ac.jp/pub/lang/caml-light/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DOCFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-refman.html${EXTRACT_SUFX}

MAINTAINER=	patrick@watson.org

.if defined(WITHOUT_TK)
PLIST_SUB+=	LABLTK:="@comment "
.else
PLIST_SUB+=	LABLTK:=""
BUILD_DEPENDS+=	${LOCALBASE}/include/tcl8.3:${PORTSDIR}/lang/tcl83
BUILD_DEPENDS+=	${LOCALBASE}/include/tk8.3:${PORTSDIR}/x11-toolkits/tk83
LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83
.endif

USE_XLIB=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=	world opt opt.opt

.if ${MACHINE_ARCH} != "i386"
PLIST_SUB+=	PROF:="@comment "
.else
PLIST_SUB+=	PROF:=""
.endif

MAN1=		ocamlcp.1 ocamldep.1 ocamldebug.1 ocamlopt.1 ocamlrun.1 \
		ocamlyacc.1 ocamlmktop.1 ocaml.1 ocamlc.1 ocamllex.1 \
		ocamlprof.1 camlp4.1
MLINKS=		ocamlc.1 ocamlc.opt.1 ocamlopt.1 ocamlopt.opt.1 \
		camlp4.1 camlp4o.1 camlp4.1 camlp4r.1 camlp4.1 mkcamlp4.1 \
		camlp4.1 camlp4o.opt.1 camlp4.1 camlp4r.opt.1 \
		camlp4.1 ocpp.1

CONFIGURE_ARGS=	-prefix ${PREFIX} \
		-x11include ${X11BASE}/include \
		-x11lib ${X11BASE}/lib \
		-with-pthread

.if !defined(WITHOUT_TK)
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
	@cd ${WRKSRC}/otherlibs/labltk/example; \
		${INSTALL_DATA} * ${EXAMPLESDIR}/labltk
.endif
	@strip ${PREFIX}/bin/ocamlrun ${PREFIX}/bin/ocamlyacc

.include <bsd.port.mk>
