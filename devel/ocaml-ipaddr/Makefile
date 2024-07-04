PORTNAME=	ipaddr
PORTVERSION=	5.6.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml library for manipulation of IP address representations
WWW=		https://github.com/mirage/ocaml-ipaddr

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/cstruct/META:devel/ocaml-cstruct \
		${SA_DIR}/domain-name/META:devel/ocaml-domain-name \
		${SA_DIR}/ppx_sexp_conv/META:devel/ocaml-ppx_sexp_conv
RUN_DEPENDS=	${SA_DIR}/cstruct/META:devel/ocaml-cstruct \
		${SA_DIR}/domain-name/META:devel/ocaml-domain-name \
		${SA_DIR}/ppx_sexp_conv/META:devel/ocaml-ppx_sexp_conv

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	mirage
GH_PROJECT=	ocaml-ipaddr
USE_OCAML=		yes
OCAML_PACKAGES=		ipaddr ipaddr-cstruct ipaddr-sexp
OCAML_PACKAGES+=	macaddr macaddr-cstruct macaddr-sexp

DOCSDIR=	${OCAML_DOCSDIR}
PORTDOCS=	${OCAML_PACKAGES:@p@$p/CHANGES.md $p/LICENSE.md $p/README.md@}

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(name ${PORTNAME})/&\n (version ${PORTVERSION})/" \
		${WRKSRC}/dune-project

post-install:
	@(cd ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}; \
	${STRIP_CMD} \
		ipaddr/top/ipaddr_top.cmxs \
		ipaddr/unix/ipaddr_unix.cmxs \
		macaddr/top/macaddr_top.cmxs \
		${OCAML_PACKAGES:@p@$p/${p:S/-/_/g}.cmxs@})

.include <bsd.port.mk>
