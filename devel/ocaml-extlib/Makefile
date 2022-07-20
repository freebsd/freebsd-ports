PORTNAME=	extlib
PORTVERSION=	1.7.5
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete - yet small - standard library for OCaml

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/../LICENSE

BROKEN_mips=	Depends on Ocaml(not available for mips)

BUILD_DEPENDS=	cppo:devel/ocaml-cppo

WRKSRC_SUBDIR=	src

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	ygrek
GH_PROJECT=	ocaml-extlib

USE_OCAML=	yes
USE_OCAML_CAMLP4=yes
USE_OCAML_FINDLIB=yes
USE_OCAMLFIND_PLIST=yes

MAKE_ARGS=	VERSION="${PORTVERSION}"
ALL_TARGET=	all opt doc

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
