# New ports collection makefile for:	ocamlduce
# Date created:				Feb 24, 2007
# Whom:					Jaap Boender <jaapb@kerguelen.rg>
#
# $FreeBSD$
#

PORTNAME=	ocamlduce
PORTVERSION=	3.10.0.1
CATEGORIES=	lang
MASTER_SITES=	http://gallium.inria.fr/~frisch/ocamlcduce/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	Library to integrate XML features into OCaml

USE_GMAKE=	yes
USE_OCAML=	yes
OCAMLC_DEPEND=	ocaml>=3.10.0:${OCAMLC_PORT}
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
USE_OCAML_PLIST=	yes

ALL_TARGET=	all opt
BROKEN=		does not build with current version of lang/ocaml
DEPRECATED=	has been broken for 7 months
EXPIRATION_DATE=2010-01-08

.include <bsd.port.pre.mk>

post-extract:
# For nonstandard prefixes
.if !exists(${OCAMLFIND_DESTDIR})
	${MKDIR} ${OCAMLFIND_DESTDIR}
.endif
.if !exists(${OCAMLFIND_LDCONF})
	${TOUCH} ${OCAMLFIND_LDCONF}
.endif

.include <bsd.port.post.mk>
