# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kdegraphics
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphics utilities for KDE 4 (meta port)

RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/mobithumbnail.so:${PORTSDIR}/graphics/kdegraphics4-mobipocket \
		${KDE4_PREFIX}/lib/strigi/strigiea_dvi.so:${PORTSDIR}/graphics/kdegraphics4-strigi-analyzer \
		${KDE4_PREFIX}/lib/kde4/svgpart.so:${PORTSDIR}/graphics/kdegraphics4-svgpart \
		${KDE4_PREFIX}/lib/kde4/gsthumbnail.so:${PORTSDIR}/graphics/kdegraphics4-thumbnailers

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	kdeprefix
NO_BUILD=	yes

OPTIONS_DEFINE=	GPHOTO GWENVIEW KCOLORCHOOSER KGAMMA KRULER \
		KOLOURPAINT KSNAPSHOT OKULAR SANE
OPTIONS_DEFAULT=${OPTIONS_DEFINE}

GPHOTO_DESC=		Digital camera manager
GWENVIEW_DESC=		Image viewer and browser
KCOLORCHOOSER_DESC=	Utility for colors selection
KGAMMA_DESC=		Monitor calibration tool
KRULER_DESC=		Screen ruler
KOLOURPAINT_DESC=	Paint application
KSNAPSHOT_DESC=		Screen capture program
OKULAR_DESC=		Universal document viewer
SANE_DESC=		Plugin for scanning on KDE

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGPHOTO}
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/kio_kamera.so:${PORTSDIR}/graphics/kamera-kde4
.endif

.if ${PORT_OPTIONS:MGWENVIEW}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/gwenview:${PORTSDIR}/graphics/gwenview-kde4
.endif

.if ${PORT_OPTIONS:MKCOLORCHOOSER}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kcolorchooser:${PORTSDIR}/graphics/kcolorchooser
.endif

.if ${PORT_OPTIONS:MKGAMMA}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/xf86gammacfg:${PORTSDIR}/x11/kgamma
.endif

.if ${PORT_OPTIONS:MKRULER}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kruler:${PORTSDIR}/deskutils/kruler
.endif

.if ${PORT_OPTIONS:MKOLOURPAINT}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kolourpaint:${PORTSDIR}/graphics/kolourpaint
.endif

.if ${PORT_OPTIONS:MKSNAPSHOT}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/ksnapshot:${PORTSDIR}/graphics/ksnapshot
.endif

.if ${PORT_OPTIONS:MOKULAR}
USE_KDE4+=	okular_run
.endif

.if ${PORT_OPTIONS:MSANE}
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/ksaneplugin.so:${PORTSDIR}/graphics/ksaneplugin
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
