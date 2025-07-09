PORTNAME=	dnsjit
DISTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	dns net
MASTER_SITES=	https://www.dns-oarc.net/files/${PORTNAME}/

MAINTAINER=	freebsd@dns.company
COMMENT=	Engine for capturing, parsing and replaying DNS
WWW=		https://www.dns-oarc.net/tools/dnsjit

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libck.so:devel/concurrencykit \
		libgnutls.so:security/gnutls \
		liblmdb.so:databases/lmdb \
		liblz4.so:archivers/liblz4 \
		libzstd.so:archivers/zstd

USES=		libtool localbase luajit pkgconfig

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	EXAMPLES

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.lua ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
