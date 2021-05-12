PORTNAME=	gleam
DISTVERSIONPREFIX=	v
DISTVERSION=	0.15.1
CATEGORIES=	lang

MAINTAINER=	dch@FreeBSD.org
COMMENT=	ML-flavoured type-safe language using Erlang's BEAM runtime

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	rebar3:devel/rebar3

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	gleam-lang

.include "Makefile.deps"

RUSTFLAGS+=	--cap-lints=warn

PLIST_FILES=	bin/gleam

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gleam

post-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} README.md ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
