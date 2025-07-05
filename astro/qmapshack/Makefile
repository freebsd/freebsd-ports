PORTNAME=	qmapshack
DISTVERSIONPREFIX=	V_
DISTVERSION=	1.18.0
CATEGORIES=	astro

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Ultimate outdoor aficionado's tool
WWW=		https://github.com/Maproom/qmapshack/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	vulkan-headers>0:graphics/vulkan-headers
LIB_DEPENDS=	libalglib.so:math/alglib \
		libgdal.so:graphics/gdal \
		libproj.so:graphics/proj \
		libquazip1-qt6.so:archivers/quazip@qt6 \
		libroutino.so:astro/routino
RUN_DEPENDS=	${LOCALBASE}/bin/bsdisks:sysutils/bsdisks

USES=		cmake desktop-file-utils gl jpeg qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	Maproom
USE_GL=	gl
USE_QT=		5compat base declarative positioning tools webchannel \
		webengine

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
