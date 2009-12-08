# New ports collection makefile for:	qtgtl
# Date created:				28 September 2009
# Whom:					Alberto Villa <villa.alberto@gmail.com>
# $FreeBSD$

PORTNAME=	qtgtl
PORTVERSION=	0.9.0
CATEGORIES=	graphics devel
MASTER_SITES=	http://www.opengtl.org/download/
DISTNAME=	libQtGTL-${PORTVERSION}

MAINTAINER=	villa.alberto@gmail.com
COMMENT=	Qt bindings for the Graphics Transformation Languages

LIB_DEPENDS=	GTLCore.0:${PORTSDIR}/graphics/opengtl

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes

pre-configure:
	${REINPLACE_CMD} -e 's|set(QTGTL_LIB_SOVERSION.*|set(QTGTL_LIB_SOVERSION "0")|' \
		${PATCH_WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${PATCH_WRKSRC}/QtGTL/CMakeLists.txt \
		${PATCH_WRKSRC}/QtShiva/CMakeLists.txt

.include <bsd.port.mk>
