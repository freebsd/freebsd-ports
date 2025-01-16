PORTNAME=	type_conv
PORTVERSION=	113.00.02
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://ocaml.janestreet.com/ocaml-core/${PORTVERSION:R}/files/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Type conversion routines for OCaml
WWW=		https://janestreet.github.io/

LICENSE=	APACHE20 BSD3CLAUSE
LICENSE_COMB=	multi

BUILD_DEPENDS=	ocamlbuild:devel/ocaml-ocamlbuild

USES=		gmake ocaml:camlp4,findplist

OPTIONS_DEFINE=	DOCS

CONFIGURE_ARGS=	--disable-docs --prefix ${PREFIX}
HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/type_conv/pa_type_conv.cmxs

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGES.md README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
