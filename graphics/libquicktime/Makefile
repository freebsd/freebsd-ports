# ex:ts=8
# Ports collection makefile for:	libquicktime
# Date Created:			Jul 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libquicktime
PORTVERSION=	0.9.1
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A library for reading and writing quicktime files

LIB_DEPENDS=	vorbis.2:${PORTSDIR}/audio/libvorbis \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		dv.2:${PORTSDIR}/graphics/libdv \
		png.5:${PORTSDIR}/graphics/png

USE_MESA=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN1=	lqtplay.1

CFLAGS+=	-O0

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS=".*-O3|CFLAGS="\$$CFLAGS|g ; \
		 s|CFLAGS=".*-O6|CFLAGS="\$$CFLAGS|g' ${WRKSRC}/configure

.include <bsd.port.mk>
