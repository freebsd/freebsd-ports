# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ocamlbuild
PORTVERSION=	0.9.3
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

MAKE_ARGS=	CHECK_IF_PREINSTALLED=false	# XXX: remove after 4.03.0+

.include <bsd.port.mk>
