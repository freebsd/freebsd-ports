# New ports collection makefile for:	libopkele
# Date created:				28 November 2007
# Whom:					Sutra Zhou <zhoushuqun@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libopkele
PORTVERSION=	2.0
CATEGORIES=	devel
MASTER_SITES=	http://kin.klever.net/dist/

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	A c++ implementation of an OpenID decentralized identity system

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost
LIB_DEPENDS=	curl.4:${PORTSDIR}/ftp/curl \
		pcre.0:${PORTSDIR}/devel/pcre \
		expat.6:${PORTSDIR}/textproc/expat2 \
		tidy:${PORTSDIR}/www/tidy-lib \
		xslt:${PORTSDIR}/textproc/libxslt

USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"OPENSSL_CFLAGS=${CFLAGS} -l${OPENSSLINC}" \
		OPENSSL_LIBS=-L${OPENSSLLIB} \
		CPPFLAGS=-I${LOCALBASE}/include

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	"-L${LOCALBASE}/lib"

# This port needs OpenSSL 0.9.8b which is present in 7.0 and up
.if !exists(/usr/include/openssl/store.h)
WITH_OPENSSL_PORT=      yes
.endif

# If we use the base OpenSSL either by default or
# by design, we need to remove the openssl dependency
# in pkgconfig/libopkele.pc.

post-patch:
	@ ${REINPLACE_CMD} -e "s|pkgconfigdir =.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|g" \
	    ${WRKSRC}/Makefile.in
.if !defined(WITH_OPENSSL_PORT)
	@ ${REINPLACE_CMD} -e "s|Requires: openssl|Requires:|" ${WRKSRC}/libopkele.pc.in
.endif

.include <bsd.port.mk>
