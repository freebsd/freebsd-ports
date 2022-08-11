PORTNAME=	fcitx5-hangul
DISTVERSION=	5.0.2
CATEGORIES=	korean textproc

MAINTAINER=	khng300@gmail.com
COMMENT=	Hangul support for Fcitx5

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

LIB_DEPENDS=	libhangul.so:korean/libhangul \
		libFcitx5Core.so:textproc/fcitx5

USES=		compiler:c++17-lang gettext-tools cmake kde:5 pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	fcitx

USE_KDE=	ecm

.include <bsd.port.mk>
