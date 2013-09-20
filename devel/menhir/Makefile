# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	menhir
PORTVERSION=	20080912
CATEGORIES=	devel
MASTER_SITES=	http://cristal.inria.fr/~fpottier/menhir/

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	LR(1) parser generator for OCaml

USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
OCAML_PKGDIRS=		menhirLib

INSTALL_TARGET=	install
MAKE_ENV+=	mandir="${MANPREFIX}/man/man1"
MAN1=		menhir.1

.if !defined(NOPORTDOCS)
INSTALL_TARGET+=	docinstall
DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}
MAKE_ENV+=	docdir="${DOCSDIR}"
.endif

NO_STAGE=	yes
.include <bsd.port.mk>
