PORTNAME=	povray
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.0.8
PORTREVISION=	7
CATEGORIES=	graphics
PKGNAMESUFFIX=	37

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Persistence of Vision Ray Tracer

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		autoreconf:build compiler:c11 gmake
USE_GITHUB=	yes
GH_ACCOUNT=	POV-Ray

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	COMPILED_BY=${MAINTAINER} \
		--program-transform-name='s/povray/${PKGBASE}/' \
		--disable-optimiz

VERSION_BASE=	${PORTVERSION:C/([0-9]+\.[0-9]+).*/\1/}
DATADIR=	${PREFIX}/share/${PORTNAME}-${VERSION_BASE}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${VERSION_BASE}
ETCDIR=		${PREFIX}/etc/${PORTNAME}/${VERSION_BASE}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}-${VERSION_BASE}

OPTIONS_DEFINE=	X11 PNG JPEG TIFF OPENEXR STATIC IO EXAMPLES DOCS
OPTIONS_DEFAULT=PNG JPEG
OPTIONS_SUB=	yes

DOCS_DESC=	Install HTML documentation
EXAMPLES_DESC=	Install example scenes
IO_DESC=	Without I/O restrictions (security risk)

IO_CONFIGURE_ON=	--disable-io-restrictions
STATIC_CONFIGURE_ON=	--enable-static
X11_USES=		sdl xorg
X11_USE=		XORG=xpm,sm,ice,x11 SDL=sdl
X11_CONFIGURE_OFF=	--without-x

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPNG}
.if ${PORT_OPTIONS:MSTATIC}
BUILD_DEPENDS+=	png>=1.4:graphics/png
.else
LIB_DEPENDS+=	libpng.so:graphics/png
.endif
.else
CONFIGURE_ARGS+=--without-libpng
.endif

.if ${PORT_OPTIONS:MJPEG}
.if ${PORT_OPTIONS:MSTATIC}
USES+=		jpeg:build
.else
USES+=		jpeg
.endif
.else
CONFIGURE_ARGS+=--without-libjpeg
.endif

.if ${PORT_OPTIONS:MTIFF}
.if ${PORT_OPTIONS:MSTATIC}
BUILD_DEPENDS+=	tiff>=4:graphics/tiff
.else
LIB_DEPENDS+=	libtiff.so:graphics/tiff
.endif
.else
CONFIGURE_ARGS+=--without-libtiff
.endif

.if ${PORT_OPTIONS:MOPENEXR}
.if ${PORT_OPTIONS:MSTATIC}
BUILD_DEPENDS+=	openexr>=1.6:graphics/openexr
.else
LIB_DEPENDS+=	libOpenEXR.so:graphics/openexr libImath.so:math/Imath
CPPFLAGS+=	-I${LOCALBASE}/include/OpenEXR -I${LOCALBASE}/include/Imath -DInt64=uint64_t
.endif
.else
CONFIGURE_ARGS+=--without-openexr
.endif

.if !${PORT_OPTIONS:MPNG} || !${PORT_OPTIONS:MJPEG} || !${PORT_OPTIONS:MTIFF}
CONFIGURE_ARGS+=NON_REDISTRIBUTABLE_BUILD=yes
.endif

PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
	${REINPLACE_CMD} -e 's|@@EXAMPLESDIR@@|${EXAMPLESDIR}|' \
		-e 's|@@ETCDIR@@|${ETCDIR}|' \
		${WRKSRC}/unix/povray.conf

pre-configure:
	cd ${WRKSRC}/unix && ./prebuild.sh

pre-build:
.if ${PORT_OPTIONS:MSTATIC} && ${PORT_OPTIONS:MTIFF}
#	graphics/tiff adds dependencies on libjpeg, libjbig and liblzma
	@${REINPLACE_CMD} -e 's,^\(LIBS = .*\)-ltiff\(.*\),\1-ltiff -ljpeg -ljbig -llzma\2,' ${WRKSRC}/unix/Makefile
.endif

post-install:
	${MV} ${STAGEDIR}${DATADIR}/scenes ${STAGEDIR}${EXAMPLESDIR}
.for i in povray.conf povray.ini
	${MV} ${STAGEDIR}${ETCDIR}/${i} ${STAGEDIR}${ETCDIR}/${i}.sample
.endfor

.include <bsd.port.mk>
