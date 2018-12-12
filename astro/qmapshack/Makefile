# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qmapshack
PORTVERSION=	1.12.0
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	https://bitbucket.org/maproom/qmapshack/downloads/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Ultimate outdoor aficionado's tool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libproj.so:graphics/proj \
		libquazip5.so:archivers/quazip@qt5 \
		libroutino.so:astro/routino
RUN_DEPENDS=	${LOCALBASE}/bin/bsdisks:sysutils/bsdisks

USES=		cmake compiler:c++11-lib desktop-file-utils jpeg qt:5
USE_QT=		buildtools core dbus declarative gui linguisttools location network \
		printsupport qmake sql sql-sqlite3 uitools \
		webchannel webengine widgets xml

.include <bsd.port.mk>
