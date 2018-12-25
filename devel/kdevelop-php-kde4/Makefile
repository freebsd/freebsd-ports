# $FreeBSD$

PORTNAME=	kdevelop-php
PORTVERSION=	${KDEVELOP_VERSION:S/4./1./}
PORTREVISION=	7
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDEVELOP_BRANCH}/kdevelop/${KDEVELOP_VERSION}
DIST_SUBDIR=	KDE/kdevelop/${KDEVELOP_VERSION}
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PHP support for KDevelop

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libkdevplatforminterfaces.so:devel/kdevplatform-kde4
BUILD_DEPENDS=	${KDE_PREFIX}/bin/kdev-pg-qt:devel/kdevelop-pg-qt-kde4

USES=		cmake compiler:c++11-lib kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		moc_build qmake_build rcc_build uic_build
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	PHPDOCS NLS
OPTIONS_DEFAULT=	PHPDOCS
OPTIONS_SUB=	yes

PHPDOCS_DESC=	Integrate with PHP.net documentation
PHPDOCS_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/kdevphpdocs.so:devel/kdevelop-php-docs-kde4

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DBUILD_po:BOOL=Off

.include <bsd.port.mk>
