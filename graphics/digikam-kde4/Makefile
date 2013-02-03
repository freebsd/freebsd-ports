# New ports collection makefile for:	digikam
# Date created: 			3 February 2003
# Whom:					Arjan van Leeuwen <avleeuwen@piwebs.com>
#
# $FreeBSD$
#

PORTNAME=	digikam
PORTVERSION=	${DIGIKAM_VER}
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	graphics kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 digital photo management application

.include "${.CURDIR}/Makefile.common"

LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		lcms:${PORTSDIR}/graphics/lcms \
		png15:${PORTSDIR}/graphics/png \
		jasper:${PORTSDIR}/graphics/jasper \
		lensfun:${PORTSDIR}/graphics/lensfun \
		lqr-1:${PORTSDIR}/graphics/liblqr-1 \
		kface:${PORTSDIR}/graphics/libkface \
		pgf:${PORTSDIR}/graphics/libpgf \
		kgeomap:${PORTSDIR}/astro/libkgeomap

LATEST_LINK=	${PORTNAME}-kde4

OPTIONS_DEFINE=		NLS GPHOTO2 PIMLIBS MYSQL
OPTIONS_DEFAULT=	GPHOTO2 PIMLIBS
NO_OPTIONS_SORT=	yes

GPHOTO2_DESC=		Enable gphoto2 camera support
PIMLIBS_DESC=		Enable address book support

USE_PKGCONFIG=	build
USE_KDE4+=	libkdcraw libkexiv2 libkipi
USE_QT4+=	sql-sqlite3_run

MAN1=		digitaglinktree.1 \
		cleanup_digikamdb.1

WRKSRC=		${WRKDIR}/${DISTNAME}/core

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DWITH_NLS:BOOL=OFF
PLIST_SUB+=	NLS="@comment "
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

post-patch:
	${LN} -s ../doc ${WRKSRC}/doc
	${LN} -s ../po ${WRKSRC}/po
	${RM} ${WRKSRC}/po/*/libkgeomap.po ${WRKSRC}/po/*/kipi*

.include <bsd.port.mk>
