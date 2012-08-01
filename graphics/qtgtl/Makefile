# New ports collection makefile for:	qtgtl
# Date created:				28 September 2009
# Whom:					Alberto Villa <villa.alberto@gmail.com>
#
# $FreeBSD$

PORTNAME=	qtgtl
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	graphics devel
MASTER_SITES=	http://download.opengtl.org/
DISTNAME=	libQtGTL-${PORTVERSION}

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Qt bindings for the Graphics Transformation Languages

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	GTLCore.0:${PORTSDIR}/graphics/opengtl

USE_PKGCONFIG=	build
USE_QT4=	gui moc_build qmake_build rcc_build uic_build
USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_LDCONFIG=	yes

pre-configure:
	${REINPLACE_CMD} -e 's|set(QTGTL_LIB_SOVERSION.*|set(QTGTL_LIB_SOVERSION "0")|' \
		${PATCH_WRKSRC}/CMakeLists.txt
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${PATCH_WRKSRC}/QtGTL/CMakeLists.txt \
		${PATCH_WRKSRC}/QtShiva/CMakeLists.txt

.include <bsd.port.mk>
