PORTNAME=	gleam
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.0
PORTREVISION=	1
CATEGORIES=	lang

MAINTAINER=	dch@FreeBSD.org
COMMENT=	ML-flavoured type-safe language using Erlang's BEAM runtime

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/compiler-core/LICENCE

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	gleam-lang

.include "Makefile.deps"

RUSTFLAGS+=	--cap-lints=warn

PLIST_FILES=	bin/gleam

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-build:
	(cd ${WRKSRC} && cargo build --release)
	(cd ${WRKSRC}/compiler-cli && cargo install --path . --force --locked)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/bin/
	${MV} ${WRKSRC}/target/release/gleam ${STAGEDIR}${PREFIX}/bin/

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gleam

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} README.md ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
