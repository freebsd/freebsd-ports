PORTNAME=	fcitx5-table-other
DISTVERSION=	5.1.5
CATEGORIES=	chinese textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Other table support for Fcitx5
WWW=		https://github.com/fcitx/fcitx5-table-other

LICENSE=	GPLv3

LIB_DEPENDS=	libFcitx5Core.so:textproc/fcitx5 \
		libIMETable.so:chinese/libime

USES=		cmake gettext-tools kde:5 tar:zst

OPTIONS_DEFINE=	DEPRECATED

DEPRECATED_DESC=	Enable deprecated tables
DEPRECATED_CMAKE_BOOL=	ENABLE_DEPRECATED

USE_KDE=	ecm

INSTALL_TARGET=	install

CONFLICTS_INSTALL=	fcitx-table-other # share/icons/hicolor/32x32/apps/fcitx-thai.png

.include <bsd.port.mk>
