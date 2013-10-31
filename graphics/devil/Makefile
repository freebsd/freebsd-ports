# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	devil
PORTVERSION=	1.7.8
PORTEPOCH=	1
PORTREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	SF/openil/DevIL/${PORTVERSION}
DISTNAME=	DevIL-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A full featured cross-platform image library

USES=		pkgconfig
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtool
ACLOCAL_ARGS=	-I m4 -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing --copy --force-missing
CONFIGURE_ARGS=	--enable-ILU \
		--disable-allegro --disable-directx8 --disable-directx9 \
		--without-libsquish
USE_LDCONFIG=	yes
USE_GCC=	any

WRKSRC=		${WRKDIR}/${DISTNAME:L}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	JPEG JASPER LCMS MNG PNG TIFF EXR X11 SDL NVTT SIMD DOCS
OPTIONS_DEFAULT=JPEG JASPER LCMS MNG PNG TIFF EXR X11 SDL NVTT DOCS
OPTIONS_DEFAULT_amd64=SIMD

JPEG_DESC=	Enable JPEG support
JASPER_DESC=	Enable JPEG2000 support
LCMS_DESC=	Enable LCMS support
MNG_DESC=	Enable MNG support
PNG_DESC=	Enable PNG support
TIFF_DESC=	Enable TIFF support
EXR_DESC=	Enable EXR support
X11_DESC=	Enable X11 support
SDL_DESC=	Enable SDL support
SQUISH_DESC=	Enable DXT compression via libsquish
NVTT_DESC=	Enable NVidia texture tools support
SIMD_DESC=	Enable SIMD autodetection (AltiVec, SSE3,...)

JPEG_LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg
JPEG_CONFIGURE_ENABLE=	jpeg
JASPER_LIB_DEPENDS=	libjasper.so:${PORTSDIR}/graphics/jasper
JASPER_CONFIGURE_ENABLE=jp2
LCMS_LIB_DEPENDS=	liblcms.so:${PORTSDIR}/graphics/lcms
LCMS_CONFIGURE_ENABLE=	lcms
MNG_LIB_DEPENDS=	libmng.so:${PORTSDIR}/graphics/libmng
MNG_CONFIGURE_ENABLE=	mng
PNG_LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
PNG_CONFIGURE_ENABLE=	png
TIFF_LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff
TIFF_CONFIGURE_ENABLE=	tiff
EXR_LIB_DEPENDS=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR
EXR_CONFIGURE_ENABLE=	exr
#SQUISH_BUILD_DEPENDS=	${LOCALBASE}/lib/libsquish.a:${PORTSDIR}/graphics/squish
#SQUISH_CONFIGURE_WITH=	libsquish
NVTT_LIB_DEPENDS=	libnvtt.so:${PORTSDIR}/graphics/nvidia-texture-tools
NVTT_CONFIGURE_WITH=	nvtt

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MPNG}
CONFIGURE_ENV+=	libpng_app=no
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
	@${RMDIR} ${STAGEDIR}${DATADIR}/examples
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS CREDITS ChangeLog Libraries.txt README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
