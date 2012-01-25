# New ports collection makefile for:	shiboken
# Date created:		2011-03-21
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	shiboken
PORTVERSION=	1.1.0
#PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.pyside.org/files/

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	C++ code generator for CPython extensions

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi

BUILD_DEPENDS=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
LIB_DEPENDS=	apiextractor.0:${PORTSDIR}/devel/apiextractor \
		genrunner.0:${PORTSDIR}/devel/generatorrunner

PLIST_SUB=	PORTVERSION=${PORTVERSION} \
		PYTHON_VERSION=${PYTHON_VERSION}

QT_COMPONENTS=	corelib qmake_build moc_build uic_build rcc_build

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_QT_VER=	4

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	shiboken.1
.else
CMAKE_ARGS=	-DNO_INSTALL_MANPAGES:BOOL="ON"
.endif

.include <bsd.port.mk>
