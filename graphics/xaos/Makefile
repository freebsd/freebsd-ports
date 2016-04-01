# Created by: Joseph Koshy <koshy@india.hp.com>
# $FreeBSD$

PORTNAME=	xaos
PORTVERSION=	3.6
PORTREVISION=	2
CATEGORIES=	graphics math
MASTER_SITES=	SF/${PORTNAME}/XaoS/${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Real-time fractal browser

LIB_DEPENDS=	libpng.so:graphics/png \
		libgsl.so:math/gsl

USES=		gmake
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	THREADS NLS
OPTIONS_MULTI=	DRIVER
OPTIONS_MULTI_DRIVER=	AALIB GTK2 X11
DRIVER_DESC=	User Interface
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=	yes

AALIB_LIB_DEPENDS=	libaa.so:graphics/aalib
AALIB_CONFIGURE_WITH=	aa-driver
AALIB_CONFIGURE_ON=	ac_cv_aalib_ver_ok=yes

GTK2_DESC=	GTK+ User Interface (experimental)
GTK2_USE=	GNOME=gtk20
GTK2_USES=	pkgconfig
GTK2_CONFIGURE_WITH=	gtk-driver

X11_USE=	XORG=x11,xext
X11_CONFIGURE_WITH=	x11-driver x

NLS_USES=	gettext iconv
NLS_CONFIGURE_ENABLE=	nls

THREADS_DESC=	Enable SMP support (experimental)
THREADS_CONFIGURE_WITH=	pthread
THREADS_LIBS=	-lpthread

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

INFO=		xaos

PLIST_SUB+=	XAOSDIR="share/XaoS"

MAKE_JOBS_UNSAFE=	yes
DESKTOP_ENTRIES=	"XaoS" "" "${PREFIX}/share/pixmaps/xaos.png" \
			"xaos" "" false

pre-configure:
	${REINPLACE_CMD} -e 's,/usr\(/share/locale\),${PREFIX}\1,g' \
		${WRKSRC}/configure \
		${WRKSRC}/src/ui/ui.c
	${REINPLACE_CMD} 's,malloc.h,stdlib.h,' \
		${WRKSRC}/src/ui/ui-drv/aa/ui_aa.c

post-install:
	${INSTALL_DATA}	${WRKSRC}/src/ui/ui-drv/qt/images/xaosbig.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/xaos.png

.include <bsd.port.mk>
