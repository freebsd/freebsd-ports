# $FreeBSD$

PORTNAME=	superkaramba
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Widget framework for KDE

USE_PYTHON=	2
USE_KDE4=	kdehier kdelibs kdeprefix automoc4 qimageblitz
USES=		cmake:outsource tar:xz
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
