# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	xmms-timidity
PORTVERSION=	0.0.3
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.shikadi.net/utils/files/

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	XMMS input plugin to play midi files (via timidity)

LIB_DEPENDS=	libxmms.so:multimedia/xmms
RUN_DEPENDS=	timidity:audio/timidity

USE_LDCONFIG=	${PREFIX}/lib/xmms/Input

USES=		tar:bzip2
USE_GNOME=	gtk12
CXXFLAGS+=	-I${LOCALBASE}/include `glib-config --cflags` -g -fPIC

FILES=	xmms-timidity.cpp
PLIST_FILES=	lib/xmms/Input/libxmms-timidity.so

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} ${FILES} -o libxmms-timidity.so \
		-shared -pthread

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/Input
	${INSTALL_DATA} ${WRKSRC}/libxmms-timidity.so \
	    ${STAGEDIR}${PREFIX}/lib/xmms/Input/libxmms-timidity.so

.include <bsd.port.mk>
