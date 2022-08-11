PORTNAME=	type_conv
PORTVERSION=	113.00.02
CATEGORIES=	devel
MASTER_SITES=	https://ocaml.janestreet.com/ocaml-core/${PORTVERSION:R}/files/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Type conversion routines for OCaml

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	multi

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--disable-docs --prefix ${PREFIX}
HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_OCAML=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
USES=		gmake

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/type_conv/pa_type_conv.cmxs

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGES.md README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
