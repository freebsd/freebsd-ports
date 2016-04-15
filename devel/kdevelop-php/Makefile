# $FreeBSD$

PORTNAME=	kdevelop-php
PORTVERSION=	${KDEVELOP_VERSION:S/4./1./}
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDEVELOP_BRANCH}/kdevelop/${KDEVELOP_VERSION}/src
DIST_SUBDIR=	KDE/kdevelop/${KDEVELOP_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PHP support for KDevelop

LIB_DEPENDS=	libkdevplatforminterfaces.so:devel/kdevplatform
BUILD_DEPENDS=	${KDE4_PREFIX}/bin/kdev-pg-qt:devel/kdevelop-pg-qt

USE_KDE4=	kdelibs kdeprefix automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
USES=		cmake:outsource compiler:c++11-lib gmake tar:bz2
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	PHPDOCS NLS
OPTIONS_DEFAULT=	PHPDOCS
OPTIONS_SUB=	yes

PHPDOCS_DESC=	Integrate with PHP.net documentation
PHPDOCS_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/kdevphpdocs.so:devel/kdevelop-php-docs

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DBUILD_po:BOOL=Off

.include <bsd.port.mk>
