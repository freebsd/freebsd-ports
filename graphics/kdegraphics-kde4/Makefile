# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdegraphics
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	graphics kde
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphics utilities for KDE 4 (meta port)

USES=		kde:4 metaport

OPTIONS_DEFINE=	GPHOTO \
		GWENVIEW \
		KCOLORCHOOSER \
		KGAMMA \
		KOLOURPAINT \
		KRULER \
		KSNAPSHOT \
		MOBIPOCKET \
		SANE \
		STRIGI \
		SVG \
		THUMBNAILER
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}

GPHOTO_DESC=		Digital camera manager
GPHOTO_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/kio_kamera.so:graphics/kamera-kde4

GWENVIEW_DESC=		Image viewer and browser
GWENVIEW_RUN_DEPENDS=	${KDE_PREFIX}/bin/gwenview:graphics/gwenview-kde4

KCOLORCHOOSER_DESC=	Utility for colors selection
KCOLORCHOOSER_RUN_DEPENDS=	${KDE_PREFIX}/bin/kcolorchooser:graphics/kcolorchooser-kde4

KGAMMA_DESC=		Monitor calibration tool
KGAMMA_RUN_DEPENDS=	${KDE_PREFIX}/bin/xf86gammacfg:x11/kgamma-kde4

KOLOURPAINT_DESC=	Paint application
KOLOURPAINT_RUN_DEPENDS=	${KDE_PREFIX}/bin/kolourpaint:graphics/kolourpaint-kde4

KRULER_DESC=		Screen ruler
KRULER_RUN_DEPENDS=	${KDE_PREFIX}/bin/kruler:deskutils/kruler-kde4

KSNAPSHOT_DESC=		Screen capture program
KSNAPSHOT_RUN_DEPENDS=	${KDE_PREFIX}/bin/ksnapshot:graphics/ksnapshot-kde4

MOBIPOCKET_DESC=	Mobipocket plugins for Strigi indexing and thumbnailers
MOBIPOCKET_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/mobithumbnail.so:graphics/kdegraphics-mobipocket-kde4 \

SANE_DESC=		Plugin for scanning on KDE
SANE_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/ksaneplugin.so:graphics/ksaneplugin-kde4

STRIGI_DESC=		Strigi analyzers for graphics file formats
STRIGI_RUN_DEPENDS=	${KDE_PREFIX}/lib/strigi/strigiea_dvi.so:graphics/kdegraphics-strigi-analyzer-kde4

SVG_DESC=		SVG KPart
SVG_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/svgpart.so:graphics/kdegraphics-svgpart-kde4

THUMBNAILER_DESC=	Thumbnail generator for graphics file formats
THUMBNAILER_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/gsthumbnail.so:graphics/kdegraphics-thumbnailers-kde4

.include <bsd.port.mk>
