# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	sexplib
PORTVERSION=	113.00.00
MASTER_SITES=	https://ocaml.janestreet.com/ocaml-core/${PORTVERSION:R}/files/
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml library for working with S-expressions

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_BSD3CLAUSE=${WRKSRC}/LICENSE-Tywith.txt

BUILD_DEPENDS=	ocaml-type_conv>=0:devel/ocaml-type_conv
RUN_DEPENDS=	ocaml-type_conv>=0:devel/ocaml-type_conv

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--disable-docs --prefix ${PREFIX}
HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAMLFIND_PLIST=	yes
USES=		gmake

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
OCAML_PKGDIRS=	${PORTNAME} ${PORTNAME}_num ${PORTNAME}_unix
PORTDOCS=	*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/sexplib*/*.cmxs

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGES.md README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
