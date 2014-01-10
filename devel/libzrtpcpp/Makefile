# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libzrtpcpp
PORTVERSION=	2.3.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=ccrtp

MAINTAINER=	acm@FreeBSD.org
COMMENT=	ZRTP extension for GNU ccRTP

LIB_DEPENDS=	libccrtp.so:${PORTSDIR}/devel/ccrtp \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

USES=		cmake iconv gettext pkgconfig
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CXXFLAGS+=	-I${LOCALBASE}/include -I${OPENSSLINC}
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-patch:
	@cd ${WRKSRC}/src && \
		${FIND} * -type f -exec ${REINPLACE_CMD} -i "" -e "s|<malloc.h>|<stdlib.h>|g" "{}" \; && \
			${FIND} * -type f -exec ${REINPLACE_CMD} -i "" -e "s|<stdint.h>|<inttypes.h>|g" "{}" \;
	@${REINPLACE_CMD} -e "s|int32_t dataLength);|int32_t dataLength)|g" \
		${WRKSRC}/src/libzrtpcpp/crypto/gcrypt/gcryptAesCFB.cpp

.include <bsd.port.mk>
