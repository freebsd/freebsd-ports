# $FreeBSD$

PORTNAME=	simple_bayes
DISTVERSION=	0.12.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel
PKGNAMEPREFIX=	elixir-

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Naive Bayes machine learning implementation in Elixir

LICENSE=	MIT

USES=		elixir
USE_GITHUB=	yes
GH_ACCOUNT=	fredwu

MIX_BUILD_DEPS=	devel/elixir-decimal \
		devel/elixir-math
MIX_RUN_DEPS:=	${MIX_BUILD_DEPS}
MIX_REWRITE=	yes

.include <bsd.port.mk>
