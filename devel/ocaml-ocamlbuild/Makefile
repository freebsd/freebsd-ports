PORTNAME=	ocamlbuild
PORTVERSION=	0.14.1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Legacy build tool for OCaml libraries and programs

LICENSE=	GPLv2

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml
USE_OCAML=	yes

ALL_TARGET=	configure all
MAKE_ENV=	OCAMLBUILD_LIBDIR=${PREFIX}/${OCAML_LIBDIR}
TEST_TARGET=	test
TEST_ENV=	VERBOSE=1

.include <bsd.port.mk>
