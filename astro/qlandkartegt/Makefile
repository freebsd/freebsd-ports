# Created by: Mykola Dzham <freebsd@levsha.org.ua>
# $FreeBSD$

PORTNAME=	qlandkartegt
PORTVERSION=	1.7.4
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/QLandkarteGT%20${PORTVERSION}

MAINTAINER=	i@levsha.me
COMMENT=	The ultimate outdoor aficionado's tool

LICENSE=	GPLv3

LIB_DEPENDS=	libgdal.so:${PORTSDIR}/graphics/gdal \
		libproj.so:${PORTSDIR}/graphics/proj \
		libgps.so:${PORTSDIR}/astro/gpsd

USES=		cmake
USE_QT4=	dbus gui opengl network sql xml linguist_build \
		moc_build uic_build rcc_build qmake_build
USE_GL=		glu

MAN1=		qlandkartegt.1

.include <bsd.port.mk>
