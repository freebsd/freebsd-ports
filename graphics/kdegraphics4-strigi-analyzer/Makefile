# $FreeBSD$

PORTNAME=	kdegraphics-strigi-analyzer
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Strigi analyzers for various graphics file formats

LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff

USE_KDE4=	kdehier kdelibs kdeprefix automoc4 strigi
USES=		cmake:outsource
USE_QT4=	moc_build qmake_build rcc_build uic_build
USE_XZ=		yes

.include <bsd.port.mk>
