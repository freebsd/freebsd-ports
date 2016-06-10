# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qmapshack
PORTVERSION=	1.6.1
CATEGORIES=	astro
MASTER_SITES=	https://bitbucket.org/maproom/qmapshack/downloads/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Ultimate outdoor aficionado's tool

LICENSE=	GPLv3


LIB_DEPENDS=	libQt5DBus.so:devel/dbus-qt5 \
		libgdal.so:graphics/gdal \
		libproj.so:graphics/proj \
		libroutino.so:astro/routino

USES=		cmake compiler:c++11-lib desktop-file-utils
USE_QT5=	buildtools core gui linguisttools network printsupport \
		qmake script sql sql-sqlite3 webkit widgets xml

.include <bsd.port.mk>
