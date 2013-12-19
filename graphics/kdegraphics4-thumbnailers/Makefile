# $FreeBSD$

PORTNAME=	kdegraphics-thumbnailers
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Thumbnailers for various graphics file formats

CONFLICTS=	kdegraphics-4.[0-6].*

USE_KDE4=	kdehier kdelibs kdeprefix libkdcraw libkexiv2 automoc4
USES=		cmake:outsource pkgconfig
USE_QT4=	gui qmake_build moc_build uic_build rcc_build
USE_XZ=		yes

NO_STAGE=	yes
.include <bsd.port.mk>
