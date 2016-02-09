# Created by: Meikel Brandmeyer <ocaml-ounit-port@kotka.de>
# $FreeBSD$

PORTNAME=	ounit
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.xs4all.nl/~mmzeeman/ocaml/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml unit test framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

USES=		gmake
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
OCAML_PKGDIRS=	oUnit
ALL_TARGET=	all allopt testall doc
MAKE_ENV=	OCAMLFIND_DESTDIR=${PREFIX}/lib/ocaml/site-lib

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/style.css ${STAGEDIR}${DOCSDIR}
	${FIND} ${WRKSRC}/doc -type f -name "*.html" -exec \
		${INSTALL_DATA} {} ${STAGEDIR}${DOCSDIR} \;

.include <bsd.port.mk>
