PORTNAME=	ulex
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.cduce.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lexer generator for Unicode and OCaml

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild

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

post-patch:
	@${REINPLACE_CMD} -e '/^let latin1_sub_lexeme/,+3 \
		s,^  s,  Bytes.to_string s,' ${WRKSRC}/ulexing.ml

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${WRKSRC}/*.css ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
