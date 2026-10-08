PORTNAME=	codemark
DISTVERSION=	0.7.30
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Semantic code bookmarking system for humans and agents
WWW=		https://github.com/DanielCardonaRojas/codemark

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libonig.so:devel/oniguruma \
		libzstd.so:archivers/zstd

USES=		cargo cmake:indirect pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	DanielCardonaRojas

CARGO_INSTALL_PATH=	crates/codemark-cli crates/codemark-tui

PLIST_FILES=	bin/codemark \
		bin/codemark-tui

.include <bsd.port.options.mk>

.if ${ARCH:Mpowerpc64*}
post-patch:
	@${REINPLACE_CMD} -e 's/, "wasm"]/]/' \
		${WRKSRC}/crates/codemark-cli/Cargo.toml \
		${WRKSRC}/crates/codemark-core/Cargo.toml \
		${WRKSRC}/crates/codemark-tui/Cargo.toml
.endif

.include <bsd.port.mk>
