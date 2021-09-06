# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	ocamlbuild
PORTVERSION=	0.14.0
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Build tool for OCaml libraries and programs

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
