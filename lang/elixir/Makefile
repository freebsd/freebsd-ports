# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elixir
PORTVERSION=	1.0.0
CATEGORIES=	lang

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Functional, meta-programming aware language built on top of Erlang VM

LICENSE=	APACHE20

BUILD_DEPENDS=	erlang>=17:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erlang>=17:${PORTSDIR}/lang/erlang

USE_GITHUB=	yes
GH_ACCOUNT=	elixir-lang
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	52ff7e9

USES=	gmake

ALL_TARGET=	#empty

.include <bsd.port.mk>
