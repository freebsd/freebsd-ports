# Created by: Sutra Zhou <zhoushuqun@gmail.com>
# $FreeBSD$

PORTNAME=	libopkele
PORTVERSION=	2.0.4
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://kin.klever.net/dist/

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	A c++ implementation of an OpenID decentralized identity system

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libtidy.so:${PORTSDIR}/www/tidy-lib \
		libxslt.so:${PORTSDIR}/textproc/libxslt

USE_LDCONFIG=	yes
USE_GCC=	4.6
USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"OPENSSL_CFLAGS=${CFLAGS} -l${OPENSSLINC}" \
		OPENSSL_LIBS=-L${OPENSSLLIB}
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

# This port needs OpenSSL 0.9.8b which is present in 7.0 and up
USE_OPENSSL=	yes

.include <bsd.port.pre.mk>

.include "${PORTSDIR}/Mk/bsd.openssl.mk"

# If we use the base OpenSSL either by default or
# by design, we need to remove the openssl dependency
# in pkgconfig/libopkele.pc.

post-patch:
	@ ${REINPLACE_CMD} -e "s|pkgconfigdir =.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|g" \
	    ${WRKSRC}/Makefile.in
.if !defined(WITH_OPENSSL_PORT)
	@ ${REINPLACE_CMD} -e "s|Requires: openssl|Requires:|" ${WRKSRC}/libopkele.pc.in
.endif

.include <bsd.port.post.mk>
