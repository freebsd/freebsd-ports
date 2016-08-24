# $FreeBSD$

PORTNAME=	kdesdk-strigi-analyzers
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Strigi analyzers for SDK related file formats

USES=		cmake:outsource kde:4 tar:xz
USE_KDE=	kdelibs automoc4 strigi
USE_QT4=	moc_build qmake_build rcc_build uic_build

.include <bsd.port.mk>
