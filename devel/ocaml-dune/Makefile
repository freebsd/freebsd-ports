# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	dune
PORTVERSION=	1.11.4
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

CONFLICTS_INSTALL=	wdune

ALL_TARGET=	release
MAKE_ENV=	LIBDIR="${OCAML_SITELIBDIR}"
DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

PORTDOCS=	*.md

OPTIONS_DEFINE=	DOCS

post-patch:
# FreeBSD-specific hack, do not nag upstream (for now)
	@${REINPLACE_CMD} -e '/let doc_root/ \
		s:"doc:"${OCAML_DOCSDIR:S,^${PREFIX}/,,}:' \
		${WRKSRC}/src/install.ml

.include <bsd.port.mk>
