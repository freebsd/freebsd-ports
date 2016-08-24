# $FreeBSD$

PORTNAME=	umbrello
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	UML modeller for KDE

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs automoc4
USE_GNOME=	libxml2 libxslt
USE_QT4=	moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
