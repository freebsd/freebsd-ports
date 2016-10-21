# $FreeBSD$

PORTNAME=	kde-dev-scripts
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	devel kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE development scripts

USES=		cmake:outsource kde:4 shebangfix tar:xz
USE_KDE=	kdelibs automoc4
USE_QT4=	moc_build qmake_build rcc_build uic_build

SHEBANG_FILES=	cxxmetric \
		draw_lib_dependencies \
		fixkdeincludes \
		fixuifiles \
		krazy-licensecheck \
		png2mng.pl \
		svnintegrate

.include <bsd.port.mk>
