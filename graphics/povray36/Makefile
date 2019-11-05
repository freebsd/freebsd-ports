# Created by: paulo@isr.uc.pt
# $FreeBSD$

PORTNAME=	povray
PORTVERSION=	3.6.1
PORTREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/%SUBDIR%/ \
		ftp://ftp.mirrorservice.org/sites/ftp.povray.org/pub/povray/%SUBDIR%/
MASTER_SITE_SUBDIR=	Old-Versions/Official-3.62/Unix
PKGNAMESUFFIX=	36
DIST_SUBDIR=	povray36

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Persistence of Vision Ray Tracer

LIB_DEPENDS=	libpng.so:graphics/png \
		libtiff.so:graphics/tiff

USES=		compiler:c11 gmake jpeg tar:bzip2 xorg
USE_XORG=	x11
GNU_CONFIGURE=	yes
USE_CXXSTD=	gnu++98

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS DOCS

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-3.6
DATADIR=	${PREFIX}/share/${PORTNAME}-3.6

.include <bsd.port.options.mk>
.include <bsd.port.pre.mk>

.if (${ARCH} == "i386" || ${ARCH} == "amd64")
LIB_DEPENDS+=	libvgagl.so:graphics/svgalib
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations
CXXFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -Wno-multichar
.if (${ARCH} == "i386" && !${ARCH} == "amd64" )
CFLAGS+=	-mfancy-math-387 -mpreferred-stack-boundary=3 -malign-double
CXXFLAGS+=	-mfancy-math-387 -mpreferred-stack-boundary=3 -malign-double
.endif # i386
CONFIGURE_ARGS=	--disable-optimiz
.endif

CONFIGURE_ARGS+=	--x-includes="${LOCALBASE}/include" --includedir=${LOCALBASE} \
		CXXFLAGS="${CXXFLAGS} -L${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS} -L${LOCALBASE}/lib" \
		LDFLAGS="-L${LOCALBASE}/lib" COMPILED_BY=${MAINTAINER} \
		--program-transform-name='s/${PORTNAME}/${PORTNAME}${PKGNAMESUFFIX}/'

.include <bsd.port.post.mk>
