PORTNAME=	povray
DISTVERSIONPREFIX=	v
DISTVERSION=	3.8.0-beta.2
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/POV-Ray/povray/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
PKGNAMESUFFIX=	38
DISTNAME=	povunix-${DISTVERSIONPREFIX}${DISTVERSION}-src

MAINTAINER=	bsd@philippost.de
COMMENT=	Persistence of Vision Ray Tracer v3.8.0 Beta 2

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		compiler:c++11-lang gmake

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name='s/povray/${PKGBASE}/' \
		COMPILED_BY=${MAINTAINER}

VERSION_BASE=	${PORTVERSION:C/([0-9]+\.[0-9]+).*/\1/}
DATADIR=	${PREFIX}/share/${PORTNAME}-${VERSION_BASE}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${VERSION-BASE}
ETCDIR=		${PREFIX}/etc/${PORTNAME}/${VERSION_BASE}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}-${VERSION_BASE}

OPTIONS_DEFINE=		DOCS EXAMPLES IO JPEG OPENEXR OPTIMIZED_CFLAGS PNG TIFF \
			X11
OPTIONS_DEFAULT=	JPEG PNG TIFF
OPTIONS_SUB=		yes

DOCS_DESC=	Install HTML documentation
EXAMPLES_DESC=	Install example scenes
IO_DESC=	Without I/O restrictions (security risk)

IO_CONFIGURE_ON=	--disable-io-restrictions

JPEG_USES=		jpeg
JPEG_CONFIGURE_OFF=	--without-libjpeg

OPENEXR_LIB_DEPENDS=	libImath.so:math/Imath \
			libOpenEXR.so:graphics/openexr
OPENEXR_CONFIGURE_ON=	--with-openexr
OPENEXR_CONFIGURE_OFF=	--without-openexr

OPTIMIZED_CFLAGS_CONFIGURE_OFF=	--disable-optimiz
OPTIMIZED_CFLAGS_CFLAGS=	-march=native

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_ON=	--with-libpng
PNG_CONFIGURE_OFF=	--without-libpng

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_ON=	--with-libtiff
TIFF_CONFIGURE_OFF=	--without-libtiff

X11_USES=		sdl xorg
X11_USE=		SDL=sdl \
			XORG=ice,sm,x11,xpm
X11_CONFIGURE_OFF=	--without-x

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MJPEG} || !${PORT_OPTIONS:MPNG} || !${PORT_OPTIONS:MTIFF}
CONFIGURE_ARGS+=	NON_REDISTRIBUTABLE_BUILD=yes
.endif

post-install:
	${MV} ${STAGEDIR}${DATADIR}/scenes ${STAGEDIR}${EXAMPLESDIR}
.for file in povray.conf povray.ini
	${MV} ${STAGEDIR}${ETCDIR}/${file} ${STAGEDIR}${ETCDIR}/${file}.sample
.endfor

.include <bsd.port.mk>
