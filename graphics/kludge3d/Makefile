# ex:ts=8
# Ports collection makefile for:	kludge3d
# Date created:			May 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	kludge3d
PORTVERSION=	20040822
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple 3d editor

LIB_DEPENDS=	3ds.1:${PORTSDIR}/graphics/lib3ds \
		gtkglext-x11-1.0.2:${PORTSDIR}/x11-toolkits/gtkglext

USE_PYTHON=	yes
USE_GL=		yes
USE_GNOME=	gnometarget gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-lib-GL

PLIST_FILES=	bin/kludge3d

CPPFLAGS=	-I${LOCALBASE}/include -L${X11BASE}/include \
		-I${PYTHON_INCLUDEDIR} ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib \
		-L${PYTHON_LIBDIR}/config ${PTHREAD_LIBS}

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@EXTRA_CFLAGS@|@CFLAGS@|g ; \
		 s| install-pixmapsDATA||g ; \
		 s|-lpthread||g'

.include <bsd.port.mk>
