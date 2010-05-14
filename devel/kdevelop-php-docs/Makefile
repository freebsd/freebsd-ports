# New ports collection makefile for:	kdevelop-php-docs
# Date created:				4 April 2010
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kdevelop
PORTVERSION=	${KDEVELOP_VERSION:S/4./1./}
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDEVELOP_BRANCH}/kdevelop/${KDEVELOP_VERSION}/src
PKGNAMESUFFIX=	-php-docs
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PHP documentation for KDevelop

LIB_DEPENDS=	kdevplatforminterfaces.1:${PORTSDIR}/devel/kdevplatform

USE_BZIP2=	yes
USE_KDE4=	automoc4 kdehier kdelibs kdeprefix
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes
USE_CMAKE=	yes

PLIST_FILES=	lib/kde4/kdevphpdocs.so \
		lib/kde4/kdevphpdocs_config.so \
		share/config.kcfg/phpdocssettings.kcfg \
		share/kde4/services/kdevphpdocs.desktop \
		share/kde4/services/kdevphpdocs_config.desktop

.include <bsd.port.mk>
