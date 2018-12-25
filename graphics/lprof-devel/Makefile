# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	lprof
PORTVERSION=	20080514
PORTREVISION=	14
CATEGORIES=	graphics
MASTER_SITES=	http://mirror.amdmi3.ru/distfiles/ \
		LOCAL/amdmi3
PKGNAMESUFFIX=	-devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Open source color profiler

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

LIB_DEPENDS=	liblcms.so:graphics/lcms \
		libtiff.so:graphics/tiff \
		libvigraimpex.so:graphics/vigra

USES=		cmake:insource compiler:c++11-lang desktop-file-utils jpeg qt:4 tar:bzip2
USE_XORG=	x11 xext sm ice xxf86vm
USE_QT=		corelib gui qt3support svg assistantclient \
		linguisttools_build qmake_build moc_build uic_build rcc_build

WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/asm\/types.h/ d' ${WRKSRC}/src/argyll/spectro/hidio.c
	@${REINPLACE_CMD} -e '/DESTINATION/ s|data/|share/${PORTNAME}/data/|' \
		${WRKSRC}/data/CMakeLists.txt ${WRKSRC}/src/CMakeLists.txt
# Patch in the correct prefix of the Qt binaries into the sources.
	@${REINPLACE_CMD} -e 's|%%QT_ARCHDIR%%|${QT_ARCHDIR}|g' \
		${WRKSRC}/src/lprofqt/config.cpp

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/icons/lprof.png ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
