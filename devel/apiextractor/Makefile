# New ports collection makefile for:	apiextractor
# Date created:		2011-03-21
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	apiextractor
PORTVERSION=	0.10.10
#PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.pyside.org/files/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	API Extractor library to build PySide

LICENSE=	GPLv2

BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt

PLIST_SUB=	PORTVERSION=${PORTVERSION}

QT_COMPONENTS=	gui moc_build qmake_build qtestlib_build \
		rcc_build uic_build xml xmlpatterns

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_QT_VER=	4

.include <bsd.port.mk>
