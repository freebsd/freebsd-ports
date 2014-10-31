# Created by: ijliao
# $FreeBSD$

PORTNAME=	kludge3d
PORTVERSION=	20040822
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/source/2004-08-22

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple 3D editor

LIB_DEPENDS=	lib3ds.so:${PORTSDIR}/graphics/lib3ds \
		libgtkglext-x11-1.0.so:${PORTSDIR}/x11-toolkits/gtkglext

USES=		gmake pkgconfig python
USE_GL=		gl
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lib-GL

PLIST_FILES=	bin/kludge3d

CPPFLAGS+=	-I${LOCALBASE}/include \
		-I${PYTHON_INCLUDEDIR} ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib \
		-L${PYTHON_LIBDIR}/config -lm ${PTHREAD_LIBS}

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@EXTRA_CFLAGS@|@CFLAGS@|g ; \
		 s| install-pixmapsDATA||g ; \
		 s|-lpthread||g'

.include <bsd.port.mk>
