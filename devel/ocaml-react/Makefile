# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	react
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://erratique.ch/software/react/releases/
PKGNAMEPREFIX=	ocaml-
EXTRACT_SUFX=	.tbz

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	OCaml module for functional reactive programming

USE_OCAML=		yes
.if defined (WITHOUT_X11)
OCAMLC_DEPEND=		ocaml-notk>=3.11:${OCAMLC_PORT}
.else
OCAMLC_DEPEND=		ocaml>=3.11:${OCAMLC_PORT}
.endif

USE_OCAML_LDCONFIG=	yes

NO_STAGE=	yes
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
