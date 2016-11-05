# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	postal
PORTVERSION=	0.73
PORTREVISION=	3
CATEGORIES=	benchmarks mail
MASTER_SITES=	http://www.coker.com.au/postal/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Benchmark SMTP/POP servers

LICENSE=	GPLv3

USES=		gmake tar:tgz
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/postal-list \
		man/man1/postal-list.1.gz \
		man/man8/bhm.8.gz \
		man/man8/postal.8.gz \
		man/man8/rabid.8.gz \
		sbin/bhm \
		sbin/postal \
		sbin/rabid

OPTIONS_RADIO=		TLS
OPTIONS_RADIO_TLS=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	OPENSSL

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=		pkgconfig
GNUTLS_CONFIGURE_OFF=	--disable-gnutls
GNUTLS_CPPFLAGS=	$$(pkg-config --cflags gnutls)
GNUTLS_LDFLAGS=		$$(pkg-config --libs gnutls)
OPENSSL_USE=		OPENSSL=yes
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
