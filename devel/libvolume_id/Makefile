# New ports collection makefile for:	libvolume_id
# Date created:		04 November 2006
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libvolume_id
PORTVERSION=	0.81.0
CATEGORIES=	devel
MASTER_SITES=	http://www.marcuscom.com/downloads/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library to provide file system type information

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
MAKE_ENV=	E=${ECHO_MSG} RANLIB=${RANLIB} AR=${AR} Q=@ \
		prefix=${PREFIX}

PLIST_FILES=	include/libvolume_id.h \
		lib/libvolume_id.a \
		lib/libvolume_id.so \
		lib/libvolume_id.so.0 \
		libdata/pkgconfig/libvolume_id.pc

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.pc ${PREFIX}/libdata/pkgconfig/libvolume_id.pc
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.h ${PREFIX}/include/libvolume_id.h
	${INSTALL_DATA} ${WRKSRC}/libvolume_id.a ${PREFIX}/lib/libvolume_id.a
	${INSTALL_PROGRAM} ${WRKSRC}/libvolume_id.so.0 ${PREFIX}/lib/libvolume_id.so.0
	${LN} -sf ${PREFIX}/lib/libvolume_id.so.0 ${PREFIX}/lib/libvolume_id.so

.include <bsd.port.post.mk>
