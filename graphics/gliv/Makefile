# ports collection makefile for:	gliv
# Date created:				16 March 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	gliv
PORTVERSION=	1.6
CATEGORIES=	graphics
MASTER_SITES=	http://gliv.tuxfamily.org/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An image viewer that uses Gdk-Pixbuf and OpenGL

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		gtkgl-2.0.1:${PORTSDIR}/x11-toolkits/gtkglarea2
RUN_DEPENDS=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=		gliv.1

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lXext -lX11 -lgnugetopt \
		${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|LDFLAGS="[\$$]CFLAGS|LDFLAGS="\$$LDFLAGS|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
