# ports collection makefile for:	gliv
# Date created:				16 March 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	gliv
PORTVERSION=	1.5.2
CATEGORIES=	graphics
MASTER_SITES=	http://gliv.tuxfamily.org/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/bin/Magick-config:${PORTSDIR}/graphics/ImageMagick
LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt \
		gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea
RUN_DEPENDS=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		GDK_PIXBUF_CONFIG=${X11BASE}/bin/gdk-pixbuf-config \
		MAGICK_CONFIG=${LOCALBASE}/bin/Magick-config
CONFIGURE_ARGS=	--disable-gtk2
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		gliv.1

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lXext -lX11 -lgnugetopt

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
