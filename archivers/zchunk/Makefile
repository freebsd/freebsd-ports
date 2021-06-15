PORTNAME=	zchunk
DISTVERSION=	1.1.16
CATEGORIES=	archivers

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Compressed file format that splits the file into independent chunks

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libargp.so:devel/argp-standalone \
		libcurl.so:ftp/curl

USES=		localbase:ldflags meson pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

LDFLAGS+=	${LOCALBASE}/lib/libargp.so # workaround for https://github.com/zchunk/zchunk/issues/30

OPTIONS_DEFINE=		OPENSSL ZSTD
OPTIONS_DEFAULT=	OPENSSL ZSTD

OPENSSL_MESON_ON=	-Dwith-openssl=enabled
OPENSSL_MESON_OFF=	-Dwith-openssl=disabled
OPENSSL_USES=		ssl
OPENSSL_LDFLAGS=	-L${OPENSSLLIB} -lssl -lcrypto # workaround for https://github.com/zchunk/zchunk/issues/31

ZSTD_MESON_ON=		-Dwith-zstd=enabled
ZSTD_MESON_OFF=		-Dwith-zstd=disabled
ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd

.include <bsd.port.mk>
