# ex:ts=8
# Ports collection makefile for:	vamos
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vamos
PORTVERSION=	0.4.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automotive simulation framework

BUILD_DEPENDS=	${X11BASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear \
		${X11BASE}/lib/libplibul.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12 \
		sigc.1:${PORTSDIR}/devel/libsigc++ \
		png.5:${PORTSDIR}/graphics/png

USE_MESA=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		MAKEINFO="makeinfo --no-split"
INSTALLS_SHLIB=	yes

INFO=		vamos

CPPFLAGS=	-I${LOCALBASE}/include/libpng -I${X11BASE}/include \
		${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lGL -lGLU -lglut \
		${PTHREAD_LIBS}

post-extract:
	@${RM} -f ${WRKSRC}/doc/*.info*

post-patch:
	@${REINPLACE_CMD} -e '/^CXXFLAGS/d' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		'/^AM_CXXFLAGS/d'

.include <bsd.port.mk>
