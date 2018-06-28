# $FreeBSD$

PORTNAME=	kdevelop-php-docs
PORTVERSION=	${KDEVELOP_VERSION:S/4./1./}
PORTREVISION=	5
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDEVELOP_BRANCH}/kdevelop/${KDEVELOP_VERSION}
DIST_SUBDIR=	KDE/kdevelop/${KDEVELOP_VERSION}
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PHP documentation for KDevelop

LIB_DEPENDS=	libkdevplatforminterfaces.so:devel/kdevplatform-kde4

USES=		cmake:outsource compiler:c++11-lib kde:4 qt:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_QT=		moc_build qmake_build rcc_build uic_build webkit

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DBUILD_po:BOOL=FALSE

.include <bsd.port.mk>
