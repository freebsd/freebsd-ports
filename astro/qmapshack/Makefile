# Created by: Muhammad Moinur Rahman <bofh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qmapshack
PORTVERSION=	1.15.2
PORTREVISION=	1
DISTVERSIONPREFIX=	V_
CATEGORIES=	astro

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Ultimate outdoor aficionado's tool

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_11=	Requires OpenSSL 1.1.0+

LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libproj.so:graphics/proj \
		libquazip1-qt5.so:archivers/quazip \
		libroutino.so:astro/routino
RUN_DEPENDS=	${LOCALBASE}/bin/bsdisks:sysutils/bsdisks

USES=		cmake compiler:c++11-lib desktop-file-utils gl jpeg \
		pkgconfig qt:5 xorg
USE_GITHUB=	yes
USE_GL=		gl
USE_QT=		buildtools core dbus declarative gui help linguisttools location network \
		printsupport qmake sql sql-sqlite3 uitools \
		webchannel webengine widgets xml

GH_ACCOUNT=	Maproom

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
