# New ports collection makefile for:	vorbis-xmms
# Date created:				18 October 2000
# Whom:					t.vanklaveren@student.utwente.nl
#
# $FreeBSD$
#

PORTNAME=	vorbis-xmms
PORTVERSION=	20001018
CATEGORIES=	audio
MASTER_SITES=	http://home.student.utwente.nl/t.vanklaveren/distfiles/
DISTNAME=	vorbis-plugins-${PORTVERSION}

MAINTAINER=	t.vanklaveren@student.utwente.nl

LIB_DEPENDS=	ogg.0:${PORTSDIR}/audio/libogg \
		vorbis.0:${PORTSDIR}/audio/libvorbis \
		xmms.1:${PORTSDIR}/audio/xmms

USE_X_PREFIX=	yes
USE_GTK=	yes
WRKSRC=		${WRKDIR}/vorbis-plugins

do-build:
	cd ${WRKSRC}/xmms && ${CC} ${CFLAGS} -fPIC -c vorbis.c -I${LOCALBASE}/include `${GTK_CONFIG} --cflags`
	cd ${WRKSRC}/xmms && ${CC} ${LDFLAGS} -fPIC -Wl,-export-dynamic -Wl,-shared -o libvorbis.so vorbis.o `${GTK_CONFIG} --libs` -lxmms -lvorbis -lvorbisfile -logg -pthread

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmms/libvorbis.so ${PREFIX}/lib/xmms/Input/

.include <bsd.port.mk>
