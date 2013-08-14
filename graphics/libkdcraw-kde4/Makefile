# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libkdcraw
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	LibRaw interface for KDE

LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms

LATEST_LINK=	${PORTNAME}-kde4

CONFLICTS=	kdegraphics-4.[0-6].*

USE_GCC=	any
CMAKE_ARGS+=    -DWITH_OpenMP:BOOL=False

USE_XZ=		yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs
USES=		cmake:outsource
USE_QT4=	corelib gui moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

pre-configure:
	${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_INSTALL_DIR}/libdata/' \
		-e 's/${PORTNAME}.pc\([^.]\)/${PORTNAME}-kde4.pc\1/g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
