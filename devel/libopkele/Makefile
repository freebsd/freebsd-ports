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

# Required version of OpenSSL for this build
OPENSSL_SHLIBVER=5
# If we use the base OpenSSL either by default or
# by design, we need to remove the openssl dependency
# in pkgconfig/libopkele.pc. For the moment, the only
# way I kan think of is to check for 7.0 with OpenSSL 0.9.8b
# and not WITH_OPENSSL_PORT. As 6 requires the port, add this
# as a dependency instead.

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 700019 )
    WITH_OPENSSL_PORT=yes
.endif

post-patch:
	@ ${REINPLACE_CMD} -e "s|pkgconfigdir =.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|g" \
	    ${WRKSRC}/Makefile.in
.if !defined(WITH_OPENSSL_PORT)
	@ ${REINPLACE_CMD} -e "s|Requires: openssl|Requires:|" ${WRKSRC}/libopkele.pc.in
.endif

.include <bsd.port.post.mk>
