# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apiextractor
PORTVERSION=	0.10.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.pyside.org/files/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	API Extractor library to build PySide

LICENSE=	GPLv2

BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		xslt.2:${PORTSDIR}/textproc/libxslt

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_QT4=	gui moc_build qmake_build qtestlib_build \
		rcc_build uic_build xml xmlpatterns

USE_BZIP2=	yes
USES=		cmake
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
