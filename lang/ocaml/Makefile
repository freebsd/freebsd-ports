# New ports collection makefile for:	Objective Caml
# Date created:		24 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	ocaml
PORTVERSION=	2.04
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.inria.fr/lang/caml-light/ \
		ftp://ftp.kurims.kyoto-u.ac.jp/pub/lang/caml-light/
DISTFILES=	${PORTNAME}${PORTVERSION}.tar.gz ${DOCFILES}

MAINTAINER=	ortmann@isl.net

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-refman.html${EXTRACT_SUFX}
USE_XLIB=	yes
HAS_CONFIGURE=	yes
#USE_GMAKE=	yes
ALL_TARGET=	world bootstrap opt ocamlc.opt ocamlopt.opt

.if ${MACHINE_ARCH} != "i386"
PLIST=		${PKGDIR}/PLIST.noprof
.endif

MAN1=		ocaml.1 ocamlc.1 ocamlcp.1 ocamldep.1 ocamllex.1 \
		ocamlopt.1 ocamlprof.1 ocamlrun.1 ocamlyacc.1 ocamlmktop.1 \
		ocamlc.opt.1 ocamlopt.opt.1

CONFIGURE_ENV=	PREFIX=${PREFIX} X11BASE=${X11BASE} BATCH=${BATCH}

.if !defined(NOPORTDOCS)
DOCFILES=	${DISTNAME}-refman.html.tar.gz ${DISTNAME}-refman.ps.gz
.endif

post-install:
	@${MKDIR} ${PREFIX}/share/doc/ocaml
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/ocaml/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ocaml/html
	@cd ${WRKDIR}/htmlman; ${INSTALL_DATA} * ${PREFIX}/share/doc/ocaml/html
	@${CP} ${DISTDIR}/${DISTNAME}-refman.ps.gz ${PREFIX}/share/doc/ocaml
.endif
	@strip ${PREFIX}/bin/ocamlrun ${PREFIX}/bin/ocamlyacc

.include <bsd.port.mk>
