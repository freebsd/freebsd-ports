PORTNAME=	objfw
DISTVERSION=	1.1.6
CATEGORIES=	devel lang
MASTER_SITES=	https://objfw.nil.im/downloads/

MAINTAINER=	js@nil.im
COMMENT=	Portable, lightweight framework for the Objective-C language
WWW=		https://objfw.nil.im/

LICENSE=	LGPL3

BROKEN_armv6=	test suite fails
BROKEN_armv7=	test suite fails

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

TEST_TARGET=	check

OPTIONS_DEFINE=		DOCS
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	OPENSSL GNUTLS MBEDTLS NOSSL
OPTIONS_DEFAULT=	OPENSSL
NOSSL_DESC=		no SSL/TLS support

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen

OPENSSL_CONFIGURE_ON=	--with-tls=openssl
OPENSSL_PLIST_SUB=	TLS=""
OPENSSL_CPPFLAGS=	-I${OPENSSLINC}
OPENSSL_LDFLAGS=	-L${OPENSSLLIB}
OPENSSL_USES=		ssl

GNUTLS_CONFIGURE_ON=	--with-tls=gnutls
GNUTLS_PLIST_SUB=	TLS=""
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=		pkgconfig

MBEDTLS_CONFIGURE_ON=	--with-tls=mbedtls
MBEDTLS_PLIST_SUB=	TLS=""
MBEDTLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls
MBEDTLS_CPPFLAGS=	-I${PREFIX}/include
MBEDTLS_LDFLAGS=	-L${PREFIX}/lib

NOSSL_CONFIGURE_ON=	--without-tls
NOSSL_PLIST_SUB=	TLS="@comment "

do-build-DOCS-on:
	cd ${WRKSRC} && ${DO_MAKE_BUILD} docs

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/objfw)

post-install:
.for i in objfw-new ofarc ofdns ofhash ofhttp
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/$i
.endfor
.for i in libobjfw.so.1 libobjfwrt.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/$i
.endfor

post-install-OPENSSL-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libobjfwtls.so.1

post-install-GNUTLS-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libobjfwtls.so.1

.include <bsd.port.mk>
