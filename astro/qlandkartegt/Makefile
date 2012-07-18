# New ports collection makefile for: qlandkartegt
# Date created:                1 Jun 2009
# Whom:                        Mykola Dzham <freebsd@levsha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	qlandkartegt
PORTVERSION=	1.5.0
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/QLandkarteGT%20${PORTVERSION}

MAINTAINER=	i@levsha.me
COMMENT=	The ultimate outdoor aficionado's tool

LICENSE=	GPLv2

LIB_DEPENDS=	gdal:${PORTSDIR}/graphics/gdal \
		proj.7:${PORTSDIR}/graphics/proj \
		gps.20:${PORTSDIR}/astro/gpsd

USE_CMAKE=	yes
USE_QT4=	dbus gui opengl network sql xml linguist_build \
		moc_build uic_build rcc_build qmake_build
USE_GL=		glu
MAKE_JOBS_SAFE=	yes

SUB_FILES=	qlandkartegt

MAN1=		qlandkartegt.1

post-install:
	${MV} ${PREFIX}/bin/qlandkartegt ${PREFIX}/bin/qlandkartegt.bin
	${INSTALL_SCRIPT} ${WRKDIR}/qlandkartegt ${PREFIX}/bin

.include <bsd.port.mk>
