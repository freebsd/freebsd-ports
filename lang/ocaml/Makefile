# New ports collection makefile for:	Objective Caml
# Version required:	1.03
# Date created:		24 December 1996
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $Id$
#

DISTNAME=	ocaml-1.03
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.kurims.kyoto-u.ac.jp/pub/lang/caml-light/ \
		ftp://ftp.inria.fr/lang/caml-light/

MAINTAINER=	kiri@kiri.toba-cmt.ac.jp

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	world bootstrap opt
MAN1=		ocaml.1 ocamlc.1 ocamlcp.1 ocamldep.1 ocamllex.1 \
		ocamlopt.1 ocamlprof.1 ocamlrun.1 ocamlyacc.1 

post-install:
	@strip ${PREFIX}/bin/ocamlrun ${PREFIX}/bin/ocamlyacc

.include <bsd.port.mk>
