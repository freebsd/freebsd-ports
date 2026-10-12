PORTNAME=	fcitx5-table-other
DISTVERSION=	5.1.8
CATEGORIES=	chinese textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Other table support for Fcitx5
WWW=		https://github.com/fcitx/fcitx5-table-other

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libFcitx5Core.so:textproc/fcitx5 \
		${LOCALBASE}/lib/libIMETable.so:chinese/libime
RUN_DEPENDS=	fcitx5>0:textproc/fcitx5

USES=		cmake gettext-tools kde tar:zst

OPTIONS_DEFINE=	DEPRECATED

DEPRECATED_DESC=	Enable deprecated tables
DEPRECATED_CMAKE_BOOL=	ENABLE_DEPRECATED

USE_KDE=	ecm:build

INSTALL_TARGET=	install

CONFLICTS_INSTALL=	fcitx-table-other # share/icons/hicolor/32x32/apps/fcitx-thai.png

.include <bsd.port.mk>
