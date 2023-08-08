PORTNAME=	extlib
DISTVERSION=	1.7.9
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/ygrek/ocaml-extlib/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Complete - yet small - standard library for OCaml
WWW=		https://github.com/ygrek/ocaml-extlib

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/../LICENSE

BROKEN_mips=	depends on Ocaml(not available for mips)

BUILD_DEPENDS=	cppo:devel/ocaml-cppo

USES=		gmake

USE_OCAML=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes

MAKE_ARGS=	VERSION="${DISTVERSION}"
ALL_TARGET=	all opt doc

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

WRKSRC_SUBDIR=	src

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
