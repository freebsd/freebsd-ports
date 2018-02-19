# Created by: Nicola Vitale <nivit@mnemosine.domo.sva>
# $FreeBSD$

PORTNAME=	pyside-tools
PORTVERSION=	0.2.15
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utilities for creating PySide applications

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	pyside${PYTHON_PKGNAMESUFFIX}>=1.0.9:devel/pyside
LIB_DEPENDS=	libshiboken-${PYTHON_VERSION}.so:devel/shiboken
RUN_DEPENDS=	pyside${PYTHON_PKGNAMESUFFIX}>=1.0.9:devel/pyside

USE_GITHUB=	yes
GH_ACCOUNT=	PySide
GH_PROJECT=	Tools

USES=		cmake python:2.7 shebangfix
SHEBANG_FILES=	pyside-uic pysideuic/icon_cache.py
USE_QT4=	moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
