# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ark
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	archivers kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Archiving tool for KDE

LIB_DEPENDS=	libqjson.so:${PORTSDIR}/devel/qjson

USE_KDE4=	kdeprefix kdehier automoc4 kdelibs libkonq
USES=		cmake:outsource tar:xz
USE_QT4=	qtestlib qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	7ZIP RAR ZIP

7ZIP_DESC=	Support for 7-Zip archives
7ZIP_RUN_DEPENDS=	7z:${PORTSDIR}/archivers/p7zip

RAR_DESC=	Support for RAR archives
RAR_RUN_DEPENDS=	unrar:${PORTSDIR}/archivers/unrar \
			rar:${PORTSDIR}/archivers/rar

ZIP_DESC=	Support for ZIP archives
ZIP_RUN_DEPENDS=	unzip>0:${PORTSDIR}/archivers/unzip \
			zip:${PORTSDIR}/archivers/zip

.include <bsd.port.mk>
