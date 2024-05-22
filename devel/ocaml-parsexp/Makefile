PORTNAME=	parsexp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	OCaml library for parsing S-expressions
WWW=		https://janestreet.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${SA_DIR}/sexplib0/META:devel/ocaml-sexplib0
RUN_DEPENDS=	${SA_DIR}/sexplib0/META:devel/ocaml-sexplib0

USES=		ocaml:dune
USE_GITHUB=	yes
GH_ACCOUNT=	janestreet
USE_OCAML=	yes

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	CHANGES.md LICENSE.md README.org

OPTIONS_DEFINE=	DOCS

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/parsexp/parsexp.cmxs

.include <bsd.port.mk>
