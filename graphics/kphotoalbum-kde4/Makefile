# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	kphotoalbum
PORTVERSION=	4.4
PORTREVISION=	10
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and organizer for KDE

LIB_DEPENDS=	libexiv2.so:graphics/exiv2

SHEBANG_FILES=	script/open-raw.pl script/kpa-backup.sh

USES=		cmake:outsource jpeg kde:4 pkgconfig shebangfix tar:bzip2
USE_KDE=	kdelibs libkdcraw libkipi automoc4
USE_QT4=	phonon sql \
		qmake_build moc_build rcc_build uic_build

OPTIONS_DEFINE=	MARBLE NLS
OPTIONS_DEFAULT=	MARBLE
OPTIONS_SUB=	yes # NLS

MARBLE_DESC=	Geolocation support
MARBLE_USE=	KDE=marble
MARBLE_CMAKE_OFF=	-DWITH_Marble:BOOL=Off

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DBUILD_po:BOOL=Off

.include <bsd.port.mk>
