# ex:ts=8
# Ports collection makefile for:	vamos
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vamos
PORTVERSION=	0.4.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automotive simulation framework

BUILD_DEPENDS=	${X11BASE}/lib/libsgmisc.a:${PORTSDIR}/devel/simgear \
		${X11BASE}/lib/libplibul.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12 \
		sigc.1:${PORTSDIR}/devel/libsigc++ \
		glut.3:${PORTSDIR}/graphics/libglut \
		png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gnometarget lthack
USE_GL=		yes
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
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
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-lsgxml -lsgmisc|-lsgxml -lsgstructure -lsgmisc|g ; \
		 s|-pedantic||g'

.include <bsd.port.mk>
