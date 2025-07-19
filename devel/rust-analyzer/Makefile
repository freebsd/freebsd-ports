PORTNAME=	rust-analyzer
DISTVERSION=	2025-07-14
CATEGORIES=	devel

MAINTAINER=	rust@FreeBSD.org
COMMENT=	Experimental Rust compiler front-end for IDEs
WWW=		https://rust-analyzer.github.io/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo dos2unix
DOS2UNIX_FILES=	${WRKSRC_crate_notify}/src/kqueue.rs
USE_GITHUB=	yes

CARGO_INSTALL_PATH=	crates/rust-analyzer
CARGO_ENV+=	CFG_RELEASE=${DISTVERSION}

LTO_UNSAFE=	yes

# attempts to install rustup toolchains
NO_TEST=	yes

PLIST_FILES=	bin/rust-analyzer
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@cd ${WRKSRC}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
