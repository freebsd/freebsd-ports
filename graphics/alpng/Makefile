# Created by: Stas Timokhin <stast@bsdportal.ru>
# $FreeBSD$

PORTNAME=	alpng
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}13

MAINTAINER=	devel@stasyan.com
COMMENT=	Library for display PNG images in programs

LIB_DEPENDS=	liballeg.so:devel/allegro

HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}
MAKEFILE=	makefile
USES=		gmake
MAKE_ARGS=	CC="${CC}"
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	include/alpng.h \
		lib/libalpng.a

do-configure:
	@${REINPLACE_CMD} -e "s|gcc|${CC}|g" ${WRKSRC}/makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/libalpng.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/src/alpng.h ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>
