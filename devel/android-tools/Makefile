PORTNAME=	android-tools
PORTVERSION=	31.0.3p1.1
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	GH

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Android debugging tools

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbrotlicommon.so:archivers/brotli \
		libgmock.so:devel/googletest \
		liblz4.so:archivers/liblz4 \
		libpcre2-8.so:devel/pcre2 \
		libprotobuf.so:devel/protobuf \
		libzstd.so:archivers/zstd

USES=		cmake go:no_targets perl5 python:3.7+ shebangfix

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

.include <bsd.port.mk>
