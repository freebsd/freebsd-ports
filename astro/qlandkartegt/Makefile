# New ports collection makefile for: qlandkartegt
# Date created:                1 Jun 2009
# Whom:                        Mykola Dzham <freebsd@levsha.org.ua>
#
# $FreeBSD$
#

PORTNAME=	qlandkartegt
PORTVERSION=	1.1.0
CATEGORIES=	astro
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/QLandkarteGT%20${PORTVERSION}

MAINTAINER=	i@levsha.me
COMMENT=	The ultimate outdoor aficionado's tool

LIB_DEPENDS=	gdal:${PORTSDIR}/graphics/gdal \
		proj.6:${PORTSDIR}/graphics/proj

LICENSE=	GPLv2

USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui opengl network sql xml linguist_build \
		moc_build uic_build rcc_build qmake_build
MAKE_JOBS_SAFE=	yes

SUB_FILES=	qlandkartegt

MAN1=		qlandkartegt.1

post-patch:
	cd ${WRKSRC}/src/icons/cache/ &&\
	for f in *" "*; do ${MV} "$$f" $${f% *}-$${f#* } ; done

post-install:
	${MV} ${PREFIX}/bin/qlandkartegt ${PREFIX}/bin/qlandkartegt.bin
	${INSTALL_SCRIPT} ${WRKDIR}/qlandkartegt ${PREFIX}/bin

.include <bsd.port.mk>
