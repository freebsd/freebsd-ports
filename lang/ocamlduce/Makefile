# New ports collection makefile for:	ocamlduce
# Date created:				Feb 24, 2007
# Whom:					Jaap Boender <jaapb@kerguelen.rg>
#
# $FreeBSD$
#

PORTNAME=	ocamlduce
PORTVERSION=	3.09.3
CATEGORIES=	lang
MASTER_SITES=	http://gallium.inria.fr/~frisch/ocamlcduce/download/
PKGNAMESUFFIX=	pl1
DISTNAME=	${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	Library to integrate XML features into OCaml

USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=yes

ALL_TARGET=	all opt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/ocaml/bsd.ocaml.mk"

post-extract:
# For nonstandard prefixes
.if !exists(${OCAMLFIND_DESTDIR})
	${MKDIR} ${OCAMLFIND_DESTDIR}
.endif
.if !exists(${OCAMLFIND_LDCONF})
	${TOUCH} ${OCAMLFIND_LDCONF}
.endif

.include <bsd.port.post.mk>
