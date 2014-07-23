# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elixir
PORTVERSION=	0.14.3
CATEGORIES=	lang

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Functional, meta-programming aware language built on top of Erlang VM

LICENSE=	APACHE20

BUILD_DEPENDS=	erlang>=17:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erlang>=17:${PORTSDIR}/lang/erlang

USE_GITHUB=	yes
GH_ACCOUNT=	elixir-lang
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	82535fe

USES=	gmake

ALL_TARGET=	#empty

.include <bsd.port.mk>
