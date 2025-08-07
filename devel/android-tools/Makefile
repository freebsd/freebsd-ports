PORTNAME=	android-tools
PORTVERSION=	31.0.3p2.0
PORTREVISION=	36
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Android debugging tools
WWW=		https://github.com/neelchauhan/freebsd-android-tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	ld: error: undefined symbol: OPENSSL_cpuid_setup

LIB_DEPENDS=	libbrotlicommon.so:archivers/brotli \
		libgmock.so:devel/googletest \
		liblz4.so:archivers/liblz4 \
		libpcre2-8.so:devel/pcre2 \
		libprotobuf.so:devel/protobuf \
		libzstd.so:archivers/zstd

USES=		cmake compiler:c++17-lang go:no_targets localbase:ldflags perl5 python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	neelchauhan
GH_PROJECT=	freebsd-${PORTNAME}
GH_TAGNAME=	271d7a26c8daf4b9fe412d360a2edfaca327efdd

SHEBANG_FILES=	vendor/mkbootimg/repack_bootimg.py \
		vendor/mkbootimg/mkbootimg.py \
		vendor/mkbootimg/unpack_bootimg.py

MAKE_ENV+=	GOFLAGS=-mod=vendor \
		GOPATH=${WRKSRC}/vendor/boringssl/vendor \
		GOPROXY=off

LDFLAGS+=	-labsl_status

.include <bsd.port.mk>
