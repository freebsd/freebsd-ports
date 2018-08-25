# $FreeBSD$

PORTNAME=	kdegraphics
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphics utilities for KDE (meta port)

USES=		kde:5 metaport qt:5
USE_QT=		#

OPTIONS_DEFINE=	GPHOTO \
		GWENVIEW \
		KCOLORCHOOSER \
		KOLOURPAINT \
		KRULER \
		MOBIPOCKET \
		SKANLITE \
		SPECTACLE \
		SVG \
		THUMBNAILER

OPTIONS_DEFAULT=		${OPTIONS_DEFINE}

GPHOTO_DESC=			Digital camera manager
GPHOTO_RUN_DEPENDS=		kamera>=${KDE_APPLICATIONS_VERSION}:graphics/kamera

GWENVIEW_DESC=			Image viewer and browser
GWENVIEW_RUN_DEPENDS=		gwenview>=${KDE_APPLICATIONS_VERSION}:graphics/gwenview

KCOLORCHOOSER_DESC=		Utility for colors selection
KCOLORCHOOSER_RUN_DEPENDS=	kcolorchooser>=${KDE_APPLICATIONS_VERSION}:graphics/kcolorchooser

KOLOURPAINT_DESC=		Paint application
KOLOURPAINT_RUN_DEPENDS=	kolourpaint>=${KDE_APPLICATIONS_VERSION}:graphics/kolourpaint

KRULER_DESC=			Screen ruler
KRULER_RUN_DEPENDS=		kruler>=${KDE_APPLICATIONS_VERSION}:deskutils/kruler

SKANLITE_DESC=			Simple scanning application
SKANLITE_RUN_DEPENDS=		skanlite>=2.1:graphics/skanlite

SPECTACLE_DESC=			Screen capture program
SPECTACLE_RUN_DEPENDS=		spectacle>=${KDE_APPLICATIONS_VERSION}:graphics/spectacle

MOBIPOCKET_DESC=		Mobipocket plugins for Strigi indexing and thumbnailers
MOBIPOCKET_RUN_DEPENDS=		kdegraphics-mobipocket>=${KDE_APPLICATIONS_VERSION}:graphics/kdegraphics-mobipocket

SVG_DESC=			SVG KPart
SVG_RUN_DEPENDS=		kdegraphics-svgpart>=${KDE_APPLICATIONS_VERSION}:graphics/kdegraphics-svgpart

THUMBNAILER_DESC=		Thumbnail generator for graphics file formats
THUMBNAILER_RUN_DEPENDS=	kdegraphics-thumbnailers>=${KDE_APPLICATIONS_VERSION}:graphics/kdegraphics-thumbnailers

.include <bsd.port.mk>
