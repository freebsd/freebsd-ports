PORTNAME=	fcitx5-anthy
DISTVERSION=	5.1.5
CATEGORIES=	japanese textproc
MASTER_SITES=	https://download.fcitx-im.org/fcitx5/${PORTNAME}/

MAINTAINER=	khng@FreeBSD.org
COMMENT=	Anthy support for Fcitx5
WWW=		https://github.com/fcitx/fcitx5-anthy

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

LIB_DEPENDS=	libanthy.so:japanese/anthy \
		libFcitx5Core.so:textproc/fcitx5

USES=		cmake compiler:c++17-lang gettext-tools kde:5 pkgconfig tar:zst

USE_KDE=	ecm

.include <bsd.port.mk>
