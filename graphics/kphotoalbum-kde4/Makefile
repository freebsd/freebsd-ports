# Created by: Markus Brueffer <brueffer@phoenix-systems.de>
# $FreeBSD$

PORTNAME=	kphotoalbum
PORTVERSION=	4.4
PORTREVISION=	12
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
DIST_SUBDIR=	KDE
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and organizer for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libexiv2.so:graphics/exiv2

SHEBANG_FILES=	script/open-raw.pl script/kpa-backup.sh

USES=		cmake jpeg kde:4 pkgconfig qt:4 shebangfix tar:bzip2
USE_KDE=	kdelibs libkdcraw libkipi automoc4
USE_QT=		phonon sql \
		qmake_build moc_build rcc_build uic_build

OPTIONS_DEFINE=	MARBLE NLS
OPTIONS_DEFAULT=	MARBLE
OPTIONS_SUB=	yes # NLS

MARBLE_DESC=	Geolocation support
MARBLE_USE=	KDE=marble
MARBLE_CMAKE_OFF=	-DWITH_Marble:BOOL=Off

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DBUILD_po:BOOL=Off

CONFLICTS_INSTALL=	${PORTNAME}-5.*

.include <bsd.port.mk>
