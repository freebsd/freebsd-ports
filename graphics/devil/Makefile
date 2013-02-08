# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	devil
PORTVERSION=	1.7.8
PORTEPOCH=	1
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	SF/openil/DevIL/${PORTVERSION}
DISTNAME=	DevIL-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A full featured cross-platform image library

OPTIONS_DEFINE=	JPEG JASPER LCMS MNG PNG TIFF X11 SDL NVTT SIMD DOCS
OPTIONS_DEFAULT=JPEG JASPER LCMS MNG PNG TIFF X11 DOCS

JPEG_DESC=	Enable JPEG support
JASPER_DESC=	Enable JPEG2000 support
LCMS_DESC=	Enable LCMS support
MNG_DESC=	Enable MNG support
PNG_DESC=	Enable PNG support
TIFF_DESC=	Enable TIFF support
X11_DESC=	Enable X11 support
SDL_DESC=	Enable SDL support
NVTT_DESC=	Enable NVidia texture tools support
SIMD_DESC=	Enable SIMD autodetection (AltiVec, SSE3,...)

WRKSRC=		${WRKDIR}/${DISTNAME:L}

USE_GCC=	any
USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtool
ACLOCAL_ARGS=	-I m4 -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing --copy --force-missing
CONFIGURE_ARGS=	--enable-ILU \
		--disable-allegro --disable-directx8 --disable-directx9
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJPEG}
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=--enable-jpeg
.else
CONFIGURE_ARGS+=--disable-jpeg
.endif

.if ${PORT_OPTIONS:MJASPER}
LIB_DEPENDS+=	jasper.4:${PORTSDIR}/graphics/jasper
CONFIGURE_ARGS+=--enable-jp2
.else
CONFIGURE_ARGS+=--disable-jp2
.endif

.if ${PORT_OPTIONS:MLCMS}
LIB_DEPENDS+=	lcms.1:${PORTSDIR}/graphics/lcms
CONFIGURE_ARGS+=--enable-lcms
.else
CONFIGURE_ARGS+=--disable-lcms
.endif

.if ${PORT_OPTIONS:MMNG}
LIB_DEPENDS+=	mng.1:${PORTSDIR}/graphics/libmng
CONFIGURE_ARGS+=--enable-mng
.else
CONFIGURE_ARGS+=--disable-mng
.endif

.if ${PORT_OPTIONS:MPNG}
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
.else
CONFIGURE_ENV+=	libpng_app=no
CONFIGURE_ARGS+=--disable-png
.endif

.if ${PORT_OPTIONS:MTIFF}
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=--enable-tiff
.else
CONFIGURE_ARGS+=--disable-tiff
.endif

.if ${PORT_OPTIONS:MX11}
USE_GL=		glut
CONFIGURE_ARGS+=--enable-ILUT
PLIST_SUB+=	X11=""
.else
CONFIGURE_ARGS+=--disable-opengl --disable-x11 --disable-xpm --disable-shm
PLIST_SUB+=	X11="@comment "
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
.else
CONFIGURE_ARGS+=--disable-sdl
.endif

.if ${PORT_OPTIONS:MNVTT}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libnvtt.so:${PORTSDIR}/graphics/nvidia-texture-tools
RUN_DEPENDS+=	${LOCALBASE}/lib/libnvtt.so:${PORTSDIR}/graphics/nvidia-texture-tools
.else
CONFIGURE_ARGS+=--without-nvtt
.endif

.if ! ${PORT_OPTIONS:MSIMD}
CONFIGURE_ARGS+=--disable-altivec --disable-sse --disable-sse2 --disable-sse3
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|docs||g' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e '/^pkgdir=/s|$$(libdir)/|$$(prefix)/libdata/|g' \
		${WRKSRC}/data/Makefile.am
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' \
		${WRKSRC}/src-ILU/ilur/ilur.c

post-install:
	@${RMDIR} ${DATADIR}/examples
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS CREDITS ChangeLog Libraries.txt README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
