PORTNAME=	fcitx5-chewing
DISTVERSION=	5.1.9
CATEGORIES=	chinese textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Chewing support for Fcitx5
WWW=		https://github.com/fcitx/fcitx5-chewing

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSES/LGPL-2.1-or-later.txt

LIB_DEPENDS=	libchewing.so:chinese/libchewing \
		libFcitx5Core.so:textproc/fcitx5

USES=		compiler:c++17-lang gettext-tools cmake kde:5 pkgconfig tar:zst

USE_KDE=	ecm

CONFLICTS_INSTALL=	zh-fcitx-chewing # share/icons/hicolor/48x48/apps/fcitx-chewing.png

.include <bsd.port.mk>
