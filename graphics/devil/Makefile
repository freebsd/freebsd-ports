# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=	devil
PORTVERSION=	1.7.8
PORTREVISION=	25
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/openil/DevIL/${PORTVERSION}
DISTNAME=	DevIL-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Full featured cross-platform image library

USES=		alias autoreconf gmake libtool localbase pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ILU --enable-ILUT \
		--disable-allegro --disable-directx8 --disable-directx9 \
		--without-libsquish
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:tl}

PORTDOCS=	*

# With EXR the library is not usable from plain C (instant segfault)
OPTIONS_DEFINE=	JPEG JASPER LCMS MNG PNG TIFF EXR X11 SDL NVTT SIMD DOCS
OPTIONS_DEFAULT=JPEG JASPER LCMS MNG PNG TIFF X11 SDL NVTT
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

JPEG_USES=		jpeg
JPEG_CONFIGURE_ENABLE=	jpeg
JASPER_LIB_DEPENDS=	libjasper.so:graphics/jasper
JASPER_CONFIGURE_ENABLE=jp2
LCMS_LIB_DEPENDS=	liblcms.so:graphics/lcms
LCMS_CONFIGURE_ENABLE=	lcms
MNG_LIB_DEPENDS=	libmng.so:graphics/libmng
MNG_CONFIGURE_ENABLE=	mng
PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_ENABLE=	png
PNG_CONFIGURE_OFF=	libpng_app=no
TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_ENABLE=	tiff
EXR_LIB_DEPENDS=	libIlmImf.so:graphics/openexr
EXR_CONFIGURE_ENABLE=	exr
#SQUISH_BUILD_DEPENDS=	${LOCALBASE}/lib/libsquish.a:graphics/squish
#SQUISH_CONFIGURE_WITH=	libsquish
NVTT_LIB_DEPENDS=	libnvtt.so:graphics/nvidia-texture-tools
NVTT_CONFIGURE_WITH=	nvtt
X11_USES=		gl xorg
X11_USE=		GL=gl,glu,glut XORG=x11,xext,xmu,xi,xrender,sm,ice
X11_CONFIGURE_OFF=	--disable-opengl --disable-x11 --disable-xpm --disable-shm --disable-render
SDL_USES=		sdl
SDL_USE=		SDL=sdl
SDL_CONFIGURE_OFF=	--disable-sdl
SIMD_CONFIGURE_OFF=	--disable-altivec --disable-sse --disable-sse2 --disable-sse3

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|docs||g' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e '/^pkgdir=/s|$$(libdir)/|$$(prefix)/libdata/|g' \
		${WRKSRC}/data/Makefile.am
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' \
		${WRKSRC}/src-ILU/ilur/ilur.c

post-install:
	@${RMDIR} ${STAGEDIR}${DATADIR}/examples
	@${RMDIR} ${STAGEDIR}${DATADIR}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in AUTHORS CREDITS ChangeLog Libraries.txt README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

do-test:
	cd ${WRKSRC}/test && ${MAKE_CMD} testil
	cd ${WRKSRC}/test && ${SH} format_test/format_checks.sh

.include <bsd.port.mk>
