# Created by: mukai
# $FreeBSD$

PORTNAME=	extlib
PORTVERSION=	1.7.1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Complete - yet small - standard library for OCaml

LICENSE=	LGPL21

BUILD_DEPENDS=	cppo:devel/ocaml-cppo

WRKSRC_SUBDIR=	src

USE_GITHUB=	yes
GH_ACCOUNT=	ygrek
GH_PROJECT=	ocaml-extlib

USE_OCAML=	yes
USE_OCAML_CAMLP4=yes
USE_OCAML_FINDLIB=yes
USE_OCAMLFIND_PLIST=yes

USES=		gmake
MAKE_ARGS=	VERSION="${PORTVERSION}"
ALL_TARGET=	all opt doc
MAKE_JOBS_UNSAFE=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
