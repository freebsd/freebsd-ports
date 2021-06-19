# Created by: ijliao

PORTNAME=	kludge3d
PORTVERSION=	20040822
PORTREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/source/2004-08-22

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple 3D editor

LIB_DEPENDS=	lib3ds.so:graphics/lib3ds \
		libgtkglext-x11-1.0.so:x11-toolkits/gtkglext

USES=		compiler:c++11-lang gl gmake gnome pkgconfig python
USE_GL=		gl
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lib-GL

PLIST_FILES=	bin/kludge3d

CPPFLAGS+=	-I${LOCALBASE}/include -I${PYTHON_INCLUDEDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${PYTHON_LIBDIR}/config -lpthread -lm

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@EXTRA_CFLAGS@|@CFLAGS@|g ; \
		 s| install-pixmapsDATA||g ; \
		 s|-lpthread||g'

.include <bsd.port.mk>
