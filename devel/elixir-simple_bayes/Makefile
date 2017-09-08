# $FreeBSD$

PORTNAME=	simple_bayes
DISTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Naive Bayes machine learning implementation in Elixir

LICENSE=	MIT

BROKEN=		fails to build

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	fredwu

MIX_BUILD_DEPS=	devel/elixir-decimal \
		devel/elixir-math
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

.include <bsd.port.mk>
