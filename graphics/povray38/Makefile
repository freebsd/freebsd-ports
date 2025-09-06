PORTNAME=	povray
DISTVERSIONPREFIX=	v
DISTVERSION=	3.8.0-beta.2
PORTREVISION=	20
CATEGORIES=	graphics
MASTER_SITES=	https://github.com/POV-Ray/povray/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
PKGNAMESUFFIX=	38
DISTNAME=	povunix-${DISTVERSIONPREFIX}${DISTVERSION}-src

MAINTAINER=	bsd@philippost.de
COMMENT=	Persistence of Vision Ray Tracer v3.8.0 Beta 2
WWW=		https://www.povray.org/

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		compiler:c++14-lang gmake
USE_CXXSTD=	c++14

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

WRKSRC=		${WRKDIR}/${DISTNAME}
VERSION_BASE=	${DISTVERSION:C/([0-9]+\.[0-9]+).*/\1/}

DATADIR=	${PREFIX}/share/${PORTNAME}-${VERSION_BASE}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${VERSION-BASE}
ETCDIR=		${PREFIX}/etc/${PORTNAME}/${VERSION_BASE}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}-${VERSION_BASE}

CONFIGURE_ARGS=	--disable-optimiz \
		--program-transform-name='s/povray/${PKGBASE}/' \
		COMPILED_BY=${HOSTARCH}-portbld-${OPSYS:tl}-${OSREL:R}
CPPFLAGS+=	-D UCS2="char16_t"
CPPFLAGS+=	-D UCS4="char32_t"

OPTIONS_DEFINE=		DOCS EXAMPLES IO JPEG OPENEXR PNG TIFF \
			X11
OPTIONS_DEFAULT=	JPEG PNG TIFF
OPTIONS_SUB=		yes

IO_DESC=		Without I/O restrictions (security risk)

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
X11_USE=		SDL=sdl \
			XORG=ice,sm,x11,xpm
X11_CONFIGURE_OFF=	--without-x

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
