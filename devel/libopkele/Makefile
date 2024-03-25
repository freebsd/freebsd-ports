PORTNAME=	libopkele
PORTVERSION=	2.0.4
PORTREVISION=	21
CATEGORIES=	devel
MASTER_SITES=	http://kin.klever.net/dist/

PATCH_SITES=	https://github.com/hacker/libopkele/commit/
PATCHFILES=	62f3ba4ecb92.diff:-p1

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	C++ implementation of an OpenID decentralized identity system
WWW=		https://kin.klever.net/libopkele/

DEPRECATED=	Last upstream release was in 2009
EXPIRATION_DATE=2024-04-24

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre \
		libexpat.so:textproc/expat2 \
		libtidy5.so:www/tidy-html5 \
		libxslt.so:textproc/libxslt

USES=		gmake libtool localbase:ldflags pathfix \
		pkgconfig ssl
USE_CXXSTD=	c++14
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OPENSSL_CFLAGS="-I${OPENSSLINC}" \
		OPENSSL_LIBS="-L${OPENSSLLIB} -lcrypto"

post-patch:
	@${REINPLACE_CMD} -e "/^Requires:/s,openssl ,," \
		${WRKSRC}/libopkele.pc.in
	@${REINPLACE_CMD} -e "s/-ltidy/-ltidy5/g" \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s/buffio.h/tidybuffio.h/g" \
		${WRKSRC}/include/opkele/tidy.h

.include <bsd.port.mk>
