# $FreeBSD$

PORTNAME=	libkgeomap
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	1
CATEGORIES=	astro kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 library for browsing photos on a map

.include "${.CURDIR}/../../graphics/digikam-kde4/Makefile.common"

BUILD_DEPENDS=	${LOCALBASE}/include/boost/graph/buffer_concepts.hpp:devel/boost-libs

# libkexiv2 is used only for demo application
USE_KDE4+=	marble
USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e '/pkgconfig/s|$${LIB_INSTALL_DIR}|libdata|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
