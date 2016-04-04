# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	lprof
PORTVERSION=	20080514
PORTREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/ \
		LOCAL/amdmi3
PKGNAMESUFFIX=	-devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open source color profiler

LIB_DEPENDS=	liblcms.so:graphics/lcms \
		libtiff.so:graphics/tiff \
		libvigraimpex.so:graphics/vigra

USES=		cmake desktop-file-utils jpeg tar:bzip2
USE_XORG=	x11 xext sm ice xxf86vm
USE_QT4=	corelib gui qt3support svg assistantclient \
		linguisttools_build qmake_build moc_build uic_build rcc_build

CMAKE_ARGS=	-DQTTRANS_LRELEASE_EXECUTABLE="${LOCALBASE}/bin/lrelease-qt4"

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/asm\/types.h/ d' ${WRKSRC}/src/argyll/spectro/hidio.c
	@${REINPLACE_CMD} -e '/DESTINATION/ s|data/|share/${PORTNAME}/data/|' \
		${WRKSRC}/data/CMakeLists.txt ${WRKSRC}/src/CMakeLists.txt

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/icons/lprof.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
