# New ports collection makefile for:	Objective Caml
# Date created:		24 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	ocaml
PORTVERSION=	3.02
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/distrib/ \
		ftp://ftp.inria.fr/lang/caml-light/ \
		ftp://ftp.kurims.kyoto-u.ac.jp/pub/lang/caml-light/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DOCFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-refman.html${EXTRACT_SUFX}

MAINTAINER=	patrick@watson.org

WITH_TK=        yes

.if defined(WITH_TK)
PLIST_SUB+=	LABLTK:=""
BUILD_DEPENDS+=	${LOCALBASE}/include/tcl8.3:${PORTSDIR}/lang/tcl83
BUILD_DEPENDS+=	${LOCALBASE}/include/tk8.3:${PORTSDIR}/x11-toolkits/tk83
LIB_DEPENDS=	tk83.1:${PORTSDIR}/x11-toolkits/tk83
.else
PLIST_SUB+=	LABLTK:="@comment "
.endif

USE_XLIB=	yes
HAS_CONFIGURE=	yes
ALL_TARGET=	world opt opt.opt

.if ${MACHINE_ARCH} != "i386"
PLIST_SUB+=	PROF:="@comment "
.else
PLIST_SUB+=	PROF:=""
.endif

MAN1=		ocamlcp.1 ocamldep.1 ocamldebug.1 ocamlopt.1 ocamlc.opt.1 \
		ocamlrun.1 ocamlyacc.1 ocamlmktop.1 ocamlopt.opt.1 \
		ocaml.1 ocamlc.1 ocamllex.1 ocamlprof.1

CONFIGURE_ARGS=	-prefix ${PREFIX} \
		-x11include ${X11BASE}/include \
		-x11lib ${X11BASE}/lib \
		-with-pthread

.if defined(WITH_TK)
CONFIGURE_ARGS+=	-tkdefs "-I${PREFIX}/include/tcl8.3 -I${PREFIX}/include/tk8.3"
.endif

.if !defined(NOPORTDOCS)
DOCFILES=	${DISTNAME}-refman.html.tar.gz ${DISTNAME}-refman.ps.gz
.endif

post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	@cd ${WRKDIR}/htmlman; ${INSTALL_DATA} * ${DOCSDIR}/html
	@${CP} ${DISTDIR}/${DISTNAME}-refman.ps.gz ${DOCSDIR}
.endif
.if defined(WITH_TK)
	@${MKDIR} ${PREFIX}/share/examples/ocaml
	@${MKDIR} ${PREFIX}/share/examples/ocaml/labltk
	@cd ${WRKSRC}/otherlibs/labltk/example; ${INSTALL_DATA} * ${PREFIX}/share/examples/ocaml/labltk
.endif
	@strip ${PREFIX}/bin/ocamlrun ${PREFIX}/bin/ocamlyacc

.include <bsd.port.mk>
