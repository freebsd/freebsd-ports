PORTNAME=	povray
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7.0.10
PORTREVISION=	22
CATEGORIES=	graphics
PKGNAMESUFFIX=	37

MAINTAINER=	bsd@philippost.de
COMMENT=	Persistence of Vision Ray Tracer
WWW=		https://www.povray.org/

LICENSE=	AGPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		autoreconf:build compiler:c11 gmake
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	POV-Ray

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	COMPILED_BY=${HOSTARCH}-portbld-${OPSYS:tl}-${OSREL:R} \
		--program-transform-name='s/povray/${PKGBASE}/' \
		--disable-optimiz
CPPFLAGS+=	-D POVMSUCS2="char16_t"
CPPFLAGS+=	-D UCS2="char16_t"
CPPFLAGS+=	-D UCS4="char32_t"

VERSION_BASE=	${PORTVERSION:C/([0-9]+\.[0-9]+).*/\1/}
ETCDIR=		${PREFIX}/etc/${PORTNAME}/${VERSION_BASE}
DATADIR=	${PREFIX}/share/${PORTNAME}-${VERSION_BASE}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${VERSION_BASE}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}-${VERSION_BASE}

OPTIONS_DEFINE=	X11 PNG JPEG TIFF OPENEXR IO EXAMPLES DOCS
OPTIONS_DEFAULT=PNG JPEG
OPTIONS_SUB=	yes

IO_DESC=	Without I/O restrictions (security risk)

IO_CONFIGURE_ON=	--disable-io-restrictions

JPEG_USES=		jpeg
JPEG_CONFIGURE_OFF=	--without-libjpeg

OPENEXR_LIB_DEPENDS=	libImath.so:math/Imath \
			libOpenEXR.so:graphics/openexr
OPENEXR_CONFIGURE_WITH=	openexr

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_WITH=	libpng

TIFF_LIB_DEPENDS=	libtiff.so:graphics/tiff
TIFF_CONFIGURE_WITH=	libtiff

X11_USES=		sdl xorg
X11_USE=		XORG=xpm,sm,ice,x11 SDL=sdl
X11_CONFIGURE_OFF=	--without-x

.include <bsd.port.options.mk>

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

post-install:
	${MV} ${STAGEDIR}${DATADIR}/scenes ${STAGEDIR}${EXAMPLESDIR}
.for i in povray.conf povray.ini
	${MV} ${STAGEDIR}${ETCDIR}/${i} ${STAGEDIR}${ETCDIR}/${i}.sample
.endfor

.include <bsd.port.mk>
