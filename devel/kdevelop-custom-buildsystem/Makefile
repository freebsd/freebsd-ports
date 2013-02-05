# $FreeBSD$

PORTNAME=	kdevelop-custom-buildsystem
PORTVERSION=	1.2.2
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDEVELOP_BRANCH}/${PORTNAME:S,-,/,}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDevelop custom build system plugin

LIB_DEPENDS=	kdevplatforminterfaces:${PORTSDIR}/devel/kdevplatform

USE_KDE4=	kdehier kdelibs kdeprefix automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	lib/kde4/kcm_kdevcustombuildsystem.so \
		lib/kde4/kdevcustombuildsystem.so \
		share/kde4/services/kcm_kdevcustombuildsystem.desktop \
		share/kde4/services/kdevcustombuildsystem.desktop

.include <bsd.port.mk>
