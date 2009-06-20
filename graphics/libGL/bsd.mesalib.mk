#-*- mode: Fundamental; tab-width: 4; -*-
# ex:ts=4
#
# bsd.mesa.mk - an attempt to refactor MesaLib ports.
#
# Created by: Florent Thoumie <flz@FreeBSD.org>
#
# !!! Here be dragons !!! (they seem to be everywhere these days)
#
# Remember to upgrade the following ports everytime you bump MESAVERSION:
#
#    - graphics/libGL
#    - graphics/libGLU
#    - graphics/libGLw
#    - graphics/dri
#
# $FreeBSD$
#

MESAVERSION=	7.4.3
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.fu-berlin.de/pub/unix/X11/graphics/Mesa/
MASTER_SITE_SUBDIR=	mesa3d
DISTFILES=	MesaLib-${MESAVERSION}${EXTRACT_SUFX}
MAINTAINER?=	x11@FreeBSD.org

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib

ALL_TARGET=	default

#MAKE_ARGS=	SHELL=${SH}
#CFLAGS+=	-DUSE_XSHM -DHZ=100

#FILESDIR=	${.CURDIR}/../../graphics/libGL/files
WRKSRC=		${WRKDIR}/Mesa-${MESAVERSION}

.if !defined(ARCH)
ARCH!=		uname -p
.endif

.if ${ARCH} == alpha
FAST_MATH=
.else
FAST_MATH=      -ffast-math
.endif

COMPONENT=	${PORTNAME:L:C/^lib//:C/mesa-//}

.if ${COMPONENT:Mglut} == ""
. if ${COMPONENT:Mglu} == ""
CONFIGURE_ARGS+=	--disable-glu --disable-glut
. else
CONFIGURE_ARGS+=	--disable-glut
. endif
.else
DISTFILES+=	MesaGLUT-${MESAVERSION}${EXTRACT_SUFX}
.endif

.if ${COMPONENT:Mglw} == ""
CONFIGURE_ARGS+=	--disable-glw
.else
CONFIGURE_ARGS+=	--enable-motif
.endif

.if ${COMPONENT:Mdemos} == ""
CONFIGURE_ARGS+=	--with-demos=no
.else
DISTFILES+=	MesaDemos-${MESAVERSION}${EXTRACT_SUFX}
CONFIGURE_ARGS+=	--with-demos=demos,xdemos
.endif

.if ${COMPONENT:Mdri} == ""
CONFIGURE_ARGS+=	--with-dri-drivers=no
.endif

.if defined(WITHOUT_XCB)
CONFIGURE_ARGS+=	--disable-xcb
.else
CONFIGURE_ARGS+=	--enable-xcb
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-ffast-math|${FAST_MATH}|' -e 's|x86_64|amd64|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|[$$](INSTALL_LIB_DIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/src/glu/Makefile \
		${WRKSRC}/src/glw/Makefile \
		${WRKSRC}/src/mesa/Makefile \
		${WRKSRC}/src/mesa/drivers/dri/Makefile
.if ${COMPONENT:Mglut} != ""
	@${REINPLACE_CMD} -e 's|[$$](INSTALL_LIB_DIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/src/glut/glx/Makefile
.endif
.if ${COMPONENT:Mdemos} != ""
	@${REINPLACE_CMD} -e 's|../images/|${DATADIR}/images/|g' \
		-e 's|geartrain.dat|${DATADIR}/data/geartrain.dat|g' \
		-e 's|terrain.dat|${DATADIR}/data/terrain.dat|g' \
		-e 's|isosurf.dat|${DATADIR}/data/isosurf.dat|g' \
			${WRKSRC}/progs/demos/*.c ${WRKSRC}/progs/xdemos/*.c
.endif
