# New ports collection makefile for:	Objective Caml
# Version required:	1.07
# Date created:		24 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id: Makefile,v 1.2 1997/11/18 12:31:08 tg Exp $
#

DISTNAME=	ocaml-1.07
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.kurims.kyoto-u.ac.jp/pub/lang/caml-light/ \
		ftp://ftp.inria.fr/lang/caml-light/
DISTFILES=	${DISTNAME}.tar.gz ${DOCFILES}

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	world bootstrap opt
MAN1=		ocaml.1 ocamlc.1 ocamlcp.1 ocamldep.1 ocamllex.1 \
		ocamlopt.1 ocamlprof.1 ocamlrun.1 ocamlyacc.1

CONFIGURE_ENV=	PREFIX=${PREFIX} X11BASE=${X11BASE} BATCH=${BATCH}

.if !defined(NOPORTDOCS)
DOCFILES=	${DISTNAME}-refman.html.tar.gz
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ocaml/html
	@cd ${WRKDIR}/htmlman; ${INSTALL_DATA} * ${PREFIX}/share/doc/ocaml/html
.endif
	@strip ${PREFIX}/bin/ocamlrun ${PREFIX}/bin/ocamlyacc

.include <bsd.port.mk>
