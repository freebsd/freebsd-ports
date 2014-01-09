# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	ccrtp
PORTVERSION=	2.0.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Implementation of the real-time transport protocol

LIB_DEPENDS=	libcommoncpp.so:${PORTSDIR}/devel/ucommon \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt

GNU_CONFIGURE=	yes
USES=		gmake gettext iconv pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -pthread"
CPPFLAGS+=	-I${LOCALBASE}/include
INFO=	ccrtp

post-patch:
	@cd ${WRKSRC}/src && \
		${FIND} * -type f -exec ${REINPLACE_CMD} -i "" -e "s|<malloc.h>|<stdlib.h>|g" "{}" \;

post-configure:
	${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
	    ${REINPLACE_CMD} -e 's|-l-pthread|-pthread|g'

.include <bsd.port.mk>
