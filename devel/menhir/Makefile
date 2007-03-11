# New ports collection makefile for:	menhir
# Date created:				5 March 2007
# Whom:					Jaap Boender <jaapb@kerguelen.org>
#
# $FreeBSD$
#

PORTNAME=	menhir
PORTVERSION=	20070215
CATEGORIES=	devel
MASTER_SITES=	http://cristal.inria.fr/~fpottier/menhir/

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	LR(1) parser generator for OCaml

USE_GMAKE=	yes
USE_OCAML=	yes

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
MAKE_ENV+=	DOCSDIR="${DOCSDIR}" OCAML_SITELIBDIR="${PREFIX}/${OCAML_SITELIBDIR}"

MAN1=		menhir.1

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/ocaml/bsd.ocaml.mk"
.include <bsd.port.post.mk>
