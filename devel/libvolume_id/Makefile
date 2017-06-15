# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvolume_id
PORTVERSION=	0.81.1
CATEGORIES=	devel
MASTER_SITES=	http://www.marcuscom.com/downloads/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to provide file system type information

LICENSE=	GPLv2

USES=		gmake tar:bzip2
USE_LDCONFIG=	yes
MAKE_ENV=	E=@${TRUE} RANLIB=${RANLIB} AR=${AR} Q= \
		prefix=${PREFIX}

PLIST_FILES=	include/libvolume_id.h \
		lib/libvolume_id.a \
		lib/libvolume_id.so \
		lib/libvolume_id.so.0 \
		libdata/pkgconfig/libvolume_id.pc

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/libvolume_id.pc
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.h ${STAGEDIR}${PREFIX}/include/libvolume_id.h
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.a ${STAGEDIR}${PREFIX}/lib/libvolume_id.a
	${INSTALL_PROGRAM} ${WRKSRC}/libvolume_id.so.0 ${STAGEDIR}${PREFIX}/lib/libvolume_id.so.0
	${LN} -sf ${PREFIX}/lib/libvolume_id.so.0 ${STAGEDIR}${PREFIX}/lib/libvolume_id.so

.include <bsd.port.mk>
