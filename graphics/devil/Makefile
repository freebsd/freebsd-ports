# New ports collection makefile for:   devil
# Date created:        8 August 2004
# Whom:                Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=	devil
PORTVERSION=	1.7.8
PORTEPOCH=	1
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/openil
DISTNAME=	DevIL-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A full featured cross-platform image library

OPTIONS=	JPEG	"Enable JPEG support"		on \
		JASPER	"Enable JPEG2000 support"	on \
		LCMS	"Enable LCMS support"		on \
		MNG	"Enable MNG support"		on \
		PNG	"Enable PNG support"		on \
		TIFF	"Enable TIFF support"		on \
		X11	"Enable X11 support"		on \
		SDL	"Enable SDL support"		off \
		NVTT	"Enable NVidia texture tools support" off

WRKSRC=		${WRKDIR}/${DISTNAME:L}

USE_GNOME=	pkgconfig
USE_AUTOTOOLS=	aclocal:110 autoheader:262 automake:110 autoconf:262 libtool:22
ACLOCAL_ARGS=	-I m4 -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing --copy --force-missing
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-ILU \
		--disable-allegro --disable-directx8 --disable-directx9 \
		--disable-altivec --disable-sse --disable-sse2 --disable-sse3
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if defined(WITHOUT_JPEG)
CONFIGURE_ARGS+=--disable-jpeg
.else
LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg
CONFIGURE_ARGS+=--enable-jpeg
.endif

.if defined(WITHOUT_JASPER)
CONFIGURE_ARGS+=--disable-jp2
.else
LIB_DEPENDS+=	jasper.4:${PORTSDIR}/graphics/jasper
CONFIGURE_ARGS+=--enable-jp2
.endif

.if defined(WITHOUT_LCMS)
CONFIGURE_ARGS+=--disable-lcms
.else
LIB_DEPENDS+=	lcms.1:${PORTSDIR}/graphics/lcms
CONFIGURE_ARGS+=--enable-lcms
.endif

.if defined(WITHOUT_MNG)
CONFIGURE_ARGS+=--disable-mng
.else
LIB_DEPENDS+=	mng.1:${PORTSDIR}/graphics/libmng
CONFIGURE_ARGS+=--enable-mng
.endif

.if defined(WITHOUT_PNG)
CONFIGURE_ENV+=	libpng_app=no
CONFIGURE_ARGS+=--disable-png
.else
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png
.endif

.if defined(WITHOUT_TIFF)
CONFIGURE_ARGS+=--disable-tiff
.else
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff
CONFIGURE_ARGS+=--enable-tiff
.endif

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=--disable-opengl --disable-x11 --disable-xpm --disable-shm
PLIST_SUB+=	X11="@comment "
.else
USE_GL=		glut
CONFIGURE_ARGS+=--enable-ILUT
PLIST_SUB+=	X11=""
.endif

.if defined(WITH_SDL)
USE_SDL=	sdl
.else
CONFIGURE_ARGS+=--disable-sdl
.endif

.if defined(WITH_NVTT)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libnvtt.so:${PORTSDIR}/graphics/nvidia-texture-tools
RUN_DEPENDS+=	${LOCALBASE}/lib/libnvtt.so:${PORTSDIR}/graphics/nvidia-texture-tools
LDFLAGS+=	${PTHREAD_LIBS}
.else
CONFIGURE_ARGS+=--without-nvtt
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|docs||g' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e '/^pkgdir=/s|$$(libdir)/|$$(prefix)/libdata/|g' \
		${WRKSRC}/data/Makefile.am
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' \
		${WRKSRC}/src-ILU/ilur/ilur.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS CREDITS ChangeLog Libraries.txt README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
