# $FreeBSD$

PORTNAME=	kdevelop-php
PORTVERSION=	${KDEVELOP_VERSION:S/4./1./}
PORTREVISION=	3
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDEVELOP_BRANCH}/kdevelop/${KDEVELOP_VERSION}/src
DIST_SUBDIR=	KDE/kdevelop/${KDEVELOP_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PHP support for KDevelop

LIB_DEPENDS=	libkdevplatforminterfaces.so:${PORTSDIR}/devel/kdevplatform
BUILD_DEPENDS=	${KDE4_PREFIX}/bin/kdev-pg-qt:${PORTSDIR}/devel/kdevelop-pg-qt

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
USES=		cmake gmake tar:xz
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	PHPDOCS NLS
OPTIONS_DEFAULT=	PHPDOCS
OPTIONS_SUB=	yes

PHPDOCS_DESC=	Integrate with PHP.net documentation
PHPDOCS_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/kdevphpdocs.so:${PORTSDIR}/devel/kdevelop-php-docs

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DBUILD_po:BOOL=Off

.include <bsd.port.mk>
