PORTNAME=	dnsjit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	dns net

MAINTAINER=	freebsd@dns.company
COMMENT=	Engine for capturing, parsing and replaying DNS
WWW=		https://www.dns-oarc.net/tools/dnsjit

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libck.so:devel/concurrencykit \
		libgnutls.so:security/gnutls \
		liblmdb.so:databases/lmdb \
		libpcap.so:net/libpcap \
		liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd
		# Mind PR 262976 about libpcap

USES=		autoreconf libtool luajit pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	DNS-OARC

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.lua ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
