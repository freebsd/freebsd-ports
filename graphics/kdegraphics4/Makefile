# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdegraphics
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphics utilities for KDE 4 (meta port)

USE_KDE4=	kdeprefix
USES=		metaport

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
GPHOTO_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/kio_kamera.so:graphics/kamera-kde4

GWENVIEW_DESC=		Image viewer and browser
GWENVIEW_RUN_DEPENDS=	${KDE4_PREFIX}/bin/gwenview:graphics/gwenview-kde4

KCOLORCHOOSER_DESC=	Utility for colors selection
KCOLORCHOOSER_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kcolorchooser:graphics/kcolorchooser

KGAMMA_DESC=		Monitor calibration tool
KGAMMA_RUN_DEPENDS=	${KDE4_PREFIX}/bin/xf86gammacfg:x11/kgamma

KOLOURPAINT_DESC=	Paint application
KOLOURPAINT_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kolourpaint:graphics/kolourpaint

KRULER_DESC=		Screen ruler
KRULER_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kruler:deskutils/kruler

KSNAPSHOT_DESC=		Screen capture program
KSNAPSHOT_RUN_DEPENDS=	${KDE4_PREFIX}/bin/ksnapshot:graphics/ksnapshot

MOBIPOCKET_DESC=	Mobipocket plugins for Strigi indexing and thumbnailers
MOBIPOCKET_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/mobithumbnail.so:graphics/kdegraphics4-mobipocket \

SANE_DESC=		Plugin for scanning on KDE
SANE_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/ksaneplugin.so:graphics/ksaneplugin

STRIGI_DESC=		Strigi analyzers for graphics file formats
STRIGI_RUN_DEPENDS=	${KDE4_PREFIX}/lib/strigi/strigiea_dvi.so:graphics/kdegraphics4-strigi-analyzer

SVG_DESC=		SVG KPart
SVG_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/svgpart.so:graphics/kdegraphics4-svgpart

THUMBNAILER_DESC=	Thumbnail generator for graphics file formats
THUMBNAILER_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/gsthumbnail.so:graphics/kdegraphics4-thumbnailers

.include <bsd.port.mk>
