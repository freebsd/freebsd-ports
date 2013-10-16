# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	lprof
PORTVERSION=	20080514
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/ \
		LOCAL/amdmi3
PKGNAMESUFFIX=	-devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open source color profiler

LIB_DEPENDS=	liblcms.so:${PORTSDIR}/graphics/lcms \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libvigraimpex.so:${PORTSDIR}/graphics/vigra

USE_BZIP2=	yes
USE_XORG=	x11 xext sm ice xxf86vm
USE_QT4=	corelib gui qt3support assistantclient \
		linguist_build qmake_build moc_build uic_build rcc_build
USES=		cmake

CMAKE_ARGS=	-DQTTRANS_LRELEASE_EXECUTABLE="${LOCALBASE}/bin/lrelease-qt4"

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e '/asm\/types.h/ d' ${WRKSRC}/src/argyll/spectro/hidio.c
	@${REINPLACE_CMD} -e '/DESTINATION/ s|data/|share/${PORTNAME}/data/|' \
		${WRKSRC}/data/CMakeLists.txt ${WRKSRC}/src/CMakeLists.txt

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/icons/lprof.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
