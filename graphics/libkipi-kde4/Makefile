# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libkipi
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Image Plugin Interface

LATEST_LINK=	${PORTNAME}-kde4

CONFLICTS=	kdegraphics-4.[0-6].*

USE_XZ=		yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs
USES=		cmake:outsource
USE_QT4=	gui moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

pre-configure:
	${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_INSTALL_DIR}/libdata/' \
		-e 's/${PORTNAME}.pc\([^.]\)/${PORTNAME}-kde4.pc\1/g' \
		${WRKSRC}/CMakeLists.txt
# remove BOM:
	${REINPLACE_CMD} -e '1 s|^.*/|/|g' \
		${WRKSRC}/tests/kipitestmainwindow.cpp

.include <bsd.port.mk>
