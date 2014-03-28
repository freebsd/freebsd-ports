# Created by: J. Giovannangeli
# $FreeBSD$

PORTNAME=	opam
PORTVERSION=	1.1.1
CATEGORIES=	devel
MASTER_SITES=	http://www.ocamlpro.com/pub/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	opam-full-${PORTVERSION}

MAINTAINER=	joris@giovannangeli.fr
COMMENT=	Source-based package manager for OCaml

LICENSE=	GPLv3

BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl

USES=		gmake
USE_OCAML=	yes
GNU_CONFIGURE=	yes
MAKE_ENV+=	TERM=xterm

MAKE_JOBS_UNSAFE= yes

.include <bsd.port.mk>
