# ex:ts=8
# Ports collection makefile for:	vamos
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vamos
PORTVERSION=	0.1.11
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${X11BASE}/lib/libplibul.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	sigc:${PORTSDIR}/devel/libsigc++

USE_MESA=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${X11BASE}/lib ${PTHREAD_LIBS} -lGL -lGLU -lglut"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
