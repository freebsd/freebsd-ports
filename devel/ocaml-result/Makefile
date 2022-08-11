PORTNAME=	result
PORTVERSION=	1.5
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Compatibility result module for OCaml

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	dune:devel/ocaml-dune

USES=		gmake
USE_OCAML=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	janestreet

ALL_TARGET=	default
MAKE_ENV=	LIBDIR=${OCAML_SITELIBDIR}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
