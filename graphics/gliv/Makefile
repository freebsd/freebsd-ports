# ports collection makefile for:	gliv
# Date created:				16 March 2001
# Whom:					Jeremy Norris <ishmael27@home.com>
#
# $FreeBSD$
#

PORTNAME=	gliv
PORTVERSION=	1.3.1
CATEGORIES=	graphics
MASTER_SITES=	http://gliv.tuxfamily.org/

MAINTAINER=	ishmael27@home.com

LIB_DEPENDS=	Imlib2.1:${PORTSDIR}/graphics/imlib2 \
		gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GTK=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -lgnugetopt -L${X11BASE}/lib \
			-lGLU -lGL -lXext -lX11 -lm ${PTHREAD_LIBS}"

MAN1=		gliv.1

post-patch:
	@${PERL} -pi -e 's|gtk-config|${GTK_CONFIG}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
