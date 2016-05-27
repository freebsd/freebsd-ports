# Created by: Li-Wen Hsu <lwhsu@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elixir
PORTVERSION=	1.2.5
DISTVERSIONPREFIX=	v
CATEGORIES=	lang
MASTER_SITES+=	http://github.com/elixir-lang/elixir/releases/download/${DISTVERSIONPREFIX}${PORTVERSION}/:doc
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
MAKE_ENV=	LANG=en_US.UTF-8
ALL_TARGET=	#empty
REINPLACE_ARGS=	-i ""
NO_ARCH=	yes
OPTIONS_SUB=	yes

OPTIONS_DEFINE=	SRC DOCS
OPTIONS_DEFAULT=SRC

SRC_DESC=	Install source code

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/Makefile
	@${RM} ${WRKSRC}/bin/*.orig

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
