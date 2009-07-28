# New ports collection makefile for:	libopkele
# Date created:				28 November 2007
# Whom:					Sutra Zhou <zhoushuqun@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libopkele
PORTVERSION=	2.0.2
CATEGORIES=	devel
MASTER_SITES=	http://kin.klever.net/dist/

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	A c++ implementation of an OpenID decentralized identity system

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl \
		pcre.0:${PORTSDIR}/devel/pcre \
		expat.6:${PORTSDIR}/textproc/expat2 \
		tidy:${PORTSDIR}/www/tidy-lib \
		xslt:${PORTSDIR}/textproc/libxslt

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"OPENSSL_CFLAGS=${CFLAGS} -l${OPENSSLINC}" \
		OPENSSL_LIBS=-L${OPENSSLLIB} \
		CPPFLAGS=-I${LOCALBASE}/include

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	"-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

# This port needs OpenSSL 0.9.8b which is present in 7.0 and up
USE_OPENSSL=	yes
.if ${OSVERSION} < 700000
WITH_OPENSSL_PORT=      yes
.endif
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
