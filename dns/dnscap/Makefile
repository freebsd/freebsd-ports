PORTNAME=	dnscap
PORTVERSION=	2.4.1
PORTEPOCH=	1
CATEGORIES=	dns
MASTER_SITES=	https://www.dns-oarc.net/files/dnscap/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	DNS network traffic capture utility
WWW=		https://www.dns-oarc.net/tools/dnscap \
		https://github.com/DNS-OARC/dnscap

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libldns.so:dns/ldns \
		liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd

USES=		autoreconf libtool localbase pkgconfig ssl

CONFIGURE_ARGS=	--enable-shared --enable-static
CONFIGURE_ENV=	libcrypto_CFLAGS=-I${OPENSSLINC}/include \
		libcrypto_LIBS="-L${OPENSSLLIB}/lib -lcrypto"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	CDS THREADS
OPTIONS_DEFAULT=THREADS
CDS_DESC=	CBOR DNS Stream (CDS) format (experimental)

CDS_CONFIGURE_OFF=	ac_cv_lib_tinycbor_cbor_parser_init=no
CDS_LIB_DEPENDS=	libtinycbor.so:devel/tinycbor
THREADS_CONFIGURE_ENABLE=	threads

.include <bsd.port.mk>
