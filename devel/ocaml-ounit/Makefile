# Created by: Meikel Brandmeyer <ocaml-ounit-port@kotka.de>
# $FreeBSD$

PORTNAME=	ounit
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.xs4all.nl/~mmzeeman/ocaml/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml unit test framework

USES=		gmake
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
OCAML_PKGDIRS=	oUnit
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
ALL_TARGET=	all allopt testall doc
MAKE_ENV=	OCAMLFIND_DESTDIR=${PREFIX}/lib/ocaml/site-lib
OPTIONS_DEFINE=	DOCS

post-install:
	@${ECHO_MSG} "==>  Installing port documentation for ${PKGORIGIN}..."
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@( cd ${WRKSRC}; ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR} )
	@( cd ${WRKSRC}/doc; \
	   ${INSTALL_DATA} style.css ${STAGEDIR}${DOCSDIR}; \
	   for f in `${FIND} . -type f -name \\*.html -print`; do \
		${INSTALL_DATA} $${f} ${STAGEDIR}${DOCSDIR}; \
	   done )

.include <bsd.port.mk>
