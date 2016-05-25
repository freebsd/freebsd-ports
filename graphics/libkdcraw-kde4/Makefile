# Created by: Dima Panov <fluffy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libkdcraw
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	3
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	LibRaw interface for KDE

LIB_DEPENDS=	libjasper.so:graphics/jasper \
		liblcms.so:graphics/lcms \
		libxml2.so:textproc/libxml2 \
		libraw.so:graphics/libraw

CMAKE_ARGS+=	-DWITH_OpenMP:BOOL=False \
		-DENABLE_RAWSPEED=True

USE_KDE4=	automoc4 kdelibs
USES=		cmake:outsource jpeg pkgconfig tar:xz
USE_QT4=	corelib gui moc_build qmake_build rcc_build uic_build
USE_LDCONFIG=	yes

pre-configure:
	${REINPLACE_CMD} -e '/pkgconfig/ s/$${LIB_INSTALL_DIR}/libdata/' \
		-e 's/${PORTNAME}.pc\([^.]\)/${PORTNAME}-kde4.pc\1/g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
