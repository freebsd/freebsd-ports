# ex:ts=8
# Ports collection makefile for:	vamos
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vamos
PORTVERSION=	0.5.5
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automotive simulation framework

BUILD_DEPENDS=	${X11BASE}/lib/libplibul.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	cppunit-1.10.2:${PORTSDIR}/devel/cppunit \
		sigc-1.2.5:${PORTSDIR}/devel/libsigc++12 \
		glut.4:${PORTSDIR}/graphics/libglut \
		png.5:${PORTSDIR}/graphics/png

USE_GL=		yes
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		MAKEINFO="makeinfo --no-split"
CONFIGURE_ARGS=	--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib
INSTALLS_SHLIB=	yes

INFO=		vamos

CPPFLAGS=	-I${LOCALBASE}/include/libpng -I${LOCALBASE}/include \
		-I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lusbhid \
		${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on 4.x (port and dependencies need recent C++ compiler)"
.endif

post-extract:
	@${RM} -f ${WRKSRC}/doc/*.info*

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-pedantic -O1 -g -gstabs+||g ; \
		 s|-ldl||g'
	@${REINPLACE_CMD} -e 's|freeglut|glut|g ; \
		 s|FREEGLUT|GLUT|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
