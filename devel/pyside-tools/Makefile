# Created by: Nicola Vitale <nivit@mnemosine.domo.sva>
# $FreeBSD$

PORTNAME=	pyside-tools
PORTVERSION=	0.2.13
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://www.pyside.org/files/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities for creating PySide applications

LICENSE=	BSD GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	pyside${PYTHON_PKGNAMESUFFIX}>=1.0.9:${PORTSDIR}/devel/pyside
LIB_DEPENDS=	libshiboken-${PYTHON_VERSION}.so:${PORTSDIR}/devel/shiboken
RUN_DEPENDS=	pyside${PYTHON_PKGNAMESUFFIX}>=1.0.9:${PORTSDIR}/devel/pyside

USE_QT4=	moc_build qmake_build rcc_build uic_build

REINPLACE_ARGS=	-i.bak -e 's+/usr/bin/env python+&${PYTHON_VER}+' \
		${WRKSRC}/pyside-uic ${WRKSRC}/pysideuic/icon_cache.py

USES=		cmake tar:bzip2
USE_PYTHON=	2

post-patch:
	${REINPLACE_CMD}

.include <bsd.port.mk>
