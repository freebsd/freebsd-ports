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

MESAVERSION=	${MESABASEVERSION}${MESASUBVERSION:C/^(.)/.\1/}
MESADISTVERSION=${MESABASEVERSION}${MESASUBVERSION:C/^(.)/-\1/}

.if defined(WITH_NEW_XORG)
MESABASEVERSION=	7.11.2
# if there is a subversion, include the '-' between 7.11-rc2 for example.
MESASUBVERSION=		
PLIST_SUB+=	OLD="@comment " NEW=""
.else
MESABASEVERSION=	7.6.1
MESASUBVERSION=		
PLIST_SUB+=	OLD="" NEW="@comment "
.endif

MASTER_SITES=	ftp://ftp.freedesktop.org/pub/mesa/${MESABASEVERSION}/:mesa,glut
DISTFILES=	MesaLib-${MESADISTVERSION}${EXTRACT_SUFX}:mesa
MAINTAINER?=	x11@FreeBSD.org

BUILD_DEPENDS+=	makedepend:${PORTSDIR}/devel/makedepend \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2

USE_BISON=	build
USE_PYTHON_BUILD=yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--enable-gallium-llvm=no --without-gallium-drivers \
		--disable-egl --disable-glut

.if defined(WITH_NEW_XORG)
EXTRA_PATCHES+=	${PATCHDIR}/extra-configure \
		${PATCHDIR}/extra-mach64_context.h \
		${PATCHDIR}/extra-sis_context.h \
		${PATCHDIR}/extra-src-glsl_ir_constant_expression.cpp \
		${PATCHDIR}/extra-src__gallium__include__pipe__p_config.h \
		${PATCHDIR}/extra-src__mesa__drivers__dri__nouveau__nouveau_array.c \
		${PATCHDIR}/extra-src__mesa__drivers__dri__nouveau__nouveau_render_t.c \
		${PATCHDIR}/extra-src__mesa__drivers__dri__radeon__radeon_span.c
.else
EXTRA_PATCHES+=	${PATCHDIR}/extra-configure-old \
		${PATCHDIR}/extra-mach64_context.h-old \
		${PATCHDIR}/extra-src__mesa__x86-64__glapi_x86-64.S \
		${PATCHDIR}/extra-src__mesa__x86-64__xform4.S \
		${PATCHDIR}/extra-src__mesa__x86__glapi_x86.S \
		${PATCHDIR}/extra-src__mesa__x86__read_rgba_span_x86.S
.endif

ALL_TARGET=		default

PATCHDIR=		${.CURDIR}/../../graphics/libGL/files
WRKSRC=			${WRKDIR}/Mesa-${MESABASEVERSION}${MESASUBVERSION}

.if !defined(ARCH)
ARCH!=			uname -p
.endif

COMPONENT=		${PORTNAME:L:C/^lib//:C/mesa-//}

.if ${COMPONENT:Mglu} == ""
CONFIGURE_ARGS+=	--disable-glu
.endif

.if ${COMPONENT:Mglw} == ""
CONFIGURE_ARGS+=	--disable-glw
.else
CONFIGURE_ARGS+=	--enable-motif
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
.if defined(WITH_NEW_XORG)
# replace hardlinks with patched radeon_span.c
.for i in r200 r300 r600
	@${CP} -fp ${WRKSRC}/src/mesa/drivers/dri/radeon/radeon_span.c \
		${WRKSRC}/src/mesa/drivers/dri/${i}/
.endfor
.endif
.if ${COMPONENT:Mglut} != ""
	@${REINPLACE_CMD} -e 's|[$$](INSTALL_LIB_DIR)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/src/glut/glx/Makefile
.endif
