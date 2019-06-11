# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dune
PORTVERSION=	1.10.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Composable build system for OCaml (formerly jbuilder)

LICENSE=	MIT

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes

ALL_TARGET=	release
MAKE_ENV=	LIBDIR="${OCAMLFIND_DESTDIR}"

PORTDOCS=	CHANGES.md LICENSE.md README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/doc/dune ${STAGEDIR}${DOCSDIR}
	@${RMDIR} ${STAGEDIR}${PREFIX}/doc

.include <bsd.port.mk>
