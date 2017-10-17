# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	ccrtp
PORTVERSION=	2.0.9
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Implementation of the real-time transport protocol

LIB_DEPENDS=	libcommoncpp.so:devel/ucommon \
		libgcrypt.so:security/libgcrypt

GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib gmake gettext libtool localbase iconv pkgconfig
USE_LDCONFIG=	yes

INFO=		ccrtp

post-patch:
	@cd ${WRKSRC}/src && \
		${FIND} * -type f -exec ${REINPLACE_CMD} -i "" -e "s|<malloc.h>|<stdlib.h>|g" {} \;

post-configure:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e 's|-l-pthread|-pthread|g'

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libccrtp.so.2.0.6

.include <bsd.port.mk>
