# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	generatorrunner
PORTVERSION=	0.6.16
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.pyside.org/files/

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

USE_QT4=	gui qmake_build qtestlib moc_build rcc_build uic_build xml

USE_BZIP2=	yes
USES=		cmake
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
