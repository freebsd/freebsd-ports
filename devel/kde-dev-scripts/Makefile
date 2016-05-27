# $FreeBSD$

PORTNAME=	kde-dev-scripts
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE development scripts

USES=		cmake:outsource shebangfix tar:xz
USE_KDE4=	kdelibs automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build

SHEBANG_FILES=	cxxmetric \
		draw_lib_dependencies \
		fixkdeincludes \
		fixuifiles \
		krazy-licensecheck \
		png2mng.pl \
		svnintegrate

.include <bsd.port.mk>
