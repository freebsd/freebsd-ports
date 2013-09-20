# Created by: Arjan van Leeuwen <avleeuwen@piwebs.com>
# $FreeBSD$

PORTNAME=	digikam
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 digital photo management application

NO_STAGE=	yes
.include "${.CURDIR}/Makefile.common"

BUILD_DEPENDS=	${LOCALBASE}/include/eigen3/Eigen/Eigen:${PORTSDIR}/math/eigen3
LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		lcms:${PORTSDIR}/graphics/lcms \
		png15:${PORTSDIR}/graphics/png \
		jasper:${PORTSDIR}/graphics/jasper \
		lensfun:${PORTSDIR}/graphics/lensfun \
		lqr-1:${PORTSDIR}/graphics/liblqr-1 \
		kface:${PORTSDIR}/graphics/libkface \
		pgf:${PORTSDIR}/graphics/libpgf \
		kgeomap:${PORTSDIR}/astro/libkgeomap \
		boost_graph:${PORTSDIR}/devel/boost-libs

LATEST_LINK=	${PORTNAME}-kde4

OPTIONS_DEFINE=		DOCS NLS GPHOTO2 PIMLIBS MYSQL
OPTIONS_DEFAULT=	GPHOTO2 PIMLIBS
NO_OPTIONS_SORT=	yes

GPHOTO2_DESC=		Enable gphoto2 camera support
PIMLIBS_DESC=		Enable address book support

USES+=		pkgconfig
USE_KDE4+=	libkdcraw libkexiv2 libkipi
USE_QT4+=	sql-sqlite3_run
USE_LDCONFIG=	yes
CMAKE_ARGS+=	-DWITH_Sqlite2=off

MAN1=		digitaglinktree.1 \
		cleanup_digikamdb.1

WRKSRC=		${WRKDIR}/${DISTNAME}/core

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
RUN_DEPENDS+=	digikam-l10n>=${DIGIKAM_VER}:${PORTSDIR}/graphics/digikam-kde4-l10n
.endif

.if ${PORT_OPTIONS:MDOCS}
RUN_DEPENDS+=	digikam-doc>=${DIGIKAM_VER}:${PORTSDIR}/graphics/digikam-kde4-doc
.endif

.if ${PORT_OPTIONS:MGPHOTO2}
LIB_DEPENDS+=	gphoto2:${PORTSDIR}/graphics/libgphoto2
.else
CMAKE_ARGS+=	-DWITH_Gphoto2:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MPIMLIBS}
USE_KDE4+=	pimlibs
.else
CMAKE_ARGS+=	-DWITH_KdepimLibs:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MMYSQL}
USE_MYSQL=	server
USE_QT4+=	sql-mysql_run
CMAKE_ARGS+=	-DMYSQLD_PATH:PATH=${LOCALBASE}/libexec \
		-DMYSQL_TOOLS_PATH:PATH=${LOCALBASE}/bin
PLIST_SUB+=	MYSQL=""
.else
CMAKE_ARGS+=	-DENABLE_INTERNALMYSQL:BOOL=OFF
PLIST_SUB+=	MYSQL="@comment "
.endif

.include <bsd.port.mk>
