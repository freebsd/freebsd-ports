# New ports collection makefile for:	generatorrunner
# Date created:		2011-03-21
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	generatorrunner
PORTVERSION=	0.6.15
#PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.pyside.org/files/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tool to create binding generators for C++ and Qt libraries

LICENSE=	GPLv2

BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
LIB_DEPENDS=	apiextractor.0:${PORTSDIR}/devel/apiextractor

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	docgenerator.1 generatorrunner.1
.else
CMAKE_ARGS=	-DNO_INSTALL_MANPAGES:BOOL=ON
.endif

PLIST_SUB=	PORTVERSION=${PORTVERSION}

QT_COMPONENTS=	gui qmake_build qtestlib moc_build rcc_build uic_build xml

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_QT_VER=	4

.include <bsd.port.mk>
