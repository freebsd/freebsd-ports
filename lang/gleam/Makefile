PORTNAME=	gleam
DISTVERSIONPREFIX=	v
DISTVERSION=	1.11.0
PORTREVISION=	2
CATEGORIES=	lang

MAINTAINER=	dch@FreeBSD.org
COMMENT=	ML-flavoured type-safe language using Erlang's BEAM runtime
WWW=		https://gleam.run/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/compiler-core/LICENCE

BROKEN_i386=	needs SSE or SSE2 type extensions to compile

TEST_DEPENDS=	erlang:lang/erlang

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	gleam-lang

RUSTFLAGS+=	--cap-lints=warn

PORTSCOUT=	limit:[0-9.]+

PLIST_FILES=	bin/gleam

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

PORTSCOUT=	limit:[0-9.]+

do-build:
	(cd ${WRKSRC} && \
		cargo build --release)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin/
	${MV} ${WRKSRC}/target/release/gleam \
		${STAGEDIR}${PREFIX}/bin/

post-install-DOCS-on:
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} README.md ${STAGEDIR}${DOCSDIR})

do-test:
	(cd ${WRKSRC} && \
		gleam new hello && \
		cd hello && \
		gleam test)

.include <bsd.port.mk>
