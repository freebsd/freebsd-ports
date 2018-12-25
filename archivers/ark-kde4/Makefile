# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ark
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	5
CATEGORIES=	archivers kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Archiving tool for KDE

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

LIB_DEPENDS=	libqjson.so:devel/qjson@qt4

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake kde:4 libarchive cpe qt:4 tar:xz
USE_KDE=	automoc4 kdelibs libkonq
CPE_VENDOR=	kde
USE_QT=		qtestlib qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	7ZIP RAR ZIP

7ZIP_DESC=	Support for 7-Zip archives
7ZIP_RUN_DEPENDS=	7z:archivers/p7zip

RAR_DESC=	Support for RAR archives
RAR_RUN_DEPENDS=	unrar:archivers/unrar \
			rar:archivers/rar

ZIP_DESC=	Support for ZIP archives
ZIP_RUN_DEPENDS=	unzip>0:archivers/unzip \
			zip:archivers/zip

.include <bsd.port.mk>
