# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qmapshack
PORTVERSION=	1.14.0
DISTVERSIONPREFIX=	V_
PORTREVISION=	1
CATEGORIES=	astro

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Ultimate outdoor aficionado's tool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libproj.so:graphics/proj \
		libquazip5.so:archivers/quazip \
		libroutino.so:astro/routino
RUN_DEPENDS=	${LOCALBASE}/bin/bsdisks:sysutils/bsdisks

USES=		cmake compiler:c++11-lib desktop-file-utils gl jpeg \
		pkgconfig qt:5 xorg
USE_QT=		buildtools core dbus declarative gui linguisttools location network \
		printsupport qmake sql sql-sqlite3 uitools \
		webchannel webengine widgets xml
USE_GL=		gl
USE_GITHUB=	yes
GH_ACCOUNT=	Maproom

.include <bsd.port.mk>
