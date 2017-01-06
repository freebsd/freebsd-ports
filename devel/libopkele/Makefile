# Created by: Sutra Zhou <zhoushuqun@gmail.com>
# $FreeBSD$

PORTNAME=	libopkele
PORTVERSION=	2.0.4
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://kin.klever.net/dist/

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	C++ implementation of an OpenID decentralized identity system

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libpcre.so:devel/pcre \
		libexpat.so:textproc/expat2 \
		libtidy.so:www/tidy-lib \
		libxslt.so:textproc/libxslt

USE_LDCONFIG=	yes
USES=		libtool gmake pathfix pkgconfig compiler:c++11-lang ssl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"OPENSSL_CFLAGS=${CFLAGS} -l${OPENSSLINC}" \
		OPENSSL_LIBS=-L${OPENSSLLIB}
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

# If we use the base OpenSSL either by default or
# by design, we need to remove the openssl dependency
# in pkgconfig/libopkele.pc.

.if ${SSL_DEFAULT} == base
post-patch:
	@ ${REINPLACE_CMD} -e "s|Requires: openssl|Requires:|" ${WRKSRC}/libopkele.pc.in
.endif

.include <bsd.port.post.mk>
