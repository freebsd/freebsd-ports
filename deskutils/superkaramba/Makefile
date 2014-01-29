# $FreeBSD$

PORTNAME=	superkaramba
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Widget framework for KDE

CONFLICTS=	kdeutils-4.[0-7].*

USE_XZ=		yes
USE_PYTHON=	yes
USE_KDE4=	kdehier kdelibs kdeprefix automoc4 qimageblitz
USES=		cmake:outsource
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
