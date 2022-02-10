# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>

PORTNAME=	elixir
DISTVERSIONPREFIX=	v
DISTVERSION=	1.12.3
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES+=	https://github.com/elixir-lang/elixir/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/:doc
DISTFILES=	Docs.zip:doc
DIST_SUBDIR=	elixir/${PORTVERSION}

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Functional, meta-programming aware language built on top of Erlang VM

LICENSE=	APACHE20

BUILD_DEPENDS=	erlang>=24.0:lang/erlang
RUN_DEPENDS=	erlang>=24.0:lang/erlang

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	elixir-lang

CONFLICTS=	elixir-devel # bin/elixir bin/elixirc bin/iex

USE_LOCALE=	en_US.UTF-8
ALL_TARGET=	# empty

REINPLACE_ARGS=	-i ""
NO_ARCH=	yes
MAKE_ENV=	MAN_PREFIX=${PREFIX}/man

OPTIONS_DEFINE=		DOCS SRC
OPTIONS_DEFAULT=	DOCS SRC
OPTIONS_SUB=		yes

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

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} test

.include <bsd.port.mk>
