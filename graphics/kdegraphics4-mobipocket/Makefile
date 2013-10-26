# $FreeBSD$

PORTNAME=	kdegraphics-mobipocket
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mobipocket plugins for Strigi indexing, Okular and thumbnails

CONFLICTS=	kdegraphics-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix okular automoc4 strigi
USES=		cmake:outsource
USE_QT4=	corelib gui qmake_build moc_build uic_build rcc_build
USE_XZ=		yes

NO_STAGE=	yes
.include <bsd.port.mk>
