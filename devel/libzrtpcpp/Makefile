# New ports collection makefile for:	libzrtpcpp
# Date created:		2006-10-04
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libzrtpcpp
PORTVERSION=	2.3.2
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=ccrtp

MAINTAINER=	acm@FreeBSD.org
COMMENT=	ZRTP extension for GNU ccRTP

LIB_DEPENDS=	ccrtp:${PORTSDIR}/devel/ccrtp \
		gcrypt.18:${PORTSDIR}/security/libgcrypt

USE_CMAKE=	yes
USE_OPENSSL=	yes
WITH_OPENSSL_PORT=yes

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS:BOOL=ON
CXXFLAGS+=	-I${LOCALBASE}/include -I${OPENSSLINC}
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}
USE_LDCONFIG=	yes

post-patch:
	@cd ${WRKSRC}/src && \
		${FIND} * -type f -exec ${REINPLACE_CMD} -i "" -e "s|<malloc.h>|<stdlib.h>|g" "{}" \; && \
			${FIND} * -type f -exec ${REINPLACE_CMD} -i "" -e "s|<stdint.h>|<inttypes.h>|g" "{}" \;
	@${REINPLACE_CMD} -e "s|int32_t dataLength);|int32_t dataLength)|g" \
		${WRKSRC}/src/libzrtpcpp/crypto/gcrypt/gcryptAesCFB.cpp

.include <bsd.port.mk>
