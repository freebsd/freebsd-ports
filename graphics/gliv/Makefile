# ports collection makefile for:	gliv
# Date created:				16 March 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	gliv
PORTVERSION=	1.7.1
CATEGORIES=	graphics
MASTER_SITES=	http://gliv.tuxfamily.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An image viewer that uses Gdk-Pixbuf and OpenGL

LIB_DEPENDS=	gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext
RUN_DEPENDS=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		gliv.1

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lXext -lX11 ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
