PORTNAME=	stdio
PORTVERSION=	0.16.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	Standard IO library for Objective-Caml
WWW=		https://github.com/janestreet/stdio

LICENSE=	MIT

BUILD_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base
RUN_DEPENDS=	${SA_DIR}/base/META:devel/ocaml-base

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	janestreet
USE_OCAML=	yes
USE_OCAML_LDCONFIG=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.md odoc-pages

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}/${PORTNAME}.cmxs

.include <bsd.port.mk>
