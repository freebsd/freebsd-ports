# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ark
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	4
CATEGORIES=	archivers kde kde-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Archiving tool for KDE

LIB_DEPENDS=	libqjson.so:devel/qjson

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake:outsource kde:4 libarchive cpe tar:xz
USE_KDE=	automoc4 kdelibs libkonq
CPE_VENDOR=	kde
USE_QT4=	qtestlib qmake_build moc_build rcc_build uic_build
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
