# Created by: Mykola Dzham <freebsd@levsha.org.ua>
# $FreeBSD$

PORTNAME=	qlandkartegt
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/QLandkarteGT%20${PORTVERSION}

MAINTAINER=	i@levsha.me
COMMENT=	The ultimate outdoor aficionado's tool

LICENSE=	GPLv3

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BROKEN=		fails to build

LIB_DEPENDS=	libgdal.so:graphics/gdal \
		libproj.so:graphics/proj \
		libgps.so:astro/gpsd

USES=		cmake:insource desktop-file-utils qt:4
USE_QT=		dbus gui opengl network sql xml linguist_build \
		moc_build uic_build rcc_build qmake_build
USE_GL=		glu

.include <bsd.port.mk>
