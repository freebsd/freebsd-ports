# ex:ts=8
# Ports collection makefile for:	vamos
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vamos
PORTVERSION=	0.2.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/lib/libplibul.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	sigc:${PORTSDIR}/devel/libsigc++

USE_MESA=	yes
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${X11BASE}/lib -lGL -lGLU -lglut ${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} 's|std::fixed << ||g' ${WRKSRC}/vamos/Vamos_Car.cc

.include <bsd.port.mk>
