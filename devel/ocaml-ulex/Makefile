# Created by: ijliao
# $FreeBSD$

PORTNAME=	ulex
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cduce.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lexer generator for Unicode and OCaml

USES=		gmake
USE_OCAML=	true
USE_OCAML_FINDLIB=	true
USE_OCAML_CAMLP4=	true
USE_OCAML_LDCONFIG=	true
USE_OCAMLFIND_PLIST=	yes

ALL_TARGET=	all all.opt
MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_ALL_TARGET=	doc

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${WRKSRC}/*.css ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
