# Created by: Nicola Vitale <nivit@mnemosine.domo.sva>
# $FreeBSD$

PORTNAME=	pyside-tools
PORTVERSION=	0.2.13
PORTREVISION=	1
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

USE_QT4=	moc_build qmake_build rcc_build uic_build

REINPLACE_ARGS=	-i.bak -e 's+/usr/bin/env python+&${PYTHON_VER}+' \
		${WRKSRC}/pyside-uic ${WRKSRC}/pysideuic/icon_cache.py

USE_BZIP2=	yes
USES=		cmake
USE_PYTHON=	2

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD}

.include <bsd.port.mk>
