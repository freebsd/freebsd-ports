# Created by: Ka Ho Ng <khng300@gmail.com>

PORTNAME=	fcitx5-chewing
DISTVERSION=	5.0.7
CATEGORIES=	chinese textproc

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Chewing support for Fcitx5

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

LIB_DEPENDS=	libchewing.so:chinese/libchewing \
		libFcitx5Core.so:textproc/fcitx5

USES=		compiler:c++17-lang gettext-tools cmake kde:5 pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx

USE_KDE=	ecm

CONFLICTS_INSTALL=	zh-fcitx-chewing # share/icons/hicolor/48x48/apps/fcitx-chewing.png

.include <bsd.port.mk>
