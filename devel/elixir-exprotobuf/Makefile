# $FreeBSD$

PORTNAME=	exprotobuf
DISTVERSION=	1.2.9
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Protocol Buffers in Elixir

LICENSE=	APACHE20

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	bitwalker

MIX_BUILD_DEPS=	devel/erlang-gpb
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}

pre-build:
	@${MKDIR} ${WRKSRC}/deps
	${LN} -s -f ${LOCALBASE}/lib/erlang/lib/gpb-* ${WRKSRC}/deps/gpb

.include <bsd.port.mk>
