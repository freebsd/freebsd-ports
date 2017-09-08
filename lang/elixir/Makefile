# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elixir
PORTVERSION=	1.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	lang
MASTER_SITES+=	https://github.com/elixir-lang/elixir/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/:doc
DISTFILES=	Docs.zip:doc
DIST_SUBDIR=	elixir/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Functional, meta-programming aware language built on top of Erlang VM

LICENSE=	APACHE20

BUILD_DEPENDS=	erlang>=18:lang/erlang
RUN_DEPENDS=	erlang>=18:lang/erlang

USE_GITHUB=	yes
GH_ACCOUNT=	elixir-lang

USES=		gmake
USE_LOCALE=	en_US.UTF-8
ALL_TARGET=	# empty
REINPLACE_ARGS=	-i ""
NO_ARCH=	yes
OPTIONS_SUB=	yes

OPTIONS_DEFINE=	SRC DOCS
OPTIONS_DEFAULT=SRC

SRC_DESC=	Install source code

.include <bsd.port.options.mk>

post-extract:
	@${FIND} ${WRKDIR}/doc -name .build -delete

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/doc/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

post-install-SRC-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib
	cd ${WRKSRC}/lib/ && for lib in *; do \
		${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib/$${lib}/lib; \
		cd ${WRKSRC}/lib/$${lib}/lib && \
			${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/elixir/lib/$${lib}/lib; \
	done

.include <bsd.port.mk>
