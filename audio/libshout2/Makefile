# New ports collection makefile for:	libshout
# Date created:				06 Jun 2000
# Whom:					zach@pabst.bendnet.com
#
# $FreeBSD$
#

PORTNAME=	libshout2
PORTVERSION=	2.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio net
MASTER_SITES=	http://downloads.xiph.org/releases/libshout/
DISTNAME=	libshout-${PORTVERSION}

MAINTAINER=	lofi@freebsd.org
COMMENT=	Routines for connecting and transmitting data to the icecast server

LIB_DEPENDS=	speex.3:${PORTSDIR}/audio/speex \
		theora.1:${PORTSDIR}/multimedia/libtheora \
		vorbis.3:${PORTSDIR}/audio/libvorbis

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_GNOME+=	pkgconfig
GNU_CONFIGURE=  yes
CONFLICTS=	libshout-1.0.7

pre-configure:
	@ ${REINPLACE_CMD} -e "s|-ffast-math||g" ${WRKSRC}/configure

post-configure:
	@ ${REINPLACE_CMD} -e "s|pkgconfigdir =.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|g" \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
