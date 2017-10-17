# $FreeBSD$

PORTNAME=	kgraphviewer
DISTVERSION=	2.4.2
CATEGORIES=	graphics kde
MASTER_SITES=   KDE/stable/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=    KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphs-viewer for GraphViz files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgvc.so:graphics/graphviz

USES=		cmake:outsource desktop-file-utils kde:5 tar:xz pkgconfig
USE_KDE=	auth codecs completion config configwidgets \
		coreaddons i18n iconthemes jobwidgets kio parts service \
		sonnet textwidgets widgetsaddons xmlgui \
		ecm_build
USE_QT5=	core dbus gui network printsupport svg widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
