PORTNAME=	stdio
PORTVERSION=	0.17.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Standard IO library for Objective-Caml
WWW=		https://github.com/janestreet/stdio

LICENSE=	MIT

BUILD_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base
RUN_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base

USES=		ocaml:dune,ldconfig
USE_GITHUB=	yes
GH_ACCOUNT=	janestreet

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md odoc-pages

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
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/${PORTNAME}.cmxs

.include <bsd.port.mk>
