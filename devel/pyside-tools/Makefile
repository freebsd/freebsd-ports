# New ports collection makefile for:	pyside-tools
# Date created:		2011-12-17
# Whom:			Nicola Vitale <nivit@mnemosine.domo.sva>
#
# $FreeBSD$
#

PORTNAME=	pyside-tools
PORTVERSION=	0.2.13
#PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.pyside.org/files/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Utilities for creating PySide applications

LICENSE=	BSD GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	pyside${PYTHON_PKGNAMESUFFIX}>=1.0.9:${PORTSDIR}/devel/pyside
LIB_DEPENDS=	shiboken-${PYTHON_VERSION}.1:${PORTSDIR}/devel/shiboken
RUN_DEPENDS=	pyside${PYTHON_PKGNAMESUFFIX}>=1.0.9:${PORTSDIR}/devel/pyside

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	pyside-lupdate.1 \
	pyside-rcc.1 \
	pyside-uic.1
.else
CMAKE_ARGS=	-DNO_INSTALL_MANPAGES:BOOL=ON
.endif

QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build

REINPLACE_ARGS=	-i.bak -e 's+/usr/bin/env python+&${PYTHON_VER}+' \
		${WRKSRC}/pyside-uic ${WRKSRC}/pysideuic/icon_cache.py

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_PYTHON=	2.5-2.7
USE_QT_VER=	4

post-patch:
	${REINPLACE_CMD}

.include <bsd.port.mk>
