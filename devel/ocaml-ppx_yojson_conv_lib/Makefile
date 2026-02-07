PORTNAME=	ppx_yojson_conv_lib
DISTVERSIONPREFIX=	v
DISTVERSION=	0.17.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Runtime library for ppx_yojson_conv
WWW=		https://github.com/janestreet/ppx_yojson_conv_lib

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/yojson/META:textproc/ocaml-yojson
RUN_DEPENDS=	${SA_DIR}/yojson/META:textproc/ocaml-yojson

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	janestreet

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	LICENSE.md

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "s/(lang dune 3.11)/(lang dune 3.7)/" \
		${WRKSRC}/dune-project

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/${PORTNAME}.cmxs

.include <bsd.port.mk>
