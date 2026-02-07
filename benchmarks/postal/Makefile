PORTNAME=	postal
PORTVERSION=	0.76
PORTREVISION=	1
CATEGORIES=	benchmarks mail
MASTER_SITES=	https://www.coker.com.au/postal/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Benchmark SMTP/POP servers
WWW=		https://doc.coker.com.au/projects/postal/

LICENSE=	GPLv3

USES=		gmake tar:tgz
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/postal-list \
		share/man/man1/postal-list.1.gz \
		share/man/man8/bhm.8.gz \
		share/man/man8/postal.8.gz \
		share/man/man8/rabid.8.gz \
		sbin/bhm \
		sbin/postal \
		sbin/rabid

OPTIONS_DEFAULT=	OPENSSL
OPTIONS_RADIO=		TLS
OPTIONS_RADIO_TLS=	GNUTLS OPENSSL

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=		pkgconfig
GNUTLS_CONFIGURE_OFF=	--disable-gnutls
GNUTLS_CPPFLAGS=	$$(pkg-config --cflags gnutls)
GNUTLS_LDFLAGS=		$$(pkg-config --libs gnutls)
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_OFF=	--disable-openssl
OPENSSL_CPPFLAGS=	-I${OPENSSLINC}
OPENSSL_LDFLAGS=	-L${OPENSSLLIB}

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread| ; \
		 s|-lgcrypt||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|-pedantic|| ; \
		 s|-O2 -g|$$(CPPFLAGS)| ; \
		 s|-lstdc++|$$(LDFLAGS)|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
