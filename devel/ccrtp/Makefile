# New ports collection makefile for:	ccrtp
# Date created:		2006-04-22
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	ccrtp
PORTVERSION=	1.7.1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Implementation of the real-time transport protocol

LIB_DEPENDS=	ccgnu2-1.7.0:${PORTSDIR}/devel/commoncpp

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
INFO=	ccrtp

post-patch:
	@cd ${WRKSRC}/src && \
		${FIND} * -type f -exec ${REINPLACE_CMD} -i "" -e "s|<malloc.h>|<stdlib.h>|g" "{}" \;

.include <bsd.port.mk>
