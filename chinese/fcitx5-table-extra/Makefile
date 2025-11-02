PORTNAME=	fcitx5-table-extra
DISTVERSION=	5.1.9
CATEGORIES=	chinese textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Extra table support for Fcitx5
WWW=		https://github.com/fcitx/fcitx5-table-extra

LICENSE=	GPLv2+ GPLv3
LICENSE_COMB=	multi

LIB_DEPENDS=	libFcitx5Core.so:textproc/fcitx5 \
		libIMETable.so:chinese/libime

USES=		cmake gettext-tools kde:5 tar:zst

USE_KDE=	ecm

INSTALL_TARGET=	install

CONFLICTS_INSTALL=	zh-fcitx-table-extra # share/icons/hicolor/48x48/apps/fcitx-cantonese.png

.include <bsd.port.mk>
