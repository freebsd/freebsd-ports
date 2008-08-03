# New ports collection makefile for:	lprof
# Date created:		09 Jan 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	lprof
PORTVERSION=	20080514
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.amdmi3.ru/distfiles/ \
		${MASTER_SITE_LOCAL:S|%SUBDIR%|amdmi3|}
PKGNAMESUFFIX=	-devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open source color profiler

LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		vigraimpex.2:${PORTSDIR}/graphics/vigra \
		usb-0.1.8:${PORTSDIR}/devel/libusb

USE_BZIP2=	yes
USE_XORG=	x11 xext sm ice xxf86vm
USE_QT_VER=	4
QT_COMPONENTS=	corelib gui qt3support assistantclient moc uic rcc qmake linguist
USE_CMAKE=	yes

CMAKE_ARGS=	-DQTTRANS_LRELEASE_EXECUTABLE="${LOCALBASE}/bin/lrelease-qt4"
CMAKE_USE_PTHREAD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '/asm\/types.h/ d' ${WRKSRC}/src/argyll/spectro/hidio.c
	@${REINPLACE_CMD} -e '/DESTINATION/ s|data/|share/${PORTNAME}/data/|' \
		${WRKSRC}/data/CMakeLists.txt ${WRKSRC}/src/CMakeLists.txt

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/icons/lprof.png ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
