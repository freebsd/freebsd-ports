PORTNAME=	elixir
DISTVERSIONPREFIX=	v
DISTVERSION=	1.19.0
DISTVERSIONSUFFIX=-rc.0
CATEGORIES=	lang
MASTER_SITES+=	https://github.com/elixir-lang/elixir/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}/:doc
PKGNAMESUFFIX=	-devel
DISTFILES=	Docs.zip:doc
DIST_SUBDIR=	elixir/${PORTVERSION}

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Functional, meta-programming aware language built on top of Erlang VM
WWW=		https://elixir-lang.org/

LICENSE=	APACHE20

BUILD_DEPENDS=	erlang-runtime${ERLANG_VER}>0:lang/erlang-runtime${ERLANG_VER}

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	elixir-lang

USE_LOCALE=	en_US.UTF-8
MAKE_ENV+=	MAN_PREFIX=${PREFIX}/share/man \
		PATH="${LOCALBASE}/lib/erlang${ERLANG_VER}/bin:${PATH}"
ALL_TARGET=	# empty

CONFLICTS=	elixir # bin/elixir bin/elixirc bin/iex

REINPLACE_ARGS=	-i ""
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

ERLANG_VER?=	27

.include <bsd.port.options.mk>

post-extract:
	${FIND} ${WRKDIR}/doc -name .build -delete -or -name .ex_doc -delete

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKDIR}/doc/ && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib
	cd ${WRKSRC}/lib/ && \
		for lib in *; \
		do ${MKDIR} ${STAGEDIR}${PREFIX}/lib/elixir/lib/$${lib}/lib; \
		cd ${WRKSRC}/lib/$${lib}/lib && \
		${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/lib/elixir/lib/$${lib}/lib; \
		done

do-test:
	cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} test

.include <bsd.port.mk>
