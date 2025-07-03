PORTNAME=	rustup-init
DISTVERSION=	1.28.1
PORTREVISION=	3
CATEGORIES=	devel
DISTNAME=	rustup

MAINTAINER=	jinking.this@gmail.com
COMMENT=	Rust toolchain installer
WWW=		https://rustup.rs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo llvm ssl
USE_GITHUB=	yes
GH_ACCOUNT=	rust-lang
GH_PROJECT=	rustup

ONLY_FOR_ARCHS=	amd64
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
