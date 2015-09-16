# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elixir
PORTVERSION=	1.0.5
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Functional, meta-programming aware language built on top of Erlang VM

LICENSE=	APACHE20

BUILD_DEPENDS=	erlang>=17:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erlang>=17:${PORTSDIR}/lang/erlang

USE_GITHUB=	yes
GH_ACCOUNT=	elixir-lang

USES=		gmake
MAKE_ENV=	LANG=en_US.UTF-8
ALL_TARGET=	#empty

OPTIONS_DEFINE=	SRC
OPTIONS_DEFAULT=SRC

SRC_DESC=	Install source code

PLIST_FILES=	bin/elixir \
		bin/elixirc \
		bin/iex \
		bin/mix

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MSRC}
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib
	cd ${WRKSRC}/lib/ && for lib in *; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib/$${lib}/lib; \
		cd ${WRKSRC}/lib/$${lib}/lib && \
			${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/elixir/lib/$${lib}/lib; \
	done
.endif
	@cd ${STAGEDIR}${PREFIX}; ${FIND} lib/elixir/* -type f -o -type l \
		| ${SORT} \
		>> ${TMPPLIST}

.include <bsd.port.mk>
