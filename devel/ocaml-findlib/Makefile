# ex:ts=8
# Ports collection makefile for:	findlib
# Date created:			Jul 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	findlib
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.ocaml-programming.de/packages/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml package manager

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	ocamlfind.1
MAN3=	Findlib.3 Topfind.3
MAN5=	META.5 findlib.conf.5 site-lib.5

.include <bsd.port.mk>
