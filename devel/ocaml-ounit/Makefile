# Ports collection makefile for: ocaml-ounit
# Date created:        28th February 2006
# Whom:                Meikel Brandmeyer <ocaml-ounit-port@kotka.de>
#
# $FreeBSD$
#

PORTNAME=	ounit
PORTVERSION=	1.0.3
CATEGORIES=	devel
MASTER_SITES=	http://www.xs4all.nl/~mmzeeman/ocaml/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ocaml-ounit-port@kotka.de
COMMENT=	OCaml unit test framework

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib

USE_GMAKE=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
PORTDOCS=	README style.css *.html

ALL_TARGET=	all allopt testall doc

MAKE_ENV=	OCAMLFIND_DESTDIR=${PREFIX}/lib/ocaml/site-lib

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "==>  Installing port documentation for ${PKGORIGIN}..."
	@${MKDIR} ${DOCSDIR}
	@( cd ${WRKSRC}; ${INSTALL_DATA} README ${DOCSDIR} )
	@( cd ${WRKSRC}/doc; \
	   ${INSTALL_DATA} style.css ${DOCSDIR}; \
	   for f in `${FIND} . -type f -name \\*.html -print`; do \
		${INSTALL_DATA} $${f} ${DOCSDIR}; \
	   done )
.endif

.include <bsd.port.mk>
