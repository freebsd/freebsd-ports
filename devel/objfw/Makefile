PORTNAME=	objfw
DISTVERSION=	1.4.1
CATEGORIES=	devel lang
MASTER_SITES=	https://objfw.nil.im/downloads/

MAINTAINER=	js@nil.im
COMMENT=	Portable, lightweight framework for the Objective-C language
WWW=		https://objfw.nil.im/

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

BROKEN_armv6=	test suite fails
BROKEN_armv7=	test suite fails

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

TEST_TARGET=	check

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	OPENSSL
OPTIONS_SINGLE=		TLS
OPTIONS_SINGLE_TLS=	OPENSSL GNUTLS MBEDTLS NOTLS
NOTLS_DESC=		no SSL/TLS support

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=		pkgconfig
GNUTLS_CONFIGURE_ON=	--with-tls=gnutls
GNUTLS_PLIST_SUB=	TLS=""

MBEDTLS_LIB_DEPENDS=	libmbedtls.so:security/mbedtls3
MBEDTLS_USES=		localbase:ldflags
MBEDTLS_CONFIGURE_ON=	--with-tls=mbedtls
MBEDTLS_PLIST_SUB=	TLS=""

NOTLS_CONFIGURE_ON=	--without-tls
NOTLS_PLIST_SUB=	TLS="@comment "

OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_ON=	--with-tls=openssl
OPENSSL_CPPFLAGS=	-I${OPENSSLINC}
OPENSSL_LDFLAGS=	-L${OPENSSLLIB}
OPENSSL_PLIST_SUB=	TLS=""

do-build-DOCS-on:
	cd ${WRKSRC} && ${DO_MAKE_BUILD} docs

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/objfw)

post-install:
.for i in objfw-new ofarc ofdns ofhash ofhttp
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor
.for i in libobjfw.so.1 libobjfwrt.so.1 libobjfwhid.so.1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${i}
.endfor

.for tls in GNUTLS MBEDTLS OPENSSL
post-install-${tls}-on:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libobjfwtls.so.1
.endfor

.include <bsd.port.mk>
