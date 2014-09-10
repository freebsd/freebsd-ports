# Created by: Arjan van Leeuwen <avleeuwen@piwebs.com>
# $FreeBSD$

PORTNAME=	digikam
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 digital photo management application

.include "${.CURDIR}/Makefile.common"

BUILD_DEPENDS=	${LOCALBASE}/include/eigen3/Eigen/Eigen:${PORTSDIR}/math/eigen3
LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff \
		liblcms.so:${PORTSDIR}/graphics/lcms \
		libpng15.so:${PORTSDIR}/graphics/png \
		libjasper.so:${PORTSDIR}/graphics/jasper \
		liblensfun.so:${PORTSDIR}/graphics/lensfun \
		liblqr-1.so:${PORTSDIR}/graphics/liblqr-1 \
		libkface.so:${PORTSDIR}/graphics/libkface \
		libpgf.so:${PORTSDIR}/graphics/libpgf \
		libkgeomap.so:${PORTSDIR}/astro/libkgeomap \
		libboost_graph.so:${PORTSDIR}/devel/boost-libs

USES+=		pkgconfig shebangfix
USE_KDE4+=	libkdcraw libkexiv2 libkipi
USE_QT4+=	sql-sqlite3_run
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DWITH_Sqlite2=off

WRKSRC=		${WRKDIR}/${DISTNAME}/core
SHEBANG_FILES=	utilities/scripts/digitaglinktree/digitaglinktree

OPTIONS_DEFINE=		DOCS NLS GPHOTO2 PIMLIBS MYSQL
OPTIONS_DEFAULT=	GPHOTO2 PIMLIBS
NO_OPTIONS_SORT=	yes
OPTIONS_SUB=		yes # MYSQL

DOCS_RUN_DEPENDS=	digikam-doc>=${DIGIKAM_VER}:${PORTSDIR}/graphics/digikam-kde4-doc

NLS_RUN_DEPENDS=	digikam-l10n>=${DIGIKAM_VER}:${PORTSDIR}/graphics/digikam-kde4-l10n

GPHOTO2_DESC=		Enable gphoto2 camera support
GPHOTO2_LIB_DEPENDS=	libgphoto2.so:${PORTSDIR}/graphics/libgphoto2
GPHOTO2_CMAKE_OFF=	-DWITH_Gphoto2:BOOL=OFF

PIMLIBS_DESC=		Enable address book support
PIMLIBS_USE=		KDE4=pimlibs
PIMLIBS_CMAKE_OFF=	-DWITH_KdepimLibs:BOOL=OFF

MYSQL_USE=		MYSQL=server QT4=sql-mysql_run
MYSQL_BUILD_DEPENDS=	${LOCALBASE}/lib/mysql/libmysqld.a:${PORTSDIR}/${_MYSQL_SERVER}
MYSQL_CMAKE_ON= 	-DMYSQLD_PATH:PATH=${LOCALBASE}/libexec \
			-DMYSQL_TOOLS_PATH:PATH=${LOCALBASE}/bin
MYSQL_CMAKE_OFF=	-DENABLE_INTERNALMYSQL:BOOL=OFF

.include <bsd.port.mk>
