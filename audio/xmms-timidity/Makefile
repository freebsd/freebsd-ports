# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	xmms-timidity
PORTVERSION=	0.0.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.shikadi.net/utils/files/

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	XMMS input plugin to play midi files (via timidity)

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

USE_LDCONFIG=	${PREFIX}/lib/xmms/Input
NO_STAGE=	yes

USE_BZIP2=	yes
USE_GNOME=	gtk12
CXXFLAGS+=	-I${LOCALBASE}/include `glib-config --cflags` -g -fPIC

FILES=	xmms-timidity.cpp
PLIST_FILES=	lib/xmms/Input/libxmms-timidity.so

do-build:
	(cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -c ${FILES} -o xmms-timidity.o)

.include <bsd.port.mk>
