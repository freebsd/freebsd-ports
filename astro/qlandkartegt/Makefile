# Created by: Mykola Dzham <freebsd@levsha.org.ua>
# $FreeBSD$

PORTNAME=	qlandkartegt
PORTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/QLandkarteGT%20${PORTVERSION}

MAINTAINER=	i@levsha.me
COMMENT=	The ultimate outdoor aficionado's tool

LICENSE=	GPLv2

LIB_DEPENDS=	gdal:${PORTSDIR}/graphics/gdal \
		proj:${PORTSDIR}/graphics/proj \
		gps:${PORTSDIR}/astro/gpsd

USES=		cmake
USE_QT4=	dbus gui opengl network sql xml linguist_build \
		moc_build uic_build rcc_build qmake_build
USE_GL=		glu

SUB_FILES=	qlandkartegt

MAN1=		qlandkartegt.1

post-install:
	${MV} ${PREFIX}/bin/qlandkartegt ${PREFIX}/bin/qlandkartegt.bin
	${INSTALL_SCRIPT} ${WRKDIR}/qlandkartegt ${PREFIX}/bin

.include <bsd.port.mk>
