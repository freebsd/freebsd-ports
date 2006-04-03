# ports collection makefile for:	kudu
# Date created:		28 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	kudu
PORTVERSION=	0.0.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	amdmi3@mail.ru
COMMENT=	A 3D skeletal animation tool, powered by GTK+ and OpenGL

LIB_DEPENDS=	gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext

USE_GL=		yes
USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GCC=	3.4+

CFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib" \
		LIBS="${PTHREAD_LIBS} -lcompat"

DESKTOP_ENTRIES="Kudu" \
		"Edit 3D models" \
		"${DATADIR}/images/logo.png" \
		"kudu" \
		"Application;Graphics;" \
		true

post-patch:
	@${REINPLACE_CMD} -e 's|COPYING||' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
