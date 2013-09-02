# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	ccrtp
PORTVERSION=	2.0.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Implementation of the real-time transport protocol

LIB_DEPENDS=	commoncpp:${PORTSDIR}/devel/ucommon

GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -pthread"
CPPFLAGS+=	-I${LOCALBASE}/include
INFO=	ccrtp

BROKEN=		does not build

post-patch:
	@cd ${WRKSRC}/src && \
		${FIND} * -type f -exec ${REINPLACE_CMD} -i "" -e "s|<malloc.h>|<stdlib.h>|g" "{}" \;

.include <bsd.port.mk>
