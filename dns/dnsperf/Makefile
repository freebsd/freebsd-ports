PORTNAME=	dnsperf
PORTVERSION=	2.7.0
DISTVERSIONPREFIX=v
CATEGORIES=	dns benchmarks net

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Performance measurement of Domain Name System (DNS) servers

LICENSE=	APACHE20

LIB_DEPENDS=	libnghttp2.so:www/libnghttp2 \
		libck.so:devel/concurrencykit \
		libldns.so:dns/ldns

USES=		autoreconf compiler:c11 libtool pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	DNS-OARC

GNU_CONFIGURE=	yes
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
		man/man1/dnsperf.1.gz \
		man/man1/resperf.1.gz

.include <bsd.port.mk>
