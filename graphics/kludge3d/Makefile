# ex:ts=8
# Ports collection makefile for:	kludge3d
# Date created:			May 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	kludge3d
PORTVERSION=	20020301
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtkgl:${PORTSDIR}/x11-toolkits/gtkglarea \
		3ds:${PORTSDIR}/graphics/lib3ds

USE_LIBTOOL=	yes
USE_GTK=	yes
USE_MESA=	yes
USE_XLIB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	\
	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}"  \
	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS} -lm -lX11 -lXext"
USE_GMAKE=	yes

.include <bsd.port.mk>
