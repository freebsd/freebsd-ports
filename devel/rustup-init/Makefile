PORTNAME=	rustup-init
DISTVERSION=	1.29.1
CATEGORIES=	devel
DISTNAME=	rustup

MAINTAINER=	jinking.this@gmail.com
COMMENT=	Rust toolchain installer
WWW=		https://rustup.rs/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS=	libbrotlicommon.so:archivers/brotli \
		libbrotlidec.so:archivers/brotli \
		libcurl.so:ftp/curl \
		libidn2.so:dns/libidn2 \
		libnghttp2.so:www/libnghttp2 \
		libpsl.so:dns/libpsl \
		libssh2.so:security/libssh2 \
		libunistring.so:devel/libunistring \
		libzstd.so:archivers/zstd

USES=		cargo llvm ssl
USE_GITHUB=	yes
GH_ACCOUNT=	rust-lang
GH_PROJECT=	rustup

TESTING_UNSAFE=	yes

.if make(test)
CARGO_FEATURES=		test
CARGO_TEST_ARGS=	-- --skip test_bonanza
.endif

CARGO_ENV=	OPENSSL_NO_VENDOR=1

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
