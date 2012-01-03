# New ports collection makefile for: ocaml-react
# Date created: April 18, 2011
# Whom: Jaap Boender <jaapb@kerguelen.org>
#
# $FreeBSD$

PORTNAME=	react
PORTVERSION=	0.9.2
CATEGORIES=	devel
MASTER_SITES=	http://erratique.ch/software/react/releases/
PKGNAMEPREFIX=	ocaml-
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	OCaml module for functional reactive programming

USE_OCAML=		yes
OCAMLC_DEPEND=		ocaml>=3.11:${OCAMLC_PORT}
USE_OCAML_LDCONFIG=	yes

.include <bsd.port.pre.mk>

do-build:
	@cd ${WRKSRC} && ${SH} ./build

do-install:
	@cd ${WRKSRC} && INSTALLDIR=${PREFIX}/lib/ocaml/site-lib/${PORTNAME} ${SH} ./build install-plugin

pre-install:
# For nonstandard prefixes
.if !exists(${OCAMLFIND_DESTDIR})
	${MKDIR} ${OCAMLFIND_DESTDIR}
.endif
.if !exists(${OCAMLFIND_LDCONF})
	${TOUCH} ${OCAMLFIND_LDCONF}
.endif

.include <bsd.port.post.mk>
