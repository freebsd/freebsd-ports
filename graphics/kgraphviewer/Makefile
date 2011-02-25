# New ports collection makefile for:	kgraphviewer
# Date created:		2008-09-01
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kgraphviewer
PORTVERSION=	${APP_VER}.${EXTRA_VER}
PORTREVISION=	2
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${EXTRA_VER}/src/extragear
DISTNAME=	${PORTNAME}-${APP_VER}-kde${EXTRA_VER}
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	GraphViz dot graph viewer for KDE

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml
LIB_DEPENDS=	gvc.5:${PORTSDIR}/graphics/graphviz

USE_BZIP2=	yes
USE_KDE4=	kdelibs pimlibs kdeprefix kdehier automoc4
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

APP_VER=	2.0.2
EXTRA_VER=	4.4.0

post-patch:
#Fix build with kdelibs>=4.5.0
	${REINPLACE_CMD} -e 's,V4.1.2-Based,V4.2-Based,g' \
		${WRKSRC}/doc-translations/*_kgraphviewer/kgraphviewer/index.docbook \
		${WRKSRC}/doc/index.docbook

.include <bsd.port.mk>
