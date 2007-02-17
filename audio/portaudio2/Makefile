# New ports collection makefile for:	portaudio
# Date created:		18 May 2003
# Whom:			michaelnottebrock@gmx.net and lioux@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	portaudio
PORTVERSION=	19.b${SNAPREV}
CATEGORIES=	audio
MASTER_SITES=	CSME
# svn export -rSNAPREV https://www.portaudio.com/repos/portaudio/branches/v19-devel

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Portable cross-platform Audio API

SNAPREV=	1175
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --without-alsa --without-jack --without-asihpi \
		--libdir=${PREFIX}/lib/${PORTNAME}2 --includedir=${PREFIX}/include/${PORTNAME}2
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}2

post-patch:
	@${GREP} -lre -lpthread ${WRKSRC}|${XARGS} ${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|'
	@${REINPLACE_CMD} -e '/pkgconfig/s|$$[(]libdir[)]|${PREFIX}/libdata|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
