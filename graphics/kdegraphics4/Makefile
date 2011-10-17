# New ports collection Makefile for:	kdegraphics
# Date created:				2008-01-31
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdegraphics
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphics utilities for KDE 4 (meta-port)

RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/mobithumbnail.so:${PORTSDIR}/graphics/kdegraphics4-mobipocket \
		${KDE4_PREFIX}/lib/strigi/strigiea_dvi.so:${PORTSDIR}/graphics/kdegraphics4-strigi-analyzer \
		${KDE4_PREFIX}/lib/kde4/svgpart.so:${PORTSDIR}/graphics/kdegraphics4-svgpart \
		${KDE4_PREFIX}/lib/kde4/gsthumbnail.so:${PORTSDIR}/graphics/kdegraphics4-thumbnailers

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	kdeprefix
NO_BUILD=	yes

OPTIONS=	GPHOTO2 "Digital camera manager" on \
		GWENVIEW "Image viewer and browser" on \
		KCOLORCHOOSER "Utility for colors selection" on \
		KGAMMA "Monitor calibration tool" on \
		KRULER "Screen ruler" on \
		KOLOURPAINT "Paint application" on \
		KSNAPSHOT "Screen capture program" on \
		OKULAR "Universal document viewer" on \
		SANE "Plugin for scanning on KDE" on

.include <bsd.port.options.mk>

.ifndef(WITHOUT_GPHOTO2)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/kio_kamera.so:${PORTSDIR}/graphics/kamera-kde4
.endif

.ifndef(WITHOUT_GWENVIEW)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/gwenview:${PORTSDIR}/graphics/gwenview-kde4
.endif

.ifndef(WITHOUT_KCOLORCHOOSER)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kcolorchooser:${PORTSDIR}/graphics/kcolorchooser
.endif

.ifndef(WITHOUT_KGAMMA)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/xf86gammacfg:${PORTSDIR}/x11/kgamma
.endif

.ifndef(WITHOUT_KRULER)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kruler:${PORTSDIR}/deskutils/kruler
.endif

.ifndef(WITHOUT_KOLOURPAINT)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kolourpaint:${PORTSDIR}/graphics/kolourpaint
.endif

.ifndef(WITHOUT_KSNAPSHOT)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/ksnapshot:${PORTSDIR}/graphics/ksnapshot
.endif

.ifndef(WITHOUT_OKULAR)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/okular:${PORTSDIR}/graphics/okular
.endif

.ifndef(WITHOUT_SANE)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/ksaneplugin.so:${PORTSDIR}/graphics/ksaneplugin
.endif

do-install:
	${DO_NADA}

.include <bsd.port.mk>
