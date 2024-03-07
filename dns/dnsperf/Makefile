PORTNAME=	dnsperf
DISTVERSION=	2.11.0
PORTREVISION=	1
CATEGORIES=	dns benchmarks net
MASTER_SITES=	https://www.dns-oarc.net/files/${PORTNAME}/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Performance measurement of Domain Name System (DNS) servers
WWW=		https://www.dns-oarc.net/tools/dnsperf

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libnghttp2.so:www/libnghttp2 \
		libck.so:devel/concurrencykit \
		libldns.so:dns/ldns

USES=		compiler:c11 libtool pkgconfig ssl

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV=	libssl_LIBS="-lssl -L${OPENSSLLIB}" \
		libssl_CFLAGS="-I${OPENSSLINC}" \
		libcrypto_LIBS="-lcrypto -L${OPENSSLLIB}" \
		libcrypto_CFLAGS="-I${OPENSSLINC}"
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}"
PLIST_FILES=	bin/dnsperf \
		bin/resperf \
		bin/resperf-report \
		share/man/man1/dnsperf.1.gz \
		share/man/man1/resperf.1.gz

.include <bsd.port.mk>
