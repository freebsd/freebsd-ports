# ex:ts=8
# Ports collection makefile for:	vamos
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vamos
PORTVERSION=	0.3.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automotive simulation framework

BUILD_DEPENDS=	${X11BASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear \
		${X11BASE}/lib/libplibul.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	sigc.1:${PORTSDIR}/devel/libsigc++

USE_MESA=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${X11BASE}/lib -lGL -lGLU -lglut ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} 's|std::fixed << ||g' ${WRKSRC}/vamos/Vamos_Car.cc

.include <bsd.port.mk>
