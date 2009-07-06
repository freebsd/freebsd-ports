# New ports collection makefile for:	libshout
# Date created:				06 Jun 2000
# Whom:					Zach Zurflu <zach@pabst.bendnet.com>
#
# $FreeBSD$
#

PORTNAME=	libshout2
PORTVERSION=	2.2.2
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	audio net
MASTER_SITES=	http://downloads.xiph.org/releases/libshout/
DISTNAME=	libshout-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Connect and transmit data to an Icecast media streaming server

LIB_DEPENDS=	speex.1:${PORTSDIR}/audio/speex \
		theora.0:${PORTSDIR}/multimedia/libtheora \
		vorbis.4:${PORTSDIR}/audio/libvorbis

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
USE_LDCONFIG=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_GNOME+=	pkgconfig
GNU_CONFIGURE=	yes
CONFLICTS=	libshout-1.0.7
DOCSDIR=	${PREFIX}/share/doc/libshout

pre-configure:
	@${REINPLACE_CMD} -e "s|-ffast-math||g" ${WRKSRC}/configure

post-configure:
	@${REINPLACE_CMD} -e "s|pkgconfigdir =.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|g" \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
