PORTNAME=	ocamlbuild
PORTVERSION=	0.14.2
PORTREVISION=	5
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Legacy build tool for OCaml libraries and programs
WWW=		https://github.com/ocaml/ocamlbuild

LICENSE=	GPLv2

USES=		gmake ocaml
USE_GITHUB=	yes
GH_ACCOUNT=	ocaml

ALL_TARGET=	configure all
MAKE_ENV=	OCAMLBUILD_LIBDIR=${PREFIX}/${OCAML_LIBDIR}
TEST_TARGET=	test
TEST_ENV=	VERBOSE=1

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

.include <bsd.port.mk>
