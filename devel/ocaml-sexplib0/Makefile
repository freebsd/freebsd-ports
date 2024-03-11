PORTNAME=	sexplib0
DISTVERSIONPREFIX=	v
DISTVERSION=	0.16.0
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml library for working with S-expressions
WWW=		https://janestreet.github.io/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	dune:devel/ocaml-dune \
		ocaml-type_conv>=0:devel/ocaml-type_conv \
		${LOCALBASE}/${OCAML_SITELIBDIR}/num/META:math/ocaml-num
RUN_DEPENDS=	ocaml-type_conv>=0:devel/ocaml-type_conv

USES=		gmake
ALL_TARGET=	default
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAMLFIND_PLIST=	yes
CONFIGURE_ARGS=	--disable-docs --prefix ${PREFIX}

USE_GITHUB=	yes
GH_ACCOUNT=	janestreet

OPTIONS_DEFINE=	DOCS

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
OCAML_PKGDIRS=	${PORTNAME} ${PORTNAME}_num ${PORTNAME}_unix
PORTDOCS=	*

do-install:
	cd ${INSTALL_WRKSRC} && dune install --destdir=${STAGEDIR} \
		--prefix=${PREFIX} --libdir=${PREFIX}/${OCAML_SITELIBDIR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/sexplib*/*.cmxs

#post-install-DOCS-on:
#	${MKDIR} ${STAGEDIR}${DOCSDIR}/
#	cd ${WRKSRC}/ && ${INSTALL_DATA} CHANGES.md README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
